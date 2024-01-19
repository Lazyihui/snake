#ifndef SANKECONTROLLER_H__
#define SANKECONTROLLER_H__
#include "SnakeEntity.h"

void SnakeController_Tick(Context *ctx,float dt) {
    // 蛇
    SnakeEntity *snake = &ctx->snake;
    ctx->snakeMoveTimer -= dt;
    // 一顿一顿的移动
    if (ctx->snakeMoveTimer <= 0) {
        ctx->snakeMoveTimer = ctx->snakeMoveInterval;
        Snake_Move(snake, ctx->input.moveAxis, ctx->gridWidth, ctx->gridHeight,ctx->Gamestatus);
        // printf("snake.x=%d  sanke.y=%d\r\n",snake->bodies->x,snake->bodies->y);
    }
}

#endif