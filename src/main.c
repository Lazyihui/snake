#include <stdio.h>
#include "..\include\raylib.h"
#include "..\include\raymath.h"
#include "Common.h"
#include "Context.h"
#include "SnakeEntity.h"
#include "InputEntity.h"

void Draw_All(Context *ctx) {

    int cellDrawSize = ctx->cellDrawSize;
    Vector2 startPos = ctx->startPos;
    DrawRectangle(startPos.x, startPos.y, ctx->gridWidth * cellDrawSize,
                  ctx->gridHeight * cellDrawSize, BLACK);

    SnakeEntity *snake = &ctx->snake;
    Snake_Draw(snake, startPos, cellDrawSize);

    for (int i = 0; i < ctx->foodCount; i++) {
        FoodEntity *food = &ctx->foods[i];
        if (food->isAlive) {
            FoodEntity_Draw(food, startPos, cellDrawSize);
        }
    }
}

int main() {

    Context ctx = {0};
    ContextInit(&ctx);

    InitWindow(ctx.windowWidth, ctx.windowHeight, "snake");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        BeginDrawing();
        ClearBackground(RAYWHITE);

        Input_Process(&ctx.input);

        // 蛇
        SnakeEntity *snake = &ctx.snake;
        ctx.snakeMoveTimer -= dt;
        // 一顿一顿的移动
        if (ctx.snakeMoveTimer <= 0) {
            ctx.snakeMoveTimer = ctx.snakeMoveInterval;
            Snake_Move(&ctx,snake, ctx.input.moveAxis);
            // printf("snake.x=%d  sanke.y=%d\r\n",snake->bodies->x,snake->bodies->y);
        }

        // 果: Spawn
        ctx.foodSpawnTimer -= dt;
        if (ctx.foodSpawnTimer <= 0) {
            int times = 1;
            for (int i = 0; i < times; i++) {
                ctx.foodCount += 1;
                FoodEntity food = (FoodEntity){0};
                // 生成
                food.color = GRAY;
                food.pos = GetVecort_Rand(ctx.gridWidth, ctx.gridHeight);
                food.isAlive = true;
                food.fadeTimer = 0;

                printf("x=%f y=%f\r\n", food.pos.x, food.pos.y);

                ctx.foods[ctx.foodCount - 1] = food;
                ctx.foodSpawnTimer = ctx.foodSpawnInterval;
            }
        }

        for (int i = 0; i < ctx.foodCount; i++) {
            FoodEntity *food = &ctx.foods[i];
            food->fadeTimer += dt;
            if (food->fadeTimer >= 6) {
                food->isAlive = false;
            }
        }

        // 碰到消失
        for (int i = 0; i < ctx.foodCount; i++) {
            FoodEntity *food = &ctx.foods[i];
            Vector2 *head = Snake_Head(snake);
            if (Vector2Equals(food->pos, *head)) {
                Snake_Eat(snake);
                food->isAlive = false;
                printf("%d\r\n", snake->bodycount);
            }
        }
        // 消失 换位置
        for (int i = ctx.foodCount - 1; i >= 0; i--) {
            FoodEntity food = ctx.foods[i];
            if (!food.isAlive) {
                ctx.foods[i] = ctx.foods[ctx.foodCount - 1];
                ctx.foods[ctx.foodCount - 1] = food;
                ctx.foodCount -= 1;
            }
        }

        Draw_All(&ctx);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}