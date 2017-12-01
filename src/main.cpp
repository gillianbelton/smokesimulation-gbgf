#include <cstring>
#include <iostream>

#include "../../ray_tracer/ArgParser.h"
#include "../../ray_tracer/Renderer.h"

using namespace std;

const int DIM = 3;
vector<vector<vector<float>>> density_grid;

int
main(int argc, const char *argv[])
{
    // Report help usage if no args specified.
    if (argc == 1) {
        std::cout << "Usage: a5 <args>\n"
            << "\n"
            << "Args:\n"
            << "\t-input <scene>\n"
            << "\t-size <width> <height>\n"
            << "\t-output <image.png>\n"
            << "\t[-depth <depth_min> <depth_max> <depth_image.png>\n]"
            << "\t[-normals <normals_image.png>]\n"
            << "\t[-bounces <max_bounces>\n]"
            << "\t[-shadows\n]"
            << "\n"
            ;
        return 1;
    }

    // ArgParser argsParser(argc, argv);

    density_grid.resize(DIM);
    for (int i = 0; i < DIM; ++i) {
        density_grid[i].resize(DIM);
        for (int j = 0; j < DIM; ++j)
            density_grid[i][j].resize(DIM);
    }

    for (int x = 0; x < DIM; ++x) {
       for (int y = 0; y < DIM; ++y) {
            for (int z = 0; z < DIM; ++z) {
                density_grid[x][y][z] = 0.5f;
            } 
        } 
    }
    float grid_dim = 4;
    Renderer renderer(density_grid, grid_dim);
    renderer.Render();
    return 0;
}
