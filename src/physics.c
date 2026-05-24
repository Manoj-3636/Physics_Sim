#include "physics.h"

void UpdatePosition(Body *bodies, int count, float dt) {
    for (int i = 0;i<count;i++) {
        // bodies[i].position.x += bodies[i].velocity.x * dt;
        // bodies[i].position.y += bodies[i].velocity.y * dt;
        bodies[i].position = Vector2Add(bodies[i].position,Vector2Scale(bodies[i].velocity,dt));
    }
}
