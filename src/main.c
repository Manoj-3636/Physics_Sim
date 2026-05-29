#include <stdio.h>
#include <stdlib.h>

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



    BodyList body_list = SetupSpringPendulum();
    SpringList spring_list ={ malloc(sizeof(Spring) * 2),2};
    spring_list.springs[0] = (Spring){
        &body_list.bodies[0],
        &body_list.bodies[1],
        20,
        25
    };

    spring_list.springs[1] = (Spring){
        &body_list.bodies[1],
        &body_list.bodies[2],
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