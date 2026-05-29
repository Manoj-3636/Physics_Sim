//
// Created by manoj on 5/29/26.
//

#ifndef WORLD_H
#define WORLD_H

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

typedef struct {
    BodyList body_list;
    SpringList spring_list;
} World;

#endif //WORLD_H
