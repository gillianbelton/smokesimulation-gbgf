#ifndef FLUIDSYSTEM_H
#define FLUIDSYSTEM_H

#include <vector>
#include <vecmath.h>
#include <cstdint>
#include "particlesystem.h"

// helper for uniform distribution
float rand_uniform(float low, float hi);

struct GLProgram;
class FluidSystem
{
public:

    //TODO: create fluidsystem representation

    virtual ~FluidSystem() {}

    // for a given state, evaluate derivative f(X,t)
    virtual std::vector<Vector3f> evalF(std::vector<Vector3f> state) = 0;

    // getter method for the system's state
    std::vector<Vector3f> getState() { return m_vVecState; };

    // setter method for the system's state
    void setState(const std::vector<Vector3f>  & newState) { m_vVecState = newState; };

 protected:
    std::vector<Vector3f> m_vVecState;
};

#endif
