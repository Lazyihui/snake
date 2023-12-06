#ifndef SNAKEENTITY_H__
#define SNAKEENTITY_H__
#include <stdio.h>
#include "..\include\raylib.h"
#include "..\include\raymath.h"

typedef struct SnakeEntity {

    Vector2 pos;
    Color color;
    float interval;
    float size;
    Vector2 bodies[40 * 40];
    int bodycount;

} SnakeEntity;

void Snake_Move(SnakeEntity *snake, Vector2 moveAxis) {
    Vector2 *posptr = &snake->pos;
    *posptr = Vector2Add(*posptr, moveAxis);
}

void Snake_Draw(SnakeEntity *snake) {
    float size = snake->size;
    Vector2 pos = snake->pos;
    pos = Vector2Scale(pos, size);
    DrawRectangleV(pos, (Vector2){size, size}, snake->color);
}
#endif

