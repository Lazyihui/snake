#ifndef CONTEXT_H__
#define CONTEXT_H__
#include "InputEntity.h"
#include "SnakeEntity.h"
#include "FoodEntity.h"
#include "Common.h"

typedef struct Context {

    InputEntity input;

    SnakeEntity snake;
    int snakelongth;
    float snakeMoveTimer;
    float snakeMoveInterval;

    FoodEntity foods[10];
    int foodCount;

} Context;

void ContextInit(Context *ctx) {
    

    ctx->snakeMoveTimer=0.2;
    ctx->snakeMoveInterval=0.2;
    ctx->snakelongth=1;
    SnakeEntity *snake = &ctx->snake;
    snake->color = RED;
    snake->size = 15;
    snake->pos.x = 0;
    snake->pos.y = 0;
    snake->interval = 15;

    ctx->foodCount=1;
    FoodEntity *foods = &ctx->foods[0];
    foods->color = GRAY;
    foods->pos = GetVecort_Rand();
    foods->radius = 10;

}

#endif