#include "Renderer.h"

#include "ArgParser.h"
#include "Camera.h"
#include "Image.h"
#include "Ray.h"
#include "VecUtils.h"

#include <limits>

using namespace std;


Renderer::Renderer(vector<vector<vector<float>>> dg, float grid_dim) :
    _density_grid(dg),
    _grid_width(grid_dim)
{

}


void
Renderer::Render()
{
    int w = _grid_width * 100;
    int h = _grid_width * 100;

    Image image(w, h);
    // Image nimage(_grid_width, _grid_width);
    // Image dimage(_grid_width, _grid_width);

    // loop through all the pixels in the image
    // generate all the samples

    // This look generates camera rays and callse traceRay.
    // It also write to the color, normal, and depth images.
    // You should understand what this code does.
    // Camera* cam = _scene.getCamera();


    for (int y = 0; y < h; ++y) {
        float ndcy = 2 * (y / (h - 1.0f)) - 1.0f;
        for (int x = 0; x < w; ++x) {
            // float ndcx = 2 * (x / (w - 1.0f)) - 1.0f;
            // Use PerspectiveCamera to generate a ray.
            // You should understand what generateRay() does.
            // Ray r = cam->generateRay(Vector2f(ndcx, ndcy));

            // Hit h;
            Vector3f color = Vector3f(0,255,255);

            image.setPixel(x, y, color);
            // nimage.setPixel(x, y, (h.getNormal() + Vector3f(1, 1, 1.0f)) / 2.0f);
            // float range = (_args.depth_max - _args.depth_min);
            // if (range) {
            //     dimage.setPixel(x, y, Vector3f((h.t - _args.depth_min) / range));
            // }
        }
    }
    // END SOLN

    // save the files 

        image.savePNG("SMOKE.png");
    
    // if (_args.depth_file.size()) {
    //     dimage.savePNG(_args.depth_file);
    // }
    // if (_args.normals_file.size()) {
    //     nimage.savePNG(_args.normals_file);
    // }
}

