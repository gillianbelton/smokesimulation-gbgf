#include "timestepper.h"

#include <cstdio>

void ForwardEuler::takeStep(ParticleSystem* particleSystem, float stepSize)
{
    // particle system has (x, y, z) coordinates
	// calling evalF(state) will get the first deriv at that point. 
	// so you get the first deriv, and then multiply by (h) stepsize
	// and add it to the orignal particle system, and re-set it.

	std::vector<Vector3f> dX = particleSystem->evalF(particleSystem->getState());
	std::vector<Vector3f> newState(particleSystem->getState().size());
	int i = 0;
	// if (dX.size() == 4){
	// 	printf("DX accel: \n");
	// 	dX[2].print();
	// 	printf("DX velocity: \n");
	// 	dX[3].print();
	// }

	for (Vector3f particle : particleSystem->getState()) {
		Vector3f delta = stepSize * dX[i];
		newState[i] = (delta + particle);
		++i;
	}
	particleSystem->setState(newState);
}

void Trapezoidal::takeStep(ParticleSystem* particleSystem, float stepSize)
{
	std::vector<Vector3f> f0 = particleSystem->evalF(particleSystem->getState());
	std::vector<Vector3f> f1 = std::vector<Vector3f>();
	std::vector<Vector3f> newState = std::vector<Vector3f>();
	int i = 0;
	for (Vector3f particle : particleSystem->getState()) {
		f1.push_back(particle + stepSize * f0[i]);
		++i;
	}
	f1 = particleSystem->evalF(f1);
	i = 0;
	for (Vector3f particle : particleSystem->getState()) {
		newState.push_back(particle + stepSize/2 * (f0[i] + f1[i]));
		++i;
	}
	particleSystem->setState(newState);
}


void RK4::takeStep(ParticleSystem* particleSystem, float stepSize)
{
	int numStates = particleSystem->getState().size();
	std::vector<Vector3f> particles = particleSystem->getState();
	std::vector<Vector3f> k1 = particleSystem->evalF(particleSystem->getState());
	std::vector<Vector3f> k2 = std::vector<Vector3f>();
	std::vector<Vector3f> k3 = std::vector<Vector3f>();
	std::vector<Vector3f> k4 = std::vector<Vector3f>();
	std::vector<Vector3f> newState = std::vector<Vector3f>();

	// printf("numStates = %i\n", numStates);
	for (int i = 0; i < numStates; ++i) {
		k2.push_back(particles[i] + stepSize/2.0 * k1[i]);
	}
	k2 = particleSystem->evalF(k2);
	for (int i = 0; i < numStates; ++i) {
		k3.push_back(particles[i] + stepSize/2.0 * k2[i]);
	}
	k3 = particleSystem->evalF(k3);
	for (int i = 0; i < numStates; ++i) {
		k4.push_back(particles[i] + stepSize * k3[i]);
	}
	k4 = particleSystem->evalF(k4);
	for (int i = 0; i < numStates; ++i) {
		newState.push_back(particles[i] + stepSize/6.0 * (k1[i] + 2.0 * k2[i] + 2.0 * k3[i] + k4[i]));
	}
	particleSystem->setState(newState);
}

