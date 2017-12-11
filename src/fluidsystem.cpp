#include "fluidsolver.cpp"
#include "fluidsystem.h"

#include "gl.h"
#include "camera.h"
#include <random>
#include <cstdio>
#include <vector>

#define IX(i,j,k) ((i)+(M+2)*(j) + (M+2)*(N+2)*(k))

float rand_uniform(float low, float hi) {
   float abs = hi - low;
   float f = (float)rand() / RAND_MAX;
   f *= abs;
   f += low;
   return f;
}

void FluidSystem::takeStep(float diff, float visc, float dt){
    // vel_step ( int M, int N, int O, float * u, float * v,  float * w, float * u0, float * v0, float * w0, float visc, float dt )
    // dens_step ( int M, int N, int O, float * x, float * x0, float * u, float * v, float * w, float diff, float dt )
    dens_source[IX(M/2,N/2,O/2)] = 100;
    vel_step (M, N, O, u, v, w, u_source, v_source, w_source, visc, dt);
    dens_step (M, N, O, dens, dens_source, u, v, w, diff, dt);
}

void FluidSystem::print() {
    
    for (int j = N - 1; j >= 0; j-=1) {
        for (int i = 0; i < M; i+=1) {

            float dens_sum = 0;
            for (int k = 0; k < O; k+=1) {
                dens_sum += densityAt(i, j, k);
            }

            printf(" %.4f", dens_sum);
        }
        printf("\n");
    }

    printf("\n");
}

//TODO write hooks into fluidsystem rep, also allow force adding




