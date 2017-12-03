#include "Renderer.h"

#include "Camera.h"
#include "Image.h"
#include "Ray.h"

#include <limits>

using namespace std;


Renderer::Renderer(vector<vector<vector<float>>> dg, int grid_dim) :
    _density_grid(dg),
    _grid_width(grid_dim),
    _pic_width(grid_dim * 100)
{
}


void Renderer::Render()
{
    Image image(_pic_width, _pic_width);

    for (int y = 0; y < _grid_width; ++y) {
        for (int x = 0; x < _grid_width; ++x) {
            Vector3f color = getDensity(x, y);
            for (int i = 0; i < 100; ++i) {                
                image.setPixel(x*100 + i, y*100 + i, color); 
            }           
        }
    }

    image.savePNG("SMOKE.png");
}

Vector3f Renderer::getDensity(int x, int y) {
    printf("x,y = %i, %i\n", x, y);
    float total = 0;
    for (int z = 0; z < _grid_width; ++z) {
        if (x == 3)
            printf("z = %i\n", z);
        total += _density_grid[x][y][z];

    }
    printf("made it out!\n");
    total /= _grid_width;

    return Vector3f(total, total, total);
}

