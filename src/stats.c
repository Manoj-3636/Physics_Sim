//
// Created by manoj on 5/29/26.
//
#include "stats.h"

#include <physics.h>
#include <raylib.h>
#include <raymath.h>
#include <stdlib.h>

#include "world.h"

float GetWorldEnergy(World* w);

void UpdateStats(Stats* s,World* w) {
    s->fps = GetFPS();
    s->curr_energy = GetWorldEnergy(w);
}

Stats* InitializeStats(World* w) {
    Stats* s = malloc(sizeof(Stats));
    s->initial_energy = GetWorldEnergy(w);
    return s;
}

float GetWorldEnergy(World* w) {
    float energy = 0;

    for (int i = 0;i<w->body_list.size;i++) {
        RigidBody b =  w->body_list.bodies[i];
        energy += 0.5f * b.mass * pow(Vector2Length(b.velocity),2);
        energy += -1 *  b.mass * GRAVITY * b.position.y;
    }

    for (int i = 0;i<w->spring_list.size;i++) {
        Spring s = w->spring_list.springs[i];
        float x = Vector2Length(Vector2Subtract(s.anchor1->position,s.anchor2->position)) - s.rest_length;
        energy += 0.5f * s.stiffness * pow(x,2);
    }

    return energy;
}