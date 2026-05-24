#include "physics.h"
#include "render.h"

Body bodies[1] = {
    {
        {100,100},
        {0,0},
        {200,0}
    }
};

int main() {
    InitWindow(1600,900,"Physics Simulation");

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        BeginDrawing();
        ClearBackground(BLACK);
        UpdatePosition(bodies,sizeof(bodies)/sizeof(Body),dt);
        RenderBodies(bodies,sizeof(bodies)/sizeof(Body));
        EndDrawing();
    }

    CloseWindow();
    return 0;
}