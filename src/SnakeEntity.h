#ifndef SNAKEENTITY_H__
#define SNAKEENTITY_H__
#include <stdio.h>
#include "..\include\raylib.h"
#include "..\include\raymath.h"
typedef struct SnakeEntity {

    Vector2 pos;
    Color color;
    float speed;
    float width;
    float hight;

} SnakeEntity;



void Snake_Move(SnakeEntity *snake, Vector2 moveAxis, float dt) {
    Vector2 *posptr = &snake->pos;
    Vector2 offset = Vector2Normalize(moveAxis);
    offset = Vector2Scale(offset, snake->speed * dt);
    *posptr = Vector2Add(*posptr, offset);
    //////////////////////////////////////////////////////////////////////边界/////////////有问题
    if (posptr->x >= 800) {
        posptr->x = 800;
    }
    if (posptr->x <= 0) {
        posptr->x = 0;
    }
    if (posptr->y >= 450) {
        posptr->y = 450;
    }
    if (posptr->y <= 0) {
        posptr->y = 0;
    }
}




void Snake_Draw(SnakeEntity *snake){
    DrawRectangle(snake->pos.x,snake->pos.y,snake->width,snake->hight,snake->color);
}
#endif



/// 长度？ 就是画一条线
