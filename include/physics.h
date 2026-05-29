#ifndef PHYSICS_H
#define PHYSICS_H

#include "world.h"

void DestroyBodyList(BodyList list);

void DestroyWorld(World* world);

void UpdatePosition(BodyList body_list,float dt);

void ApplySpringForce(World* world);

void ApplyGravity(World* world);

void UpdateVelocity(BodyList body_list,float dt) ;

void ResetNetForce(BodyList body_list);
#endif
