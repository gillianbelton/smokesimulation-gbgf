#include "Renderer.h"

#include "Camera.h"
#include "Image.h"
#include "Ray.h"

#include <limits>
#include <math.h>

using namespace std;

const int PIXELS_PER_VOXEL = 10;
const int PPV = PIXELS_PER_VOXEL;


Renderer::Renderer(vector<vector<vector<float>>> dg, int grid_dim) :
    _density_grid(dg),
    _grid_width(grid_dim),
    _pic_width(grid_dim * PIXELS_PER_VOXEL)
{
}


void Renderer::Render(string filename)
{
    Image image(_pic_width, _pic_width);

    for (int x = 0; x < _grid_width; ++x) {
        for (int y = 0; y < _grid_width; ++y) {
            //for each grid point, go through the pixels in between
            for (int i = 0; i < PIXELS_PER_VOXEL; ++i) { 
                for (int j = 0; j < PIXELS_PER_VOXEL; ++j) {
                    Vector3f color = getDensitySum(x*PIXELS_PER_VOXEL + i, y*PIXELS_PER_VOXEL + j);
                    image.setPixel(x*PIXELS_PER_VOXEL + i, y*PIXELS_PER_VOXEL + j, color); 
                }
            }     
        }
    }


    // for (int x = 0; x < _grid_width; ++x) {
    //     for (int y = 0; y < _grid_width; ++y) {
    //         //Vector3f color = getDensitySum(x, y);
    //         vector<float> v = interpolate(x, y);
    //         for (int i = 0; i < PIXELS_PER_VOXEL; ++i) { 
    //             for (int j = 0; j < PIXELS_PER_VOXEL; ++j) {
    //                 Vector3f color = Vector3f(v[j], v[j], v[j]);
    //                 image.setPixel(x*PIXELS_PER_VOXEL + i, y*PIXELS_PER_VOXEL + j, color); 
    //             }
    //         }     
    //     }
    // }

    image.savePNG(filename);
}

Vector3f Renderer::getDensitySum(int x, int y) {
    
    float total = 0;
    
    float xf = x;
    float yf = y;

    float gridX = xf / PIXELS_PER_VOXEL;
    float gridY = yf / PIXELS_PER_VOXEL;

    for (float z = 0; z < _grid_width; z += 1) {
        total += queryDensity(gridX, gridY, z);
    }
    total /= _grid_width;
    return Vector3f(total, total, total);
}

float lerp(float a, float b, float t) {
    return (a * (1 - t)) + (b * t);
}


float Renderer::queryDensity(float x, float y, float z) {
    // Find voxel points around
    int x_floor = floor(x);
    int y_floor = floor(y);
    int z_floor = floor(z);

    x_floor = max(0, x_floor);
    y_floor = max(0, y_floor);
    z_floor = max(0, z_floor);

    int x_ceil = ceil(x);
    int y_ceil = ceil(y);
    int z_ceil = ceil(z);

    x_ceil = min(_grid_width - 1, x_ceil);
    y_ceil = min(_grid_width - 1, y_ceil);
    z_ceil = min(_grid_width - 1, z_ceil);

    // Find float [0,1] for distance between x_floor and ceil
    float xd = (x - x_floor)/(x_ceil - x_floor);
    float yd = (y - y_floor)/(y_ceil - y_floor);
    float zd = (z - z_floor)/(z_ceil - z_floor);

    if (x_ceil == x_floor) {
        xd = 0;
    }
    if (y_ceil == y_floor) {
        yd = 0;
    }
    if (z_ceil == z_floor) {
        zd = 0;
    }

    // Find corners of interpolation cube
    float c000 = _density_grid[x_floor][y_floor][z_floor];
    float c001 = _density_grid[x_floor][y_floor][z_ceil];
    float c010 = _density_grid[x_floor][y_ceil][z_floor];
    float c100 = _density_grid[x_ceil][y_floor][z_floor];
    float c110 = _density_grid[x_ceil][y_ceil][z_floor];
    float c011 = _density_grid[x_floor][y_ceil][z_ceil];
    float c101 = _density_grid[x_ceil][y_floor][z_ceil];
    float c111 = _density_grid[x_ceil][y_ceil][z_ceil];

    // interpolate in x
    float c00 = lerp(c000, c100, xd);
    float c01 = lerp(c001, c101, xd);
    float c10 = lerp(c010, c110, xd);
    float c11 = lerp(c011, c111, xd);

    //interpolate in y
    float c0 = lerp(c00, c10, yd);
    float c1 = lerp(c01, c11, yd);

    //interpolate in z
    float c = lerp(c0, c1, zd);
    return c;
}


vector<float> Renderer::interpolate(int x, int y) {
    std::vector<float> v;
    //v.resize(100);
    // interpolate pixel values
    int k = y;

    float f_k = getDensitySum(x, y)[0];
    
    float f_kp1;
    if (y != _grid_width - 1) {
         f_kp1 = getDensitySum(x, y + 1)[0];
    } else {
        f_kp1 = f_k;
    }
    float f_kp2;
    if (y < _grid_width - 2) {
         f_kp2 = getDensitySum(x, y + 2)[0];
    } else {
        f_kp2 = f_kp1;
    }

    float f_k_1;
    if (y != 0) {
        f_k_1 = getDensitySum(x, y - 1)[0];
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

    for (int i = 0; i < PPV; ++i) {
        float new_d = a_3 * pow(i / PPV, 3) + a_2 * pow(i / PPV, 2) + a_1 * i / PPV + a_0;
        v.push_back(new_d);
    }

    return v;
}


