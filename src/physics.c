#include "physics.h"

#include <stdlib.h>
#include <raymath.h>

float getSpringExtension(Spring spring);


void StepSymplecticEuler(World *w,float dt) {
    RigidBody *bodies = w->body_list.bodies;
    for (int i = 0;i<w->body_list.size;i++) {
        if (bodies[i].mass <= 0.0f) continue;
        bodies[i].velocity = Vector2Add(bodies[i].velocity,Vector2Scale(bodies[i].net_force,dt/bodies[i].mass));
    }

    for (int i = 0;i<w->body_list.size;i++) {
        if (bodies[i].mass <= 0.0f) continue;
        bodies[i].position = Vector2Add(bodies[i].position,Vector2Scale(bodies[i].velocity,dt));
    }
}

void ResetNetForces(World *w) {
    for (int i = 0; i < w->body_list.size; i++) {
        w->body_list.bodies[i].net_force = (Vector2){0.0f,0.0f};
    }
}

void ApplySpringForce(World* w) {
    for (int i = 0; i < w->spring_list.size; i++) {
        Spring currSpring = w->spring_list.springs[i];
        float length = getSpringExtension(currSpring);
        if (length < 1e-6f) continue;

        Vector2 dirn = Vector2Normalize(Vector2Subtract(currSpring.anchor2->position, currSpring.anchor1->position));

        float force_mag = (length - currSpring.rest_length) * currSpring.stiffness;
        RigidBody* anchor1 = currSpring.anchor1;
        RigidBody* anchor2 = currSpring.anchor2;

        Vector2 force_vector = Vector2Scale(dirn, force_mag);

        anchor1->net_force = Vector2Add(anchor1->net_force, force_vector);
        anchor2->net_force = Vector2Add(anchor2->net_force, Vector2Negate(force_vector));

        // --- axial damping ---
        Vector2 relVel = Vector2Subtract(anchor2->velocity, anchor1->velocity);
        float relVelAlongAxis = Vector2DotProduct(relVel, dirn);
        float damp_mag = currSpring.damping * relVelAlongAxis;
        Vector2 damp_vector = Vector2Scale(dirn, damp_mag);

        anchor1->net_force = Vector2Add(anchor1->net_force, damp_vector);
        anchor2->net_force = Vector2Add(anchor2->net_force, Vector2Negate(damp_vector));
    }
}

void ApplyGravity(World* world) {
    for (int i = 0; i < world->body_list.size; i++) {
        world->body_list.bodies[i].net_force = Vector2Add(world->body_list.bodies[i].net_force,(Vector2){0,GRAVITY * world->body_list.bodies[i].mass});
    }
}

float getSpringExtension(Spring spring) {
    Vector2 length_vec = Vector2Subtract(spring.anchor1->position,spring.anchor2->position);
    return Vector2Length(length_vec);
}

void ApplyDrag(World* world) {
    for (int i = 0; i < world->body_list.size; i++) {
        RigidBody* b = &world->body_list.bodies[i];
        if (b->mass <= 0.0f) continue;
        Vector2 drag = Vector2Scale(b->velocity, -DRAG);
        b->net_force = Vector2Add(b->net_force, drag);
    }
}

void ComputeNetForces(World* world) {
    ApplyGravity(world);
    ApplySpringForce(world);
    ApplyDrag(world);
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
