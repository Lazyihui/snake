#ifndef SNAKEENTITY_H__
#define SNAKEENTITY_H__
#include <stdio.h>
#include "..\include\raylib.h"
#include "..\include\raymath.h"
#include "Context.h"

typedef struct SnakeEntity {
    Color color;
    Vector2 bodies[40 * 40];
    int bodycount;
} SnakeEntity;

Vector2 *Snake_Head(SnakeEntity *snake) {
    return &snake->bodies[0];
}

void Snake_Eat(SnakeEntity *snake) {
    snake->bodycount += 1;
    snake->bodies[snake->bodycount - 1] = snake->bodies[snake->bodycount - 2];
}

void Snake_Move(SnakeEntity *snake, Vector2 moveAxis, int gridWidth, int gridHeight) {
    Vector2 *bodies = snake->bodies;
    Vector2 *posptr = Snake_Head(snake);
    Vector2 nextPos = Vector2Add(*posptr, moveAxis);
    if (nextPos.x < 0 || nextPos.x > gridWidth - 1) {
        return;
    }
    if (nextPos.y < 0 || nextPos.y > gridWidth - 1) {
        return;
    }
    // move
    Vector2 oldpos = *posptr;
    *posptr = nextPos;

    for (int i = 1; i < snake->bodycount; i++) {
        Vector2 tmp = bodies[i];
        bodies[i] = oldpos;
        oldpos = tmp;
    } //

    // if (posptr->x > gridWidth - 1) {
    //     posptr->x = gridWidth - 1;
    // } else if (posptr->x < 0) {
    //     posptr->x = 0;
    // }
    // if (posptr->y > gridHeight - 1) {
    //     posptr->y = gridHeight - 1;
    // } else if (posptr->y < 0) {
    //     posptr->y = 0;
    // }
}

// 逻辑和表现分离
void Snake_Draw(SnakeEntity *snake, Vector2 startPos, int size) {
    for (int i = 0; i < snake->bodycount; i++) {
        Vector2 pos = snake->bodies[i];
        pos = Vector2Scale(pos, size);
        pos = Vector2Add(pos, startPos);
        DrawRectangleV(pos, (Vector2){size, size}, snake->color);
    }
}

#endif
