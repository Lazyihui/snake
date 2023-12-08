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

void FoodEntity_Draw(FoodEntity *food, Vector2 startPos, int cellDrawSize) {
    Vector2 pos = Vector2Scale(food->pos, cellDrawSize);
    pos = Vector2Add(startPos, pos);
    DrawRectangleV(pos, (Vector2){cellDrawSize, cellDrawSize}, food->color);
}

#endif