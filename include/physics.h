#ifndef PHYSICS_H
#define PHYSICS_H

#include "world.h"

void DestroyWorld(World* world);

void ComputeNetForces(World* world);

void StepSymplecticEuler(World *w,float dt);

void ResetNetForces(World* w);
#endif
