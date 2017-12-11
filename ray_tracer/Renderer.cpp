#include "Renderer.h"

#include "Camera.h"
#include "Image.h"
#include "Ray.h"

#include <limits>

using namespace std;

const int PIXELS_PER_VOXEL = 10;


Renderer::Renderer(vector<vector<vector<float>>> dg, int grid_dim) :
    _density_grid(dg),
    _grid_width(grid_dim),
    _pic_width(grid_dim * PIXELS_PER_VOXEL)
{
}


void Renderer::Render(string filename)
{
    Image image(_pic_width, _pic_width);

    std::cout << "about to go through pixels" << std::endl;

    for (int x = 0; x < _grid_width; ++x) {
        for (int y = 0; y < _grid_width; ++y) {
            Vector3f color = getDensity(x, y);
            for (int i = 0; i < PIXELS_PER_VOXEL; ++i) { 
                for (int j = 0; j < PIXELS_PER_VOXEL; ++j) {
                    image.setPixel(x*PIXELS_PER_VOXEL + i, y*PIXELS_PER_VOXEL + j, color); 
                }
            }           
        }
    }

    std::cout << "about to save file" << std::endl;
    image.savePNG(filename);
    std::cout << "done saving file" << std::endl;
}

Vector3f Renderer::getDensity(int x, int y) {
    float total = 0;
    for (int z = 0; z < _grid_width; ++z) {
        total += _density_grid[x][y][z];
    }
    total /= _grid_width;
    return Vector3f(total, total, total);
}


