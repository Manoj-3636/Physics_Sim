#ifndef RENDER_H
#define RENDER_H
    
#include "world.h"
#include <raylib.h>

#include "stats.h"

void RenderWorld(World* w);
void RenderStatsHUD(Stats *s);

#endif
