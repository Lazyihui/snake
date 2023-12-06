#ifndef FOODENTITY_H__
#define FOODENTITY_H__
#include "..\include\raylib.h"
#include "..\include\raymath.h"
typedef struct FoodEntity {

    Vector2 pos;
    float radius;
    Color color;
    

} FoodEntity;


void FoodEntity_Draw(FoodEntity *food) {
    DrawCircle(food->pos.x, food->pos.y, food->radius, food->color);
}

#endif