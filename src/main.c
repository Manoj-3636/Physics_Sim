#include <stdlib.h>

#include "physics.h"
#include "render.h"
#include "demos.h"




int main() {
    InitWindow(1600,900,"Physics Simulation");
    BodyList body_list = SetupMovingBlock();
    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        BeginDrawing();
        ClearBackground(BLACK);
        UpdatePosition(body_list,dt);
        RenderBodies(body_list);
        EndDrawing();
    }

    DestroyBodyList(body_list);
    CloseWindow();
    return 0;
}