#include "clothsystem.h"

#include "camera.h"
#include "vertexrecorder.h"
#include "Spring.h"

 // your system should at least contain 8x8 particles.
const int W = 8;
const int H = 8;
const int NUM_PARTICLES = 9;
const double D = -0.16;
const double OS = 0.4;
const double BALL_MASS = .2;
const double GRAVITY = 9.8;
const double DRAG_COEFF = 0.6;
const double LOFT = 0.15;
const double RL = 0.16;

const double structural = 40;
const double shear = 30;
const double flex = 30;


const double SQRT2 = 1.41421356237;
std::vector<Spring> clothSprings;
int clothSize;

ClothSystem::ClothSystem()
{
    // TODO 5. Initialize m_vVecState with cloth particles. 
    // You can again use rand_uniform(lo, hi) to make things a bit more interesting

}

int getIndex(int col, int row) {
    return row * clothSize + col;
}

ClothSystem::ClothSystem(int size) {
    clothSize = size;
    for (int r = 0; r < size; ++r) {
        for (int c = 0; c < size; ++c) {
            m_vVecState.push_back(Vector3f(0, 0, 0));    // velocity
            m_vVecState.push_back(Vector3f(r*-D, c*D, c*LOFT));    // position 
        }
    }
    
    for (int r = 0; r < size; ++r) {
        for (int c = 0; c < size; ++c) {
            int index = getIndex(c, r);

            if (c != size - 1){
                clothSprings.push_back(Spring(index, getIndex(c+1, r), RL, structural));
            }
            if (c != size - 1 && r != 0){
                clothSprings.push_back(Spring(index, getIndex(c+1,r-1), RL*SQRT2, shear));
            }
            if (c < size - 2){
                clothSprings.push_back(Spring(index, getIndex(c+2, r), RL*2, flex));
            }
            if (c != size - 1 && r != size - 1){
                clothSprings.push_back(Spring(index, getIndex(c+1, r+1), RL*SQRT2, shear));
            }
            if (r != size - 1){
                clothSprings.push_back(Spring(index, getIndex(c, r+1), RL, structural));
            }
            if (r < size - 2){
                clothSprings.push_back(Spring(index, getIndex(c, r+2), RL*2, flex));
            }
        }
    }
}

std::vector<Vector3f> ClothSystem::evalF(std::vector<Vector3f> state)
{
    std::vector<Vector3f> f(state.size());
    // TODO 5. implement evalF
    // - gravity
    // - viscous drag
    // - structural springs
    // - shear springs
    // - flexion springs
     
    int i = 0;
    for (Vector3f v : state) {
        if (i % 2 == 0) {
            //even => velocity, return acceleration
            Vector3f gravityForce = Vector3f(0, -BALL_MASS * GRAVITY, 0);
            Vector3f viscousForce = Vector3f(-DRAG_COEFF * v.x(), -DRAG_COEFF * v.y(), -DRAG_COEFF * v.z());
            Vector3f springForce = Vector3f(0, 0, 0);
            for (Spring spring : clothSprings) {
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
    for (int j = 0; j < clothSize; ++j) {
        f[j*2] = Vector3f(0, 0, 0);
        f[j*2 + 1] = Vector3f(0, 0, 0);
    }
    return f;
}


void ClothSystem::draw(GLProgram& gl)
{
    //TODO 5: render the system 
    //         - ie draw the particles as little spheres
    //         - or draw the springs as little lines or cylinders
    //         - or draw wireframe mesh

    const Vector3f CLOTH_COLOR(0.9f, 0.9f, 0.9f);
    gl.updateMaterial(CLOTH_COLOR);

    for (int i = 0; i < m_vVecState.size()/2; ++i) {
        gl.updateModelMatrix(Matrix4f::translation(m_vVecState[i * 2 + 1]));
        drawSphere(0.075f, 10, 10);
    } 

    gl.disableLighting();
    gl.updateModelMatrix(Matrix4f::identity()); // update uniforms after mode change
    VertexRecorder rec;
    for (int i = 0; i < clothSprings.size(); ++i) {
        int index1 = clothSprings[i].getP1();
        int index2 = clothSprings[i].getP2();
        rec.record(m_vVecState[index1*2+1], CLOTH_COLOR);
        rec.record(m_vVecState[index2*2+1], CLOTH_COLOR);
    }
    glLineWidth(3.0f);
    rec.draw(GL_LINES);
    gl.enableLighting(); // reset to default lighting model
}

