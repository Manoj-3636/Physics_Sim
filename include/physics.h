#ifndef PHYSICS_H
#define PHYSICS_H

#include "world.h"

void DestroyBodyList(BodyList list);

void UpdatePosition(BodyList body_list,float dt);

void ApplySpringForce(SpringList spring_list);

void ApplyGravity(BodyList body_list);

void UpdateVelocity(BodyList body_list,float dt) ;

void ResetNetForce(BodyList body_list);
#endif
