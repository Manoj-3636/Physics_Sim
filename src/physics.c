#include "physics.h"

#include <stdlib.h>
#include <raymath.h>

float getSpringExtension(Spring spring);

void UpdatePosition(BodyList body_list, float dt) {
    RigidBody *bodies = body_list.bodies;
    for (int i = 0;i<body_list.size;i++) {
        if (bodies[i].mass <= 0.0f) continue;
        bodies[i].position = Vector2Add(bodies[i].position,Vector2Scale(bodies[i].velocity,dt));
    }
}

void UpdateVelocity(BodyList body_list,float dt) {
    RigidBody *bodies = body_list.bodies;
    for (int i = 0;i<body_list.size;i++) {
        if (bodies[i].mass <= 0.0f) continue;
        bodies[i].velocity = Vector2Add(bodies[i].velocity,Vector2Scale(bodies[i].net_force,dt/bodies[i].mass));
    }
}

void ResetNetForce(BodyList body_list) {
    for (int i = 0;i<body_list.size;i++) {
        body_list.bodies[i].net_force = (Vector2){0.0f,0.0f};
    }
}

void ApplySpringForce(World* world) {
    SpringList spring_list = world->spring_list;
    for (int i = 0;i<spring_list.size;i++) {
        Spring currSpring = spring_list.springs[i];
        float length = getSpringExtension(currSpring);
        if (length < 1e-6f) continue;


        float force_mag = (length - currSpring.rest_length) * currSpring.stiffness;
        RigidBody* anchor1 = currSpring.anchor1;
        RigidBody* anchor2 = currSpring.anchor2;

        Vector2 force_vector = Vector2Scale(Vector2Normalize(Vector2Subtract(anchor2->position,anchor1->position)),force_mag);

        anchor1->net_force = Vector2Add(anchor1->net_force,force_vector);
        anchor2->net_force = Vector2Add(anchor2->net_force,Vector2Negate(force_vector));
    }
}

void ApplyGravity(World* world) {
    BodyList body_list = world->body_list;
    for (int i = 0;i<body_list.size;i++) {
        body_list.bodies[i].net_force = Vector2Add(body_list.bodies[i].net_force,(Vector2){0,980.0f * body_list.bodies[i].mass});
    }
}

float getSpringExtension(Spring spring) {
    Vector2 length_vec = Vector2Subtract(spring.anchor1->position,spring.anchor2->position);
    return Vector2Length(length_vec);
}

void DestroyBodyList(BodyList list) {
    free(list.bodies);

    list.bodies = NULL;
    list.size = 0;
}

void DestroyWorld(World* world) {
    if (world == NULL) return;
    
    free(world->body_list.bodies);
    world->body_list.bodies = NULL;
    world->body_list.size = 0;
    
    free(world->spring_list.springs);
    world->spring_list.springs = NULL;
    world->spring_list.size = 0;
    
    free(world);
}
