#ifndef PHYSICS_H
#define PHYSICS_H

#include <raylib.h>
#include <raymath.h>

typedef struct {
    Vector2 size;
    Vector2 position;
    Vector2 velocity;
} Body;

typedef struct {
    Body* bodies;
    int size;
} BodyList;

void UpdatePosition(BodyList body_list,float dt);

#endif