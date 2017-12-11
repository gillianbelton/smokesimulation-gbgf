#include <cstring>
#include <iostream>

#include "fluidsystem.h"
#include "../../ray_tracer/Renderer.h"

using namespace std;

const int DIM = 15;
const int NUM_STEP = 5;
vector<vector<vector<float>>> density_grid;

int
main(int argc, const char *argv[])
{
    FluidSystem fluidSystem = FluidSystem(DIM, DIM, DIM);
    
    //fluidSystem.setDensityUniform(0.7f);

    density_grid.resize(DIM);
    for (int i = 0; i < DIM; ++i) {
        density_grid[i].resize(DIM);
        for (int j = 0; j < DIM; ++j)
            density_grid[i][j].resize(DIM);
    }

    for (int i = 0; i < NUM_STEP; ++i) {

        string filename = "smoke_file_" + i;
        // Take fluid system steps
        for (int j = 0; j < 5; j+= 1)
        {
            //printf("step\n");
            fluidSystem.takeStep(0.001f, 0.0f, 0.4f);
        }

        // Store fluid system values into density grid
        for (int x = 0; x < DIM; ++x) {
           for (int y = 0; y < DIM; ++y) {
                for (int z = 0; z < DIM; ++z) {
                    density_grid[x][y][z] = fluidSystem.densityAt(x, y, z);
                } 
            } 
        }

        Renderer renderer(density_grid, DIM);
        renderer.Render(filename);
    }

    return 0;
}
