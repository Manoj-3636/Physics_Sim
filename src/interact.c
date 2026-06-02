//
// Created by manoj on 6/2/26.
//

#include "interact.h"



#include "world.h"
#include <raymath.h>
#include <stdlib.h>

bool PointInBody(RigidBody *b,Vector2 p) {
    switch (b->shape) {
        case SHAPE_RECT:
            return CheckCollisionPointRec(p,(Rectangle){b->position.x,b->position.y,b->size.x,b->size.y});
        case SHAPE_CIRCLE:
            return CheckCollisionPointCircle(p,b->position,b->size.x);
        default:
            return false;
    }
}

void GrabHandler(Pointer *p, RigidBody *bodies, int count) {
    Vector2 mouse = GetMousePosition();

    // ── CLICK: find hit body, record grab point ──────────────────────
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        for (int i = 0; i < count; i++) {
            if (PointInBody(&bodies[i], mouse)) {
                p->dragged    = &bodies[i];
                // offset from body center → where on the body you clicked
                p->grabOffset = Vector2Subtract(mouse, bodies[i].position);
                break;
            }
        }
    }

    // ── HOLD: apply spring force every frame ─────────────────────────
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && p->dragged != NULL) {
        // world-space position of the grab point on the body
        Vector2 grabPoint    = Vector2Add(p->dragged->position, p->grabOffset);

        // spring: pull grab point toward mouse
        Vector2 displacement = Vector2Subtract(mouse, grabPoint);
        Vector2 springForce  = Vector2Scale(displacement, p->stiffness);

        // damping: oppose velocity to kill wobble
        Vector2 dampForce    = Vector2Scale(p->dragged->velocity, -p->damping);

        p->dragged->net_force = Vector2Add(
            p->dragged->net_force,
            Vector2Add(springForce, dampForce)
        );

        // draw the spring line
        DrawLineEx(grabPoint, mouse, 2.0f, YELLOW);
        DrawCircleV(mouse, 5.0f, YELLOW);
        DrawCircleV(grabPoint, 4.0f, ORANGE);  // anchor point on body
    }

    // ── RELEASE ───────────────────────────────────────────────────────
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
        p->dragged = NULL;
    }
}


