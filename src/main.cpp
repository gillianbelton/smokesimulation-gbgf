#include <cstring>
#include <iostream>

#include "../../ray_tracer/Renderer.h"

using namespace std;

const int DIM = 4;
vector<vector<vector<float>>> density_grid;

int
main(int argc, const char *argv[])
{

    density_grid.resize(DIM);
    for (int i = 0; i < DIM; ++i) {
        density_grid[i].resize(DIM);
        for (int j = 0; j < DIM; ++j)
            density_grid[i][j].resize(DIM);
    }

    for (int x = 0; x < DIM; ++x) {
       for (int y = 0; y < DIM; ++y) {
            for (int z = 0; z < DIM; ++z) {
                if (x > 1) {
                    density_grid[x][y][z] = 0.8f;
                } else {
                    density_grid[x][y][z] = 0.3f; 
                }
            } 
        } 
    }
    Renderer renderer(density_grid, DIM);
    renderer.Render();
    return 0;
}
