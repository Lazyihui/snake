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

    FoodEntity foods[100];
    int foodCount;
    float foodSpawnTimer;
    float foodSpawnInterval;

    Vector2 startPos;
    int windowWidth;
    int windowHeight;
    int gridWidth; // 棋盘宽
    int gridHeight;
    int cellDrawSize; // 每格尺寸
} Context;

void ContextInit(Context *ctx) {

    ctx->snakeMoveTimer = 0.2;
    ctx->snakeMoveInterval = 0.2;
    ctx->snakelongth = 1;
    SnakeEntity *snake = &ctx->snake;
    snake->color = RED;
    snake->bodycount = 1;

    ctx->foodCount = 0;
    ctx->foodSpawnInterval = 4;
    ctx->foodSpawnTimer = 4;

    ctx->windowWidth = 500;
    ctx->windowHeight = 500;
    ctx->gridWidth = 10;
    ctx->gridHeight = 10;
    ctx->cellDrawSize = 10;
    ctx->startPos.x = (ctx->windowWidth - ctx->gridWidth * ctx->cellDrawSize) / 2;
    ctx->startPos.y = (ctx->windowHeight - ctx->gridHeight * ctx->cellDrawSize) / 2;
}

#endif