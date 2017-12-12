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



// ------------ my code -------------------
    //interpolateVoxels();

    vector<vector<float>> voxelsInterp_Y;
    vector<vector<float>> voxelsInterp_X;

    // //interpolate the along the X axis
    // for (int y = 0; y < _grid_width; ++y) {
    //     voxelsInterp_X.push_back(interpolateX(y));
    // }
    
    // //interpolate the along the Y axis
    // for (int x = 0; x < _grid_width; ++x) {
    //     voxelsInterp_Y.push_back(interpolateY(x));
    // }

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
    //     vector<float> v = voxelsInterp_Y[x];
    //     for (int i = 0; i < PIXELS_PER_VOXEL; ++i) { 
    //         for (int j = 0; j < PIXELS_PER_VOXEL * _grid_width; ++j) {
    //             Vector3f color = Vector3f(v[j], v[j], v[j]);
    //             image.setPixel(x*PIXELS_PER_VOXEL + i, j, color); 
    //         }
    //     }     
    // }

    image.savePNG(filename);
}

Vector3f Renderer::getDensitySum(int x, int y) {

    float total = 0;

    float xf = (float) x;
    float yf = (float) y;

    float gridX = xf / PIXELS_PER_VOXEL;
    float gridY = yf / PIXELS_PER_VOXEL;

    for (float z = 0; z < _grid_width; z += 1) {
        total += queryDensity(gridX,gridY, z);
    }
    total /= _grid_width;
    return Vector3f(total, total, total);
}

float lerp(float a, float b, float t) {
    return (a * (1 - t)) + (b * t);
}

float getMCInterpolation(float a, float b, float t) {

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


// Vector3f Renderer::getDensityInterpolated(int x, int y) {
//     float v = (voxelsInterp_Y[x][y] + voxelsInterp_Y[y][x] ) * 0.5;
//     return Vector3f(v, v, v);
// }

float Renderer::getVoxelDensity(int x, int y) {
    float total = 0;
    for (int z = 0; z < _grid_width; ++z) {
        total += _density_grid[x][y][z];
    }
    total /= _grid_width;
    return total;
}


vector<float> Renderer::interpolateY(int x) {
    vector<float> v;
    for (int y = 0; y < _grid_width; ++y){
         // interpolate pixel values

        float f_k = getVoxelDensity(x, y);
        
        float f_kp1;
        if (y < _grid_width - 1) {
             f_kp1 = getVoxelDensity(x, y + 1);
        } else {
            f_kp1 = f_k;
        }
        float f_kp2;
        if (y < _grid_width - 2) {
             f_kp2 = getVoxelDensity(x, y + 2);
        } else {
            f_kp2 = f_kp1;
        }

        float f_k_1;
        if (y > 0) {
            f_k_1 = getVoxelDensity(x, y - 1);
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

        for (int i = 0; i < PIXELS_PER_VOXEL; ++i) {
            float new_d = a_3 * pow(i / PIXELS_PER_VOXEL, 3) + a_2 * pow(i / PIXELS_PER_VOXEL, 2) + a_1 * i / PIXELS_PER_VOXEL + a_0;
            v.push_back(new_d);
        }
    }

    return v;
}

vector<float> Renderer::interpolateX(int y) {
    vector<float> v;
    for (int x = 0; x < _grid_width; ++x){
         // interpolate pixel values

        float f_k = getVoxelDensity(x, y);
        
        float f_kp1;
        if (x < _grid_width - 1) {
             f_kp1 = getVoxelDensity(x + 1, y);
        } else {
            f_kp1 = f_k;
        }
        float f_kp2;
        if (x < _grid_width - 2) {
             f_kp2 = getVoxelDensity(x + 2, y);
        } else {
            f_kp2 = f_kp1;
        }

        float f_k_1;
        if (x > 0) {
            f_k_1 = getVoxelDensity(x - 1, y);
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

        for (int i = 0; i < PIXELS_PER_VOXEL; ++i) {
            float new_d = a_3 * pow(i / PIXELS_PER_VOXEL, 3) + a_2 * pow(i / PIXELS_PER_VOXEL, 2) + a_1 * i / PIXELS_PER_VOXEL + a_0;
            v.push_back(new_d);
        }
    }

    return v;
}