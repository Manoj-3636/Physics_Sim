//
// Created by manoj on 6/2/26.
//

#ifndef INTERACT_H
#define INTERACT_H
#include "world.h"

typedef struct {
    RigidBody *dragged;
    Vector2    grabOffset;  // click point relative to body center
    float      stiffness;   // spring k
    float      damping;     // oscillation damping
} Pointer;

void GrabHandler(Pointer *p, RigidBody *bodies, int count);

#endif //INTERACT_H
