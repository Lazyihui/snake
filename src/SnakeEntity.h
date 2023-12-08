#ifndef SNAKEENTITY_H__
#define SNAKEENTITY_H__
#include <stdio.h>
#include "..\include\raylib.h"
#include "..\include\raymath.h"

typedef struct SnakeEntity {

    Color color;
    float size;
    Vector2 bodies[40 * 40];
    int bodycount;

} SnakeEntity;

void Snake_Eat(SnakeEntity *snake) {

    snake->bodycount += 1;
    snake->bodies[snake->bodycount - 1] = snake->bodies[snake->bodycount - 2];
}


void Snake_Move(SnakeEntity *snake, Vector2 moveAxis) {
    Vector2 *bodies = snake->bodies;
    Vector2 *posptr = &bodies[0];
    Vector2 oldpos = *posptr;
    *posptr = Vector2Add(*posptr, moveAxis);
    for (int i = 1; i < snake->bodycount; i++) {
        Vector2 tmp = bodies[i];
        bodies[i] = oldpos;
        oldpos = tmp;
    }
}
// 逻辑和表现分离

void Snake_Draw(SnakeEntity *snake) {
    float size = snake->size;
    for (int i = 0; i < snake->bodycount; i++) {

        Vector2 pos = snake->bodies[i];
        pos = Vector2Scale(pos, size);
        DrawRectangleV(pos,(Vector2){size, size}, snake->color);
    }
}


#endif
