#ifndef SNAKEENTITY_H__
#define SNAKEENTITY_H__
#include <stdio.h>
#include "..\include\raylib.h"
#include "..\include\raymath.h"

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

void Snake_Move(Context *ctx, SnakeEntity *snake, Vector2 moveAxis) {
    Vector2 *bodies = snake->bodies;
    Vector2 *posptr = Snake_Head(snake);
    Vector2 oldpos = *posptr;
    *posptr = Vector2Add(*posptr, moveAxis);
    for (int i = 1; i < snake->bodycount; i++) {
        Vector2 tmp = bodies[i];
        bodies[i] = oldpos;
        oldpos = tmp;
    }
    // if (Snake_Head(snake)->x > ctx->gridWidth || Snake_Head(snake)->x < ctx->gridWidth ||
    //     Snake_Head(snake)->y > ctx->gridHeight || Snake_Head(snake)->y < ctx->gridHeight) {

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
