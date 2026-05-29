#include "render.h"

void RenderBodies(World* w) {
    BodyList body_list = w->body_list;
    for (int i = 0;i<body_list.size;i++) {
        RigidBody b = body_list.bodies[i];
        if (b.shape == SHAPE_RECT)
            DrawRectangleV(b.position,b.size,RED);
        else if (b.shape == SHAPE_CIRCLE)
            DrawCircleV(b.position,b.size.x,RED);
    }
}
