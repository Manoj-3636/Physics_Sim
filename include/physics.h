#ifndef PHYSICS_H
#define PHYSICS_H

#include "world.h"
#define GRAVITY 980.0f
#define DRAG    1.5f

void DestroyWorld(World* world);

void ComputeNetForces(World* world);

void StepSymplecticEuler(World *w,float dt);

void ResetNetForces(World* w);
#endif
