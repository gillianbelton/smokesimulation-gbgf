#ifndef SPRING_H
#define SPRING_H

#include <vector>

#include "particlesystem.h"

class Spring {
    // const double SPRING_STIFFNESS = 100.0;
    // const double SPRING_REST_LENGTH = 0.3;

    protected:
        int particle1, particle2;
        double stiffness;
        double restLength;
    public:
        Spring(int index1, int index2, double restL, double stiff);
        int getP1 ();
        int getP2 ();
        Vector3f getForce(Vector3f distance);
};

#endif
