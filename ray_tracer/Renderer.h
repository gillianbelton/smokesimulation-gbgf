#ifndef RENDERER_H
#define RENDERER_H

#include <string>

#include "SceneParser.h"
#include "ArgParser.h"

using namespace std;

class Hit;
class Vector3f;
class Ray;

class Renderer
{
  public:
    // Instantiates a renderer for the given scene.
    Renderer(vector<vector<vector<float>>> dg, float grid_dim);
    void Render();
  //private:
    // Vector3f traceRay(const Ray &ray, float tmin, int bounces, 
    //                   Hit &hit) const;

   private:
    vector<vector<vector<float>>> _density_grid;
    int _grid_width;

};

#endif // RENDERER_H
