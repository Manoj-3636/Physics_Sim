#ifndef PHYSICS_H
#define PHYSICS_H

#include "rigidbody.h"

typedef struct {
    RigidBody* anchor1;
    RigidBody* anchor2;
    float stiffness;
    float rest_length;
} Spring;

typedef struct {
    RigidBody* bodies;
    int size;
} BodyList;

typedef struct {
    Spring* springs;
    int size;
} SpringList;

void DestroyBodyList(BodyList list);

void UpdatePosition(BodyList body_list,float dt);

void ApplySpringForce(SpringList spring_list);

void ApplyGravity(BodyList body_list);

void UpdateVelocity(BodyList body_list,float dt) ;

void ResetNetForce(BodyList body_list);
#endif