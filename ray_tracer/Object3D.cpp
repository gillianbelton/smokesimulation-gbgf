#include "Object3D.h"
#include <limits>


bool Sphere::intersect(const Ray &r, float tmin, Hit &h) const
{
    // BEGIN STARTER
    //printf("in SPHERE intersect\n");

    // We provide sphere intersection code for you.
    // You should model other intersection implementations after this one.

    // Locate intersection point ( 2 pts )
    const Vector3f &rayOrigin = r.getOrigin(); //Ray origin in the world coordinate
    const Vector3f &dir = r.getDirection();

    Vector3f origin = rayOrigin - _center;   //Ray origin in the sphere coordinate

    float a = dir.absSquared();
    float b = 2 * Vector3f::dot(dir, origin);
    float c = origin.absSquared() - _radius * _radius;

    // no intersection
    if (b * b - 4 * a * c < 0) {
        return false;
    }

    float d = sqrt(b * b - 4 * a * c);

    float tplus = (-b + d) / (2.0f*a);
    float tminus = (-b - d) / (2.0f*a);

    // the two intersections are at the camera back
    if ((tplus < tmin) && (tminus < tmin)) {
        return false;
    }

    float t = 10000;
    // the two intersections are at the camera front
    if (tminus > tmin) {
        t = tminus;
    }

    // one intersection at the front. one at the back 
    if ((tplus > tmin) && (tminus < tmin)) {
        t = tplus;
    }

    if (t < h.getT()) {
        Vector3f normal = r.pointAtParameter(t) - _center;
        normal = normal.normalized();
        h.set(t, this->material, normal);
        
        return true;
    }
    // END STARTER
    return false;
}

// Add object to group
void Group::addObject(Object3D *obj) {
    m_members.push_back(obj);
}

// Return number of objects in group
int Group::getGroupSize() const {
    return (int)m_members.size();
}

bool Group::intersect(const Ray &r, float tmin, Hit &h) const
{
    // BEGIN STARTER
    // we implemented this for you
    bool hit = false;
    for (Object3D* o : m_members) {
        if (o->intersect(r, tmin, h)) {
            hit = true;
        }
    }
    
    return hit;
    // END STARTER
}


bool Plane::intersect(const Ray &r, float tmin, Hit &h) const
{
    const Vector3f &rayOrigin = r.getOrigin(); //Ray origin in the world coordinate
    const Vector3f &dir = r.getDirection();
    float t = std::numeric_limits<float>::max();

    // assuming vectors are all normalized
    float denom = -Vector3f::dot(_normal, dir); 
    if (denom > 1e-4) { 
        Vector3f d = _p_0 - rayOrigin; 
        t = -Vector3f::dot(d, _normal) / denom; 
    } 

    if (t > tmin && t < h.getT()) {
        h.set(t, this->material, _normal.normalized());
        return true;
    }
    // END STARTER
    return false;
}

bool Triangle::intersect(const Ray &r, float tmin, Hit &h) const 
{
    Vector3f b = Vector3f(getVertex(0).x() - r.getOrigin().x(),
                          getVertex(0).y() - r.getOrigin().y(),
                          getVertex(0).z() - r.getOrigin().z());    
    Vector3f col1 = Vector3f(getVertex(0).x() - getVertex(1).x(),
                             getVertex(0).y() - getVertex(1).y(),
                             getVertex(0).z() - getVertex(1).z());
    Vector3f col2 = Vector3f(getVertex(0).x() - getVertex(2).x(),
                             getVertex(0).y() - getVertex(2).y(),
                             getVertex(0).z() - getVertex(2).z());
    Vector3f col3 = Vector3f(r.getDirection().x(), r.getDirection().y(), r.getDirection().z());
    Matrix3f A = Matrix3f(col1, col2, col3, true);
    Vector3f solution = A.inverse() * b;
    float beta = solution.x();
    float gamma = solution.y();
    float t = solution.z();
    
    if (t > tmin && beta + gamma <= 1 && beta >= 0 && gamma >= 0 && t < h.getT()) {
        Vector3f normal = getNormal(0) + beta * (getNormal(1)-getNormal(0)) + gamma * (getNormal(2)-getNormal(0));
        normal = normal.normalized();
        h.set(t, this->material, normal);
        return true;
    } 
    //printf("returning false\n");
    return false;     
}

Transform::Transform(Matrix4f &m, Object3D *obj) : _object(obj) {   
    _tObject2World = m;
}


bool Transform::intersect(const Ray &r, float tmin, Hit &h) const
{
    Vector4f direction = Vector4f(r.getDirection(), 0);
    Vector3f direction3 = (_tObject2World.inverse() * direction).xyz();
    Vector4f origin = Vector4f(r.getOrigin(), 1);
    Vector3f origin3 = (_tObject2World.inverse() * origin).xyz();

    Ray * objRay = new Ray(origin3, direction3);
    if (_object->intersect(*objRay, tmin, h)) {
        Vector4f newNormal =  _tObject2World.inverse().transposed() * Vector4f(h.getNormal(), 0);
        h.set(h.getT(), h.getMaterial(), newNormal.xyz().normalized());
        return true;
    }
    return false;
}
