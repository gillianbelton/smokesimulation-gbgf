#include "Material.h"
#include <math.h>
Vector3f Material::shade(const Ray &ray,
    					const Hit &hit,
    					const Vector3f &dirToLight,
    					const Vector3f &lightIntensity)
{
    // TODO implement Diffuse and Specular phong terms
    double clampD = fmax(0, Vector3f::dot(dirToLight, hit.getNormal()));
    Vector3f diffuseColor =  lightIntensity * _diffuseColor * clampD;

    Vector3f V = (ray.pointAtParameter(hit.getT()) - ray.getOrigin()).normalized();
    Vector3f N = hit.getNormal().normalized();
    Vector3f R = (V - 2 * (Vector3f::dot(V, N) * N)).normalized();
    double clampS = pow(fmax(0, Vector3f::dot(dirToLight.normalized(), R)), _shininess);
    Vector3f specularColor = lightIntensity * _specularColor * clampS;
    return specularColor + diffuseColor;
}
