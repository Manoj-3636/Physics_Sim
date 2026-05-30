#include "render.h"

#include <math.h>
#include <raymath.h>

#include "stats.h"
#define TURNS 16

void DrawSpring(Spring s);
void RenderWorld(World *w) {
    for (int i = 0; i < w->body_list.size; i++) {
        RigidBody b = w->body_list.bodies[i];
        if (b.shape == SHAPE_RECT)
            DrawRectangleV(b.position, b.size,RED);
        else if (b.shape == SHAPE_CIRCLE)
            DrawCircleV(b.position, b.size.x,RED);
    }

    for (int i = 0;i<w->spring_list.size;i++) {
        DrawSpring(w->spring_list.springs[i]);
    }
}

void DrawSpring(Spring s) {
    Vector2 a = s.anchor1->position;
    Vector2 b = s.anchor2->position;

    Vector2 dirn = Vector2Subtract(b,a);
    float length = Vector2Length(dirn);
    dirn = Vector2Normalize(dirn);
    Vector2 perp = (Vector2) {-1 * dirn.y,dirn.x};

    float radius = 10.0f;
    float stepLength = length/TURNS;
    Vector2 points[TURNS];

    for (int i = 0;i<TURNS;i++) {
        int side = (i%2) ? -1 : 1;
        points[i] =Vector2Add(Vector2Add(Vector2Scale(dirn,i*stepLength),a), Vector2Scale(perp,side*radius));
    }

    DrawLineStrip(points,sizeof(points)/sizeof(Vector2),WHITE);
    DrawLineV(a,points[0],WHITE);
    DrawLineV(b,points[TURNS - 1],WHITE);
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
