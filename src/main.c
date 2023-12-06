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

        if(IsKeyPressed(KEY_SPACE)){
        Snake_Eat(&ctx.snake);

        }
        
        Draw_All(&ctx);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}