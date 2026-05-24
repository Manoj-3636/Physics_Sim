#include "physics.h"
#include "render.h"

Body bodies[1] = {
    {
        {100,100},
        {0,0},
        {200,0}
    }
};

BodyList body_list = {bodies,1};

int main() {
    InitWindow(1600,900,"Physics Simulation");

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        BeginDrawing();
        ClearBackground(BLACK);
        UpdatePosition(body_list,dt);
        RenderBodies(body_list);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}