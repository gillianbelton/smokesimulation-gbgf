#include "pendulumsystem.h"

#include <cassert>
#include "camera.h"
#include "vertexrecorder.h"
#include <stdlib.h>
#include "Spring.cpp"

// TODO adjust to number of particles.
const double BALL_MASS = 1.0;
const double GRAVITY = 9.8;
const double DRAG_COEFF = 0.3;
const double REST_LENGTH = 0.5;
const double STIFFNESS = 50.0;
std::vector<Spring> springs;

PendulumSystem::PendulumSystem()
{

    // TODO 4.2 Add particles for simple pendulum
    // TODO 4.3 Extend to multiple particles

    // To add a bit of randomness, use e.g.
    // float f = rand_uniform(-0.5f, 0.5f);
    // in your initial conditions.

    //m_vVecState = vector <Vector3f> of (velocity, pos, velocity, pos, etc ... )
    // m_vVecState = std::vector<Vector3f>();
    m_vVecState.push_back(Vector3f(0, 0, 0));    // vel 0
    m_vVecState.push_back(Vector3f(-1, 0, 0));    // pos 0 
    m_vVecState.push_back(Vector3f(0, 0, 0));   // vel 1
    m_vVecState.push_back(Vector3f(-1, -0.5, 0));   // pos 1
    
    //four springs:

    m_vVecState.push_back(Vector3f(0, 0, 0));   // vel 2
    m_vVecState.push_back(Vector3f(-1, -1, 0));   // pos 2
    m_vVecState.push_back(Vector3f(0, -1, 0));   // vel 3
    m_vVecState.push_back(Vector3f(-1, -2, 0));   // pos 3

    springs.push_back(Spring(0, 1, REST_LENGTH, STIFFNESS));  //springs
    springs.push_back(Spring(1, 2, REST_LENGTH, STIFFNESS));
    springs.push_back(Spring(2, 3, REST_LENGTH, STIFFNESS));

}


std::vector<Vector3f> PendulumSystem::evalF(std::vector<Vector3f> state)
{
    std::vector<Vector3f> f(state.size()); 
    // TODO 4.1: implement evalF
    // takes in (velocity, pos) pairs, calculates the new accel/velocity of the particles
    // returns (acceleration, velocity) pairs to be used to update the particle state 

    int i = 0;
    for (Vector3f v : state) {
        if (i % 2 == 0) {
            //even => velocity, return acceleration
            Vector3f gravityForce = Vector3f(0, -BALL_MASS * GRAVITY, 0);
            Vector3f viscousForce = Vector3f(-DRAG_COEFF * v.x(), -DRAG_COEFF * v.y(), -DRAG_COEFF * v.z());
            Vector3f springForce = Vector3f(0, 0, 0);
            for (Spring spring : springs) {
                if (spring.getP1() == i/2) {
                    Vector3f distance = m_vVecState[spring.getP1() * 2 + 1] - m_vVecState[spring.getP2() * 2 + 1];
                    springForce += spring.getForce(distance);
                }  
                else if (spring.getP2() == i/2) {
                    Vector3f distance = m_vVecState[spring.getP2() * 2 + 1] - m_vVecState[spring.getP1() * 2 + 1];
                    springForce += spring.getForce(distance);
                }     
            }
            Vector3f totalAcceleration = Vector3f((springForce + viscousForce + gravityForce) / BALL_MASS);
            f[i] = totalAcceleration;
        } else {
            //return velocity
            f[i] = state[i-1];
        }
        ++i;
    }
    f[0] = Vector3f(0,0,0);
    f[1] = Vector3f(0,0,0);
    return f;
}

// render the system (ie draw the particles)
void PendulumSystem::draw(GLProgram& gl)
{
    const Vector3f PENDULUM_COLOR(0.73f, 0.0f, 0.83f);
    gl.updateMaterial(PENDULUM_COLOR);

    // TODO 4.2, 4.3

   for (int i = 0; i < m_vVecState.size()/2; ++i) {
        gl.updateModelMatrix(Matrix4f::translation(m_vVecState[i * 2 + 1]));
        drawSphere(0.075f, 10, 10);
    }
}


