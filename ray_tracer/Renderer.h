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
    void Render();
    Vector3f getDensity(int x, int y);
    vector<vector<vector<float>>> _density_grid;
    int _grid_width;
    int _pic_width;

};

#endif // RENDERER_H
