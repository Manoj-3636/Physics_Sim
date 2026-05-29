#include "demos.h"

#include <stdlib.h>

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
        20,
        25
    };

    springs[1] = (Spring){
        &world->body_list.bodies[1],
        &world->body_list.bodies[2],
        20,
        25
    };
    
    world->spring_list = (SpringList){springs, 2};
    
    return world;
}
