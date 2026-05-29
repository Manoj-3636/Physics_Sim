//
// Created by manoj on 5/29/26.
//

#ifndef STATS_H
#define STATS_H
#include "world.h"

typedef  struct {
    int fps;
} Stats;

Stats* InitializeStats(World *w);
void UpdateStats(Stats* s,World* w);

#endif //STATS_H
