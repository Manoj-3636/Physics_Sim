#include <stdio.h>
#include <stdlib.h>

#include "world.h"
#include "physics.h"
#include "render.h"
#include "demos.h"
#include "stats.h"


int main() {
    InitWindow(2200,1200,"Physics Simulation");
    SetTargetFPS(120);
    //TODO make the whole structure better
    //Make a ui element on the top left of the window that shows total energy initial energy and fps and
    // other statistics
    Stats* stats = InitializeStats();
    World* world = SetupSpringPendulum();

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();


        ResetNetForces(world);
        ComputeNetForces(world);
        StepSymplecticEuler(world,dt);
        UpdateStats(stats,world);

        BeginDrawing();
        ClearBackground(BLACK);
        RenderWorld(world);
        RenderStatsHUD(stats);
        EndDrawing();
    }

    DestroyWorld(world);
    CloseWindow();
    return 0;
}
