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
    float foodSpawnTimer;
    float foodSpawnInterval;

} Context;

void ContextInit(Context *ctx) {

    ctx->snakeMoveTimer = 0.2;
    ctx->snakeMoveInterval = 0.2;
    ctx->snakelongth = 1;
    SnakeEntity *snake = &ctx->snake;
    snake->color = RED;
    snake->size = 15;
    snake->bodycount = 1;

    ctx->foodCount=0;
    ctx->foodSpawnInterval=5;
    ctx->foodSpawnTimer=5;
}

#endif