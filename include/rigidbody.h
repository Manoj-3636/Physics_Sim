//
// Created by manoj on 5/28/26.
//

#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include <raylib.h>

typedef enum {
    SHAPE_CIRCLE,
    SHAPE_RECT,
} Shape;

typedef struct {
    Shape shape;
    float mass; // For fixed use mass as 0.0f
    Vector2 size;
    Vector2 position;
    Vector2 velocity;
    Vector2 net_force;
} RigidBody;


#endif //RIGIDBODY_H
