#include "fluidsolver.cpp"
#include "fluidsystem.h"

#include "gl.h"
#include "camera.h"
#include <random>
#include <cstdio>
#include <vector>
#include <vecmath.h>

using namespace std;


#define IX(i,j,k) ((i)+(M+2)*(j) + (M+2)*(N+2)*(k))

//constants for buoyancy equation
const float alpha = 1.0f;
const float beta = 1.0f;

//constant for vorticity confinement
const float epsilon = 1.0f;


float rand_uniform(float low, float hi) {
   float abs = hi - low;
   float f = (float)rand() / RAND_MAX;
   f *= abs;
   f += low;
   return f;
}

//Performs the same function as IX, but makes sure the indices are within range
int FluidSystem::get_ind (int x, int y, int z){
  x = max(0, x); y = max(0,y); z = max(0,z);
  x = min(M, x); y = min(N,y); z = min(O,z);
  return IX(x,y,z);
}

void FluidSystem::takeStep(float diff, float visc, float dt){
    // vel_step ( int M, int N, int O, float * u, float * v,  float * w, float * u0, float * v0, float * w0, float visc, float dt )
    // dens_step ( int M, int N, int O, float * x, float * x0, float * u, float * v, float * w, float diff, float dt )
    //dens_source[IX(M/2,N/2,O/2)] = 100;

    int size=(M+2)*(N+2)*(O+2);
    for (int i = 0; i < size; i+= 1) {
      //add gravity buoyancy force
      v_source[i] -= alpha * dens[i];
      //add temy buoyancy force
      v_source[i] += beta * (temp[i] - 0.0f);
    }

    //std::cout << "1" << std::endl;
    // Calculate curl field of velocity field
    Vector3f curl [size];
    float curl_mag [size];
    for (int i=0 ; i<M ; i++ ) { for (int j=0 ; j<N ; j++ ) { for (int k=0 ; k<O ; k++ ) {
      float xComp = ((w[get_ind(i,j+1,k)]-w[get_ind(i,j-1,k)]) - (v[get_ind(i,j,k+1)]-v[get_ind(i,j,k-1)]));
      float yComp = ((w[get_ind(i+1,j,k)]-w[get_ind(i-1,j,k)]) - (u[get_ind(i,j,k+1)]-u[get_ind(i,j,k-1)]));
      float zComp = ((v[get_ind(i+1,j,k)]-v[get_ind(i-1,j,k)]) - (u[get_ind(i,j+1,k)]-u[get_ind(i,j-1,k)]));
      curl[IX(i,j,k)] = Vector3f(xComp, yComp, zComp);

      //std::cout << zComp << ", " << j << ", " << k << std::endl;
      //std::cout << v[get_ind(i+1,j,k)] << ", " << v[get_ind(i-1,j,k)] << ", " << u[get_ind(i,j+1,k)] << ", " << u[get_ind(i,j-1,k)] << std::endl;
      //std::cout << get_ind(i,j+1,k)] << ", " << u[get_ind(i,j-1,k)] << std::endl;
      //curl[IX(i,j,k)].print();

      curl_mag[IX(i,j,k)] = curl[IX(i,j,k)].abs();
    } } }

    //std::cout << "2" << std::endl;
    // Calculate gradient of curl
    Vector3f gradient [size];
    Vector3f vorticity_norm [size];
    for (int i=0 ; i<M ; i++ ) { for (int j=0 ; j<N ; j++ ) { for (int k=0 ; k<O ; k++ ) {
      float xComp = (curl_mag[get_ind(i + 1,j,k)] - curl_mag[get_ind(i - 1,j,k)]);
      float yComp = (curl_mag[get_ind(i,j + 1,k)] - curl_mag[get_ind(i,j - 1,k)]);
      float zComp = (curl_mag[get_ind(i,j,k + 1)] - curl_mag[get_ind(i,j,k - 1)]);
      gradient[IX(i,j,k)] = Vector3f(xComp, yComp, zComp);

      //gradient[IX(i,j,k)].print();

      vorticity_norm[IX(i,j,k)] = gradient[IX(i,j,k)];
      if (vorticity_norm[IX(i,j,k)] != Vector3f::ZERO) {
        vorticity_norm[IX(i,j,k)].normalize();
        //std::cout << "hi" << std::endl;
      }
      //vorticity_norm[IX(i,j,k)].print();
    } } }

    //std::cout << "3" << std::endl;
    // Calculate vorticity confinement force
    for (int i=0 ; i<M ; i++ ) { for (int j=0 ; j<N ; j++ ) { for (int k=0 ; k<O ; k++ ) {
      Vector3f cross = Vector3f::cross(vorticity_norm[IX(i,j,k)], curl[IX(i,j,k)]);
      //curl[i].print();
      Vector3f confinement_force = epsilon * M * cross;
      
      u_source[IX(i,j,k)] += confinement_force.x();
      v_source[IX(i,j,k)] += confinement_force.y();
      w_source[IX(i,j,k)] += confinement_force.z();

      //confinement_force.print();
    } } }

    // //std::cout << "done" << std::endl;


    // //div[IX(i,j,k)] = 1.0/3.0*((u[IX(i+1,j,k)]-u[IX(i-1,j,k)])/M+(v[IX(i,j+1,k)]-v[IX(i,j-1,k)])/M+(w[IX(i,j,k+1)]-w[IX(i,j,k-1)])/M);


      vel_step (M, N, O, u, v, w, u_source, v_source, w_source, visc, dt);
      dens_step (M, N, O, dens, dens_source, u, v, w, diff, dt);
    // // //advect temperature
      dens_step (M, N, O, temp, temp_source, u, v, w, diff, dt);

    float currMass = 0;
    for (int i = 0; i < M; i += 1) {
      for (int j = 0; j < N; j += 1) {
        for (int k = 0; k < O; k+= 1) {
          currMass += dens[IX(i,j,k)];
        }
      }
    }

    for (int i = 0; i < M; i += 1) {
      for (int j = 0; j < N; j += 1) {
        for (int k = 0; k < O; k+= 1) {
          dens[IX(i,j,k)] *= totalMass / currMass;
        }
      }
    }
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




