#include "Renderer.h"

#include "ArgParser.h"
#include "Camera.h"
#include "Image.h"
#include "Ray.h"
#include "VecUtils.h"

#include <limits>


Renderer::Renderer(const ArgParser &args) :
    _args(args),
    _scene(args.input_file)
{
}

void
Renderer::Render()
{
    int w = _args.width;
    int h = _args.height;

    Image image(w, h);
    Image nimage(w, h);
    Image dimage(w, h);

    // loop through all the pixels in the image
    // generate all the samples

    // This look generates camera rays and callse traceRay.
    // It also write to the color, normal, and depth images.
    // You should understand what this code does.
    Camera* cam = _scene.getCamera();
    for (int y = 0; y < h; ++y) {
        float ndcy = 2 * (y / (h - 1.0f)) - 1.0f;
        for (int x = 0; x < w; ++x) {
            float ndcx = 2 * (x / (w - 1.0f)) - 1.0f;
            // Use PerspectiveCamera to generate a ray.
            // You should understand what generateRay() does.
            Ray r = cam->generateRay(Vector2f(ndcx, ndcy));

            Hit h;
            Vector3f color = traceRay(r, cam->getTMin(), _args.bounces, h);

            image.setPixel(x, y, color);
            nimage.setPixel(x, y, (h.getNormal() + 1.0f) / 2.0f);
            float range = (_args.depth_max - _args.depth_min);
            if (range) {
                dimage.setPixel(x, y, Vector3f((h.t - _args.depth_min) / range));
            }
        }
    }
    // END SOLN

    // save the files 
    if (_args.output_file.size()) {
        image.savePNG(_args.output_file);
    }
    if (_args.depth_file.size()) {
        dimage.savePNG(_args.depth_file);
    }
    if (_args.normals_file.size()) {
        nimage.savePNG(_args.normals_file);
    }
}



Vector3f Renderer::traceRay(const Ray &r, float tmin, int bounces, Hit &h) const {
    // The starter code only implements basic drawing of sphere primitives.
    // You will implement phong shading, recursive ray tracing, and shadow rays.
    Vector3f toLight, intensity;
    Vector3f color = Vector3f(0,0,0);
    float distToLight = 0;
    if (_scene.getGroup()->intersect(r, tmin, h)) {
        //printf("test\n");
        for (int i = 0; i < _scene.getNumLights(); ++i) { 
            PointLight * pl = (PointLight *) _scene.getLight(i);
            pl->getIllumination(r.pointAtParameter(h.getT()), 
                                toLight, //direction from p to light source
                                intensity, //is the illumination intensity (RGB) at point p
                                distToLight); //is absolute distance from P to light
            if (_args.shadows) {
                //shadows activated!
                Hit * shadowHit = new Hit();
                Ray shadowRay = Ray(r.pointAtParameter(h.getT()), toLight);
                traceRay(shadowRay, tmin, 0, * shadowHit);
                float epsilon = 0.01;
                if ((shadowRay.pointAtParameter(shadowHit->getT()) - shadowRay.getOrigin()).abs() - epsilon >= distToLight) {
                    //if the shadow ray did NOT hit something before the light 
                    color += h.getMaterial()->shade(r, h, toLight, intensity);                    
                }
            } else {
                //if shadows not activated 
                color += h.getMaterial()->shade(r, h, toLight, intensity);
            }        
        }
        Vector3f bounceDirection = r.getDirection() - 2 * (Vector3f::dot(r.getDirection(), h.getNormal()) * h.getNormal());
        Ray bounceRay = Ray(r.pointAtParameter(h.getT()), bounceDirection);
        Hit * hit = new Hit();
        if (bounces > 0) {
            return color + _scene.getAmbientLight() * h.getMaterial()->getDiffuseColor()
                         + h.getMaterial()->getSpecularColor() * traceRay(bounceRay, tmin, bounces - 1, * hit);
        } else {
            return color + _scene.getAmbientLight() * h.getMaterial()->getDiffuseColor();
        }
    } else {
        //printf("not\n");
        Vector3f dir = r.getDirection();
        return _scene.getBackgroundColor(dir);
    }
}

