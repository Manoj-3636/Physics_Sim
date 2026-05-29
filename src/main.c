#include <stdio.h>
#include <stdlib.h>

#include "world.h"
#include "physics.h"
#include "render.h"
#include "demos.h"




int main() {
    InitWindow(1600,980,"Physics Simulation");
    //TODO make the whole structure better
    //First make a world object to hold springs and bodies
    //Next make a ComputeForces on the world and so on, all functions to be called on this world object
    //Have a UpdateWorld(Method) function for ease of switching out the ODE solver
    //Make a ui element on the top left of the window that shows total energy initial energy and fps and
    // other statistics



    World* world = SetupSpringPendulum();
    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        BeginDrawing();
        ClearBackground(BLACK);
        ResetNetForce(world->body_list);
        ApplyGravity(world);
        ApplySpringForce(world);
        UpdateVelocity(world->body_list,dt);
        UpdatePosition(world->body_list,dt);
        RenderBodies(world->body_list);
        EndDrawing();
    }

    DestroyWorld(world);
    CloseWindow();
    return 0;
}
