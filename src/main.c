#include <stdio.h>
#include "..\include\raylib.h"
#include "..\include\raymath.h"
#include "Common.h"
#include "Context.h"
#include "SnakeEntity.h"
#include "InputEntity.h"

void Draw_All(Context *ctx){
    Snake_Draw(&ctx->snake);
}

int main() {
    InitWindow(400, 400, "cyh");
    SetTargetFPS(60);
    Context ctx = {0};
    ContextInit(&ctx);

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        BeginDrawing();
        ClearBackground(BLACK);

        Input_Process(&ctx.input);

        Snake_Move(&ctx.snake,ctx.input.moveAxis,dt);

        
        // FoodEntity *food = &ctx.foods[0];
        // FoodEntity_Draw(food);


        Draw_All(&ctx);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}