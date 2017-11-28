#ifndef INTEGRATOR_H
#define INTEGRATOR_H

#include "vecmath.h"
#include <vector>
#include "particlesystem.h"
#include "fluidsystem.h"

class FluidStepper
{
public:
    virtual ~FluidStepper() {}
	virtual void takeStep(FluidSystem* fluidSystem, float stepSize) = 0;
};

//IMPLEMENT YOUR TIMESTEPPERS

class StamMethod : public FluidStepper
{
	void takeStep(FluidSystem* fluidSystem, float stepSize) override;
};

/////////////////////////
#endif
