#include "render.h"

void RenderBodies(Body *bodies, int count) {
    for (int i = 0;i<count;i++) {
        Body b = bodies[i];
        DrawRectangleV(b.position,b.size,RED);
    }
}
