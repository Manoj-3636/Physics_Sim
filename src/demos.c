#include "demos.h"

#include <stdlib.h>

BodyList SetupMovingBlock() {
    RigidBody *bodies = malloc(sizeof(RigidBody));

    bodies[0] = (RigidBody){
        SHAPE_CIRCLE,
        {50, 50},
        {100, 100},
        {200, 0}
    };

    return (BodyList){bodies, 1};
}
