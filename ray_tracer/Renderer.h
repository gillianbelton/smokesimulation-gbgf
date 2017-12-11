#ifndef RENDERER_H
#define RENDERER_H

#include <string>
#include <vector>

using namespace std;

class Vector3f;

class Renderer
{
  public:
    // Instantiates a renderer for the given scene.
    Renderer(vector<vector<vector<float>>> dg, int grid_dim);
    void Render(string filename);
<<<<<<< Updated upstream
    Vector3f getDensitySum(int x, int y);
    float queryDensity(float x, float y, float z);
    vector<float> interpolate(int x, int y);
=======
    Vector3f getDensity(int x, int y);
    float getVoxelDensity(int x, int y);
    vector<float> interpolateY(int x);
    vector<float> interpolateX(int y);
    Vector3f getDensityInterpolated(int x, int y);
    void interpolateVoxels();
>>>>>>> Stashed changes

    vector<vector<vector<float>>> _density_grid;
    int _grid_width;
    int _pic_width;

};

#endif // RENDERER_H
