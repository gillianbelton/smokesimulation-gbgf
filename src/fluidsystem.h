#ifndef FLUIDSYSTEM_H
#define FLUIDSYSTEM_H
#define IX(i,j,k) ((i)+(M+2)*(j) + (M+2)*(N+2)*(k))

#include <vector>
#include <vecmath.h>
#include <cstdint>
#include <stdlib.h> // pulls in declaration of malloc, free

// helper for uniform distribution
float rand_uniform(float low, float hi);

struct GLProgram;
class FluidSystem
{
public:
    
    virtual ~FluidSystem() {
    }

    // Advance the system by one time step
    void takeStep(float diff, float visc, float dt);

    // Debug the densities of the system
    void print();

    // Construct a new fluid system with dimensions M x N x O
    FluidSystem(int M, int N, int O)
        : M(M),
          N(N),
          O(O) {
        allocate_data();

        if (doSphere) {
            //Create sphere size, position
            sphere_radius = M / 4;
            sphere_center = Vector3f(M/2, N/2, O/2);

            //Populate sphere with density, velocity
            for (int i = 0; i < M; i += 1) {
                for (int j = 0; j < N; j += 1) {
                    for (int k = 0; k < O; k+= 1) {
                        Vector3f pos = Vector3f(i,j,k);
                        if ((pos - sphere_center).absSquared() < sphere_radius * sphere_radius) {
                            dens[IX(i,j,k)] = 0.5;
                            v[IX(i,j,k)] = 10;
                            temp[IX(i,j,k)] = 4;
                        }
                }
            }
        }

        }
    }

    // Set the densities everywhere to a specific value
    void setDensityUniform(float densVal) {
        for (int i = 0; i < M; i += 1) {
            for (int j = 0; j < N; j += 1) {
                for (int k = 0; k < O; k+= 1) {
                    dens[IX(i, j, k)] = densVal;
                }
            }
        }
    }

    // Get the density of the fluid at a specific point
    float densityAt(int x, int y, int z) {
        return dens[IX(x, y, z)];
    }

    void clear_data ( void )
    {
        int i, size=(M+2)*(N+2)*(O+2);

        for ( i=0 ; i<size ; i++ ) {
            u[i] = v[i] = w[i] = u_source[i] = v_source[i] =w_source[i] = dens[i] = dens_source[i] = 0.0f;
        }

        addforce[0] = addforce[1] = addforce[2] = 0;
    }

    int allocate_data ( void )
    {
        int size = (M+2)*(N+2)*(O+2);

        u           = (float *) malloc ( size*sizeof(float) );
        v           = (float *) malloc ( size*sizeof(float) );
        w           = (float *) malloc ( size*sizeof(float) );
        u_source      = (float *) malloc ( size*sizeof(float) );
        v_source      = (float *) malloc ( size*sizeof(float) );
        w_source      = (float *) malloc ( size*sizeof(float) );
        dens        = (float *) malloc ( size*sizeof(float) );  
        dens_source   = (float *) malloc ( size*sizeof(float) );
        temp        = (float *) malloc ( size*sizeof(float) );  
        temp_source   = (float *) malloc ( size*sizeof(float) );

        if ( !u || !v || !w || !u_source || !v_source || !w_source || !dens || !dens_source ) {
            fprintf ( stderr, "cannot allocate data\n" );
            return ( 0 );
        }

        return ( 1 );
    }



 protected:
    float * u, * v, *w, * u_source, * v_source, * w_source;
    float * dens, * dens_source;
    float * temp, * temp_source;
    int M, N, O;

    Vector3f sphere_center;
    float sphere_radius;
    bool doSphere = true;

    int addforce[3] = {0, 0, 0};
    int addsource = 0;
};




#endif
