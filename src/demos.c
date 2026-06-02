#include "demos.h"

#include <stdlib.h>
#include <math.h>

// BodyList SetupMovingBlock() {
//     RigidBody *bodies = malloc(sizeof(RigidBody));
//
//     bodies[0] = (RigidBody){
//         SHAPE_CIRCLE,
//         {50, 50},
//         {100, 100},
//         {200, 0}
//     };
//
//     return (BodyList){bodies, 1};
// }

World* SetupSpringPendulum() {
    World* world = malloc(sizeof(World));
    
    // Setup bodies
    RigidBody *bodies = malloc(sizeof(RigidBody) * 3);

    bodies[0] = (RigidBody){
        SHAPE_CIRCLE,
        0.0f,
        {1,1},
        {800,300},
        {0,0},
        {0,0}
    };

    bodies[1] = (RigidBody){
        SHAPE_CIRCLE,
        2.0f,
        {25,25},
        {800,325},
        {200,0},
        {0,0}
    };

    bodies[2]= (RigidBody){
        SHAPE_CIRCLE,
        2.0f,
        {25,25},
        {800,325},
        {100,0},
        {0,0}
    };

    world->body_list = (BodyList){bodies, 3};
    
    // Setup springs
    Spring* springs = malloc(sizeof(Spring) * 2);
    
    springs[0] = (Spring){
        &world->body_list.bodies[0],
        &world->body_list.bodies[1],
        70,
        25,
        5.0f
    };

    springs[1] = (Spring){
        &world->body_list.bodies[1],
        &world->body_list.bodies[2],
        20,
        25,
        5.0f
    };
    
    world->spring_list = (SpringList){springs, 2};
    
    return world;
}

World* SetupClothSimulation() {
    World* world = malloc(sizeof(World));
    
    int rows = 6;
    int cols = 6;
    int num_bodies = rows * cols;
    
    float spacing = 50.0f;
    float startX = 975.0f;
    float startY = 100.0f;
    
    RigidBody* bodies = malloc(sizeof(RigidBody) * num_bodies);
    
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            int idx = r * cols + c;
            float mass = (r == 0) ? 0.0f : 1.0f;
            
            bodies[idx] = (RigidBody){
                SHAPE_CIRCLE,
                mass,
                {15, 15},
                {startX + c * spacing, startY + r * spacing},
                {0, 0},
                {0, 0}
            };
        }
    }
    
    world->body_list = (BodyList){bodies, num_bodies};
    
    int horiz = rows * (cols - 1);
    int vert  = (rows - 1) * cols;
    int diag  = (rows - 1) * (cols - 1);
    int num_springs = horiz + vert + diag + diag;
    
    Spring* springs = malloc(sizeof(Spring) * num_springs);
    int s = 0;
    
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols - 1; c++) {
            int i = r * cols + c;
            int j = r * cols + (c + 1);
            springs[s++] = (Spring){
                &world->body_list.bodies[i],
                &world->body_list.bodies[j],
                2500,
                spacing,
                10.0f
            };
        }
    }
    
    for (int r = 0; r < rows - 1; r++) {
        for (int c = 0; c < cols; c++) {
            int i = r * cols + c;
            int j = (r + 1) * cols + c;
            springs[s++] = (Spring){
                &world->body_list.bodies[i],
                &world->body_list.bodies[j],
                2500,
                spacing,
                10.0f
            };
        }
    }
    
    for (int r = 0; r < rows - 1; r++) {
        for (int c = 0; c < cols - 1; c++) {
            int i = r * cols + c;
            int j = (r + 1) * cols + (c + 1);
            springs[s++] = (Spring){
                &world->body_list.bodies[i],
                &world->body_list.bodies[j],
                2000,
                spacing * sqrtf(2.0f),
                8.0f
            };
        }
    }
    
    for (int r = 0; r < rows - 1; r++) {
        for (int c = 1; c < cols; c++) {
            int i = r * cols + c;
            int j = (r + 1) * cols + (c - 1);
            springs[s++] = (Spring){
                &world->body_list.bodies[i],
                &world->body_list.bodies[j],
                2000,
                spacing * sqrtf(2.0f),
                8.0f
            };
        }
    }
    
    world->spring_list = (SpringList){springs, num_springs};
    
    return world;
}
