#ifndef PHYSICS_H
#define PHYSICS_H

#include <raylib.h>
#include <raymath.h>

typedef enum {
    SHAPE_CIRCLE,
    SHAPE_RECT,
} Shape;

typedef struct {
    Shape shape;
    Vector2 size;
    Vector2 position;
    Vector2 velocity;
} Body;

typedef struct {
    Body* bodies;
    int size;
} BodyList;

void DestroyBodyList(BodyList list);

void UpdatePosition(BodyList body_list,float dt);

#endif