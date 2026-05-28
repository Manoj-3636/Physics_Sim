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

BodyList SetupSpringPendulum() {
    RigidBody *bodies = malloc(sizeof(RigidBody) * 2);

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

    return (BodyList){bodies,2};
}
