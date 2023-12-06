#ifndef CONTEXT_H__
#define CONTEXT_H__
#include "InputEntity.h"
#include "SnakeEntity.h"
#include "FoodEntity.h"
#include "Common.h"

typedef struct Context {

    InputEntity input;

    SnakeEntity snake;

    FoodEntity foods[10];
    int foodCount;

} Context;

void ContextInit(Context *ctx) {

    SnakeEntity *snake = &ctx->snake;
    snake->color = RED;
    snake->hight = 15;
    snake->width = 15;
    snake->pos.x = 400;
    snake->pos.y = 200;
    snake->speed = 150;

    ctx->foodCount=1;
    FoodEntity *foods = &ctx->foods[0];
    foods->color = GRAY;
    foods->pos = GetVecort_Rand();
    foods->radius = 10;
}

#endif