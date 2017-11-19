
#include "Spring.h"
#include <cassert>
#include <stdlib.h>


Spring::Spring(int index1, int index2, double restL, double stiff) {
    particle1 = index1;
    particle2 = index2;
    restLength = restL;
    stiffness = stiff;
}

int Spring::getP1 () {
  return particle1;
}

int Spring::getP2 () {
  return particle2;
}

Vector3f Spring::getForce(Vector3f distance) {
    Vector3f force = (distance.abs() - restLength) * -stiffness / (distance.abs()) * distance;
    return force;
}