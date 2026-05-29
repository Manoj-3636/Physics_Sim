//
// Created by manoj on 5/29/26.
//
#include "stats.h"
#include <raylib.h>
#include <stdlib.h>

#include "world.h"

void UpdateStats(Stats* s,World* w) {
    s->fps = GetFPS();
}

Stats* InitializeStats(World* w) {
    Stats* s = malloc(sizeof(Stats));
    //TODO put initial energy of the system here  
    return s;
}