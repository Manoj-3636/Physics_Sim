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



    World world;
    world.body_list = SetupSpringPendulum();
    world.spring_list = (SpringList){ malloc(sizeof(Spring) * 2), 2 };
    world.spring_list.springs[0] = (Spring){
        &world.body_list.bodies[0],
        &world.body_list.bodies[1],
        20,
        25
    };

    world.spring_list.springs[1] = (Spring){
        &world.body_list.bodies[1],
        &world.body_list.bodies[2],
        20,
        25
    };
    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        BeginDrawing();
        ClearBackground(BLACK);
        ResetNetForce(world.body_list);
        ApplyGravity(world.body_list);
        ApplySpringForce(world.spring_list);
        UpdateVelocity(world.body_list,dt);
        UpdatePosition(world.body_list,dt);
        RenderBodies(world.body_list);
        EndDrawing();
    }

    DestroyBodyList(world.body_list);
    free(world.spring_list.springs);
    world.spring_list.springs = NULL;
    CloseWindow();
    return 0;
}
