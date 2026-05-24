#include "physics.h"

void UpdatePosition(BodyList body_list, float dt) {
    for (int i = 0;i<body_list.size;i++) {
        // bodies[i].position.x += bodies[i].velocity.x * dt;
        // bodies[i].position.y += bodies[i].velocity.y * dt;
        Body *bodies = body_list.bodies;
        bodies[i].position = Vector2Add(bodies[i].position,Vector2Scale(bodies[i].velocity,dt));
    }
}
