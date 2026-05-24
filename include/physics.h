#ifndef PHYSICS_H
#define PHYSICS_H

#include <raylib.h>
#include <raymath.h>

typedef struct {
    Vector2 size;
    Vector2 position;
    Vector2 velocity;
} Body;

void UpdatePosition(Body *bodies,int count,float dt);

#endif