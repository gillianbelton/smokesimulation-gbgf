
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// #include "glutils/glut.h"
// #include <GLUT/gl.h>
// #include <GLUT/glu.h>
#include <GLUT/glut.h>

#define IX(i,j,k) ((i)+(M+2)*(j) + (M+2)*(N+2)*(k)) 
#define MAX(a,b)            (((a) > (b)) ? (a) : (b))

#define WINDOW_TITLE "Fluid"
#define WINDOW_WIDTH 768
#define WINDOW_HEIGHT 768
#define SIZE 42 // Best not to raise this very high

extern void dens_step ( int M, int N, int O, float * x, float * x0, float * u, float * v, float * w, float diff, float dt );
extern void vel_step (int M, int N, int O, float * u, float * v,  float * w, float * u0, float * v0, float * w0, float visc, float dt );


//fluid field information
static int M = SIZE; // grid x
static int N = SIZE; // grid y
static int O = SIZE; // grid z
static float dt = 0.4f; // time delta
static float diff = 0.0f; // diffuse
static float visc = 0.0f; // viscosity
static float force = 10.0f;  // added on keypress on an axis
static float source = 200.0f; // density
static float source_alpha =  0.05; //for displaying density

static int addforce[3] = {0, 0, 0};
static int addsource = 0;

static float * u, * v, *w, * u_prev, * v_prev, * w_prev;
static float * dens, * dens_prev;

static int dvel = 0;
static int dhelp = 1;
static int daxis = 0;

static int win_id;
static int win_x = WINDOW_WIDTH; 
static int  win_y = WINDOW_HEIGHT;
static int mouse_down[3];
static int omx, omy, mx, my;

enum { 
	PAN = 1,
	ROTATE,				
	ZOOM				
};

GLfloat trans[3];
GLfloat rot[2];				

static void free_data ( void )
{
	if ( u ) free ( u );
	if ( v ) free ( v );
	if ( w ) free ( w );
	if ( u_prev ) free ( u_prev );
	if ( v_prev ) free ( v_prev );
	if ( w_prev ) free ( w_prev );
	if ( dens ) free ( dens );
	if ( dens_prev ) free ( dens_prev );
}

static void clear_data ( void )
{
	int i, size=(M+2)*(N+2)*(O+2);

	for ( i=0 ; i<size ; i++ ) {
		u[i] = v[i] = w[i] = u_prev[i] = v_prev[i] =w_prev[i] = dens[i] = dens_prev[i] = 0.0f;
	}

	addforce[0] = addforce[1] = addforce[2] = 0;
}

static int allocate_data ( void )
{
	int size = (M+2)*(N+2)*(O+2);

	u			= (float *) malloc ( size*sizeof(float) );
	v			= (float *) malloc ( size*sizeof(float) );
	w			= (float *) malloc ( size*sizeof(float) );
	u_prev		= (float *) malloc ( size*sizeof(float) );
	v_prev		= (float *) malloc ( size*sizeof(float) );
	w_prev		= (float *) malloc ( size*sizeof(float) );
	dens		= (float *) malloc ( size*sizeof(float) );	
	dens_prev	= (float *) malloc ( size*sizeof(float) );

	if ( !u || !v || !w || !u_prev || !v_prev || !w_prev || !dens || !dens_prev ) {
		fprintf ( stderr, "cannot allocate data\n" );
		return ( 0 );
	}

	return ( 1 );
}

static void get_force_source ( float * d, float * u, float * v, float * w )
{
	int i, j, k, size=(M+2)*(N+2)*(O+2);;

	for ( i=0 ; i<size ; i++ ) {
		u[i] = v[i] = w[i]= d[i] = 0.0f;
	}

	if(addforce[0]==1) // x
	{
		i=2,
		j=N/2;
		k=O/2;

		if ( i<1 || i>M || j<1 || j>N || k <1 || k>O) return;
		u[IX(i,j,k)] = force*10;
		addforce[0] = 0;
	}	

	if(addforce[1]==1)
	{
		i=M/2,
		j=2;
		k=O/2;

		if ( i<1 || i>M || j<1 || j>N || k <1 || k>O) return;
		v[IX(i,j,k)] = force*10;
		addforce[1] = 0;
	}	

	if(addforce[2]==1) // y
	{
		i=M/2,
		j=N/2;
		k=2;

		if ( i<1 || i>M || j<1 || j>N || k <1 || k>O) return;
		w[IX(i,j,k)] = force*10; 	
		addforce[2] = 0;
	}	

	if(addsource==1)
	{
		i=M/2,
		j=N/2;
		k=O/2;
		d[IX(i,j,k)] = source;
		addsource = 0;
	}
}
