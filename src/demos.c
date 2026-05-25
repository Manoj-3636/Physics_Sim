#include "demos.h"

#include <stdlib.h>

BodyList SetupMovingBlock() {
    Body *bodies = malloc(sizeof(Body));

    bodies[0] = (Body){
        SHAPE_CIRCLE,
        {50, 50},
        {100, 100},
        {200, 0}
    };

    return (BodyList){bodies, 1};
}
