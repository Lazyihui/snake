#include <stdio.h>
#include "..\include\raylib.h"
#include "..\include\raymath.h"
#include "Common.h"
#include "Context.h"
#include "SnakeEntity.h"
#include "InputEntity.h"

void Draw_All(Context *ctx) {
    SnakeEntity *snake = &ctx->snake;
    Snake_Draw(snake);

    for (int i = 0; i < ctx->foodCount; i++) {
        FoodEntity *food = &ctx->foods[i];
        if (food->isAlive) {
            FoodEntity_Draw(food);
        }
    }
}

int main() {
    InitWindow(400, 400, "snake");
    SetTargetFPS(60);
    Context ctx = {0};
    ContextInit(&ctx);

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        BeginDrawing();
        ClearBackground(BLACK);

        Input_Process(&ctx.input);

        ctx.snakeMoveTimer -= dt;
        // 一顿一顿的移动
        if (ctx.snakeMoveTimer <= 0) {
            SnakeEntity *snake = &ctx.snake;
            ctx.snakeMoveTimer = ctx.snakeMoveInterval;
            Snake_Move(snake, ctx.input.moveAxis);
            // printf("snake.x=%d  sanke.y=%d\r\n",snake->bodies->x,snake->bodies->y);
        }

        ctx.foodSpawnTimer -= dt;
        if (ctx.foodSpawnTimer <= 0) {
            int times = 1;
            for (int i = 0; i < times; i++) {
                ctx.foodCount += 1;
                FoodEntity food = (FoodEntity){0};
                // 生成
                food.color = GRAY;
                food.pos = GetVecort_Rand();
                food.radius = Get_Rand(4, 11);
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
            if (food->pos.x >= (ctx.snake.bodies->x) * ctx.snake.size &&
                food->pos.x <= (ctx.snake.bodies->x) * ctx.snake.size + ctx.snake.size &&
                food->pos.y >= (ctx.snake.bodies->y) * ctx.snake.size &&
                food->pos.y <= (ctx.snake.bodies->y) * ctx.snake.size + ctx.snake.size) {

                Snake_Eat(&ctx.snake);
                food->isAlive = false;
                printf("%d\r\n", ctx.snake.bodycount);
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