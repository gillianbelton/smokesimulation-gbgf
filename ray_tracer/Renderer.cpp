#include "Renderer.h"

#include "Camera.h"
#include "Image.h"
#include "Ray.h"

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

    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            Vector3f color = Vector3f(0, 255, 255);
            image.setPixel(x, y, color);
        }
    }

    image.savePNG("SMOKE1.png");
}

