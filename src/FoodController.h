#ifndef FOODCONTROLLER_H__
#define FOODCONTROLLER_H__
#include "Context.h"

void FoodController_Tick(Context *ctx,float dt){
       // 果: Spawn
        ctx->foodSpawnTimer -= dt;
        if (ctx->foodSpawnTimer <= 0) {
            int times = 1;
            for (int i = 0; i < times; i++) {
                ctx->foodCount += 1;
                FoodEntity food = (FoodEntity){0};
                // 生成
                food.color = GREEN;
                food.pos = GetVecort_Rand(ctx->gridWidth, ctx->gridHeight);
                food.isAlive = true;
                food.fadeTimer = 0;

                printf("x=%f y=%f\r\n", food.pos.x, food.pos.y);

                ctx->foods[ctx->foodCount - 1] = food;
                ctx->foodSpawnTimer = ctx->foodSpawnInterval;
            }
        }

        for (int i = 0; i < ctx->foodCount; i++) {
            FoodEntity *food = &ctx->foods[i];
            food->fadeTimer += dt;
            if (food->fadeTimer >= 6) {
                food->isAlive = false;
            }
        }

        // 碰到消失
        for (int i = 0; i < ctx->foodCount; i++) {
            FoodEntity *food = &ctx->foods[i];
            SnakeEntity *snake = &ctx->snake;
            Vector2 *head = Snake_Head(snake);
            if (Vector2Equals(food->pos, *head)) {
                Snake_Eat(snake);
                food->isAlive = false;
                printf("%d\r\n", snake->bodycount);
            }
        }
        // 消失 换位置
        for (int i = ctx->foodCount - 1; i >= 0; i--) {
            FoodEntity food = ctx->foods[i];
            if (!food.isAlive) {
                ctx->foods[i] = ctx->foods[ctx->foodCount - 1];
                ctx->foods[ctx->foodCount - 1] = food;
                ctx->foodCount -= 1;
            }
        }

}

#endif