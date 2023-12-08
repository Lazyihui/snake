#ifndef FOODENTITY_H__
#define FOODENTITY_H__
#include "..\include\raylib.h"
#include "..\include\raymath.h"
#include "stdio.h"

typedef struct FoodEntity {

    Vector2 pos;
    float radius;
    Color color;
    bool isAlive;
    float fadeTimer;

} FoodEntity;


void FoodEntity_Draw(FoodEntity *food) {
    DrawCircle(food->pos.x, food->pos.y, food->radius, food->color);
}


#endif