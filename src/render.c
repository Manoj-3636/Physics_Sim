#include "render.h"

#include "stats.h"

void RenderWorld(World *w) {
    for (int i = 0; i < w->body_list.size; i++) {
        RigidBody b = w->body_list.bodies[i];
        if (b.shape == SHAPE_RECT)
            DrawRectangleV(b.position, b.size,RED);
        else if (b.shape == SHAPE_CIRCLE)
            DrawCircleV(b.position, b.size.x,RED);
    }
}

void RenderStatsHUD(Stats *s) {
    int x = 10, y = 10;
    int width = 300, height = 150;
    int font_size = 30;
    int padding = 12;

    // Background rectangle
    // Text
    DrawText(TextFormat("FPS: %d", s->fps), x + padding, y + padding, font_size, GREEN);
}
