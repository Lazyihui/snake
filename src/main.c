#include <stdio.h>
#include "..\include\raylib.h"
#include "..\include\raymath.h"
#include "Common.h"
#include "Context.h"
#include "SnakeEntity.h"
#include "InputEntity.h"
#include "SnakeController.h"
#include "FoodController.h"
void Draw_All(Context *ctx) {

    int cellDrawSize = ctx->cellDrawSize;
    Vector2 startPos = ctx->startPos;
    DrawRectangle(startPos.x, startPos.y, ctx->gridWidth * cellDrawSize, ctx->gridHeight * cellDrawSize, BLACK);

    SnakeEntity *snake = &ctx->snake;
    Snake_Draw(snake, startPos, cellDrawSize);

    for (int i = 0; i < ctx->foodCount; i++) {
        FoodEntity *food = &ctx->foods[i];
        if (food->isAlive) {
            FoodEntity_Draw(food, startPos, cellDrawSize);
        }
    }
    if(ctx->Gamestatus==1){
        DrawText("Game over",250,250,50,RED);
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

        SnakeController_Tick(&ctx,dt);

        FoodController_Tick(&ctx,dt);



        Draw_All(&ctx);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}