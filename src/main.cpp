#include <cstring>
#include <iostream>

#include "fluidsystem.h"
#include "../../ray_tracer/Renderer.h"

using namespace std;

// <<<<<<< HEAD
const int DIM = 70;
const int NUM_STEP = 15;
// // =======
// const int DIM = 30;
// const int NUM_STEP = 100;
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

        string filename = "smoke_file_" + std::to_string(i) + ".png";
        printf("filename: %s\n", filename.c_str());
        // Take fluid system steps
        
        
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

        fluidSystem.takeStep(0.00f, 0.0f, 0.01f);
    }

    return 0;
}
