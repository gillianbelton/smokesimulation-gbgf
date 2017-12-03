#include "fluidsolver.cpp"
#include "fluidsystem.h"

#include "gl.h"
#include "camera.h"
#include <random>
#include <cstdio>

float rand_uniform(float low, float hi) {
   float abs = hi - low;
   float f = (float)rand() / RAND_MAX;
   f *= abs;
   f += low;
   return f;
}

void takeStep(float diff, float visc, float dt){
    // vel_step ( int M, int N, int O, float * u, float * v,  float * w, float * u0, float * v0, float * w0, float visc, float dt )
    // dens_step ( int M, int N, int O, float * x, float * x0, float * u, float * v, float * w, float diff, float dt )\

    vel_step (M, N, O, u, v, w, u0, v0, w0, visc, dt);
    dens_step (M, N, O, x, x0, u, v, w, diff, dt);
}

//TODO write hooks into fluidsystem rep, also allow force adding




