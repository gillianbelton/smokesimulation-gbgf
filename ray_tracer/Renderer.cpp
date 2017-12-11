#include "Renderer.h"

#include "Camera.h"
#include "Image.h"
#include "Ray.h"

#include <limits>
#include <math.h>

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

    for (int x = 0; x < _pic_width; ++x) {
        for (int y = 0; y < _pic_width; ++y) {

        }
    }

    for (int x = 0; x < _grid_width; ++x) {
        for (int y = 0; y < _grid_width; ++y) {
            //Vector3f color = getDensity(x, y);
            vector<float> v = interpolate(x, y);
            for (int i = 0; i < 100; ++i) {
                for (int j = 0; j < v.size(); ++j) {
                    Vector3f color = Vector3f(v[j], v[j], v[j]);
                    image.setPixel(x*100 + i, y*100 + j, color);
                }
            }     
        }
    }


    for (int x = 0; x < _grid_width; ++x) {
        for (int y = 0; y < _grid_width; ++y) {
            //Vector3f color = getDensity(x, y);
            vector<float> v = interpolate(x, y);
            for (int i = 0; i < PIXELS_PER_VOXEL; ++i) { 
                for (int j = 0; j < PIXELS_PER_VOXEL; ++j) {
                    Vector3f color = Vector3f(v[j], v[j], v[j]);
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

vector<float> Renderer::interpolate(int x, int y) {
    std::vector<float> v;
    //v.resize(100);
    // interpolate pixel values
    int k = y;

    float f_k = getDensity(x, y)[0];
    
    float f_kp1;
    if (y != _grid_width - 1) {
         f_kp1 = getDensity(x, y + 1)[0];
    } else {
        f_kp1 = f_k;
    }
    float f_kp2;
    if (y < _grid_width - 2) {
         f_kp2 = getDensity(x, y + 2)[0];
    } else {
        f_kp2 = f_kp1;
    }

    float f_k_1;
    if (y != 0) {
        f_k_1 = getDensity(x, y - 1)[0];
    } else {
        f_k_1 = f_k;
    }
     
    float delta_k = f_kp1 - f_k;
    float d_k = (f_kp1 - f_k_1) * 0.5;
    float d_kp1 = (f_kp2 - f_k) * 0.5;

    if (delta_k == 0) {
        d_k = 0;
        d_kp1 = 0;
    } else {
        bool positive = delta_k > 0;
        if (d_k > 0 != positive) {
            d_k = 0;
        } else if (d_kp1 > 0 != positive) {
            d_kp1 = 0;
        }
    }

    float a_0 = f_k;
    float a_1 = d_k;
    float a_2 = 3 * delta_k - 2 * d_k - d_kp1;
    float a_3 = d_k + d_kp1 - delta_k;

    for (int i = 0; i < 100; ++i) {
        float new_d = a_3 * pow(i / 100.0, 3) + a_2 * pow(i / 100.0, 2) + a_1 * i / 100.0 + a_0;
        v.push_back(new_d);
    }

    return v;
}


