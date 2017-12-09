#ifndef FLUIDSYSTEM_H
#define FLUIDSYSTEM_H
#define IX(i,j,k) ((i)+(M+2)*(j) + (M+2)*(N+2)*(k))

#include <vector>
#include <vecmath.h>
#include <cstdint>

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
            u[i] = v[i] = w[i] = u_prev[i] = v_prev[i] =w_prev[i] = dens[i] = dens_prev[i] = 0.0f;
        }

        addforce[0] = addforce[1] = addforce[2] = 0;
    }

    int allocate_data ( void )
    {
        int size = (M+2)*(N+2)*(O+2);

        u           = (float *) malloc ( size*sizeof(float) );
        v           = (float *) malloc ( size*sizeof(float) );
        w           = (float *) malloc ( size*sizeof(float) );
        u_prev      = (float *) malloc ( size*sizeof(float) );
        v_prev      = (float *) malloc ( size*sizeof(float) );
        w_prev      = (float *) malloc ( size*sizeof(float) );
        dens        = (float *) malloc ( size*sizeof(float) );  
        dens_prev   = (float *) malloc ( size*sizeof(float) );

        if ( !u || !v || !w || !u_prev || !v_prev || !w_prev || !dens || !dens_prev ) {
            fprintf ( stderr, "cannot allocate data\n" );
            return ( 0 );
        }

        return ( 1 );
    }



 protected:
    float * u, * v, *w, * u_prev, * v_prev, * w_prev;
    float * dens, * dens_prev;
    int M, N, O;

    int addforce[3] = {0, 0, 0};
    int addsource = 0;
};




#endif
