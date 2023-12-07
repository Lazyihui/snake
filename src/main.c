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
        FoodEntity_Draw(food);
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

        if (ctx.snakeMoveTimer <= 0) {
            SnakeEntity *snake = &ctx.snake;
            ctx.snakeMoveTimer = ctx.snakeMoveInterval;
            Snake_Move(snake, ctx.input.moveAxis);
        }

        ctx.foodSpawnTimer -= dt;
        if (ctx.foodSpawnTimer <= 0) {
            int times = 2;

            for (int i = 0; i < times; i++) {
                ctx.foodCount += 1;

                FoodEntity food = (FoodEntity){0};

                food.color = GRAY;
                food.pos = GetVecort_Rand();
                food.radius = 10;

                ctx.foods[ctx.foodCount - 1] = food;
                ctx.foodSpawnTimer = ctx.foodSpawnInterval;
                if (ctx.foodCount % 3 == 0) {
                    ctx.foods->radius = 8;
                }
            }
        }

        Snake_Eat(&ctx.snake);

        Draw_All(&ctx);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}