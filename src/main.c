#include <stdio.h>
#include <stdlib.h>

#include "physics.h"
#include "render.h"
#include "demos.h"




int main() {
    InitWindow(1600,980,"Physics Simulation");
    int monitor = GetCurrentMonitor();

    BodyList body_list = SetupSpringPendulum();
    SpringList spring_list ={ malloc(sizeof(Spring)),1};
    spring_list.springs[0] = (Spring){
        &body_list.bodies[0],
        &body_list.bodies[1],
        20,
        25
    };
    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        BeginDrawing();
        ClearBackground(BLACK);
        ResetNetForce(body_list);
        ApplyGravity(body_list);
        ApplySpringForce(spring_list);
        UpdateVelocity(body_list,dt);
        UpdatePosition(body_list,dt);
        RenderBodies(body_list);
        EndDrawing();
    }

    DestroyBodyList(body_list);
    free(spring_list.springs);
    spring_list.springs = NULL;
    CloseWindow();
    return 0;
}