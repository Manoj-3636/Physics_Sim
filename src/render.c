#include "render.h"

void RenderBodies(BodyList body_list) {
    for (int i = 0;i<body_list.size;i++) {
        Body b = body_list.bodies[i];
        DrawRectangleV(b.position,b.size,RED);
    }
}
