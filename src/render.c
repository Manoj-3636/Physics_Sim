#include "render.h"

void RenderBodies(World* w) {
    for (int i = 0; i < w->body_list.size; i++) {
        RigidBody b = w->body_list.bodies[i];
        if (b.shape == SHAPE_RECT)
            DrawRectangleV(b.position,b.size,RED);
        else if (b.shape == SHAPE_CIRCLE)
            DrawCircleV(b.position,b.size.x,RED);
    }
}
