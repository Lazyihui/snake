#ifndef COMMON_H_E_
#define COMMON_H_E_
#include "stdlib.h"
#include "..\include\raylib.h"
#include "..\include\raymath.h"
int Get_Rand(int min, int max) {
    return min + rand() % max;
}

Vector2 GetVecort_Rand() {
    Vector2 result = (Vector2){0};
    result.x = Get_Rand(10, 390);
    result.y = Get_Rand(10, 390);
    return result;
}

Vector2 Vector2Max(Vector2 a, Vector2 b) {
    Vector2 res = a;
    if (a.x < b.x) {
        res.x = b.x;
    } else {
        res.x = a.x;
    }
    if (a.y < b.y) {
        res.y = b.y;
    } else {
        res.y = a.y;
    }
    return res;
}
float Absolute(float input) {
    if (input >= 0) {
        return input;
    } else {
        return -input;
    }
}
Vector2 AbsoluteVector2(Vector2 inputvector2) {
    inputvector2.x = Absolute(inputvector2.x);
    inputvector2.y = Absolute(inputvector2.y);
    return inputvector2;
}
bool IsCircleinsideRect(Vector2 rectpos, Vector2 rectsize, Vector2 circlepos, float circleradius) {
    Vector2 recthalf = Vector2Scale(rectsize, 0.5f);
    Vector2 rectCenter = Vector2Add(rectpos, recthalf);
    // rect 基于 Circle 的中心坐标
    rectCenter = Vector2Subtract(rectCenter, circlepos); // x4 y4
    // rect 中心 变到第一象限
    rectCenter = AbsoluteVector2(rectCenter);
    // rect half
    // rect min
    Vector2 rectdown = Vector2Subtract(rectCenter, recthalf); // x2 y2
    rectdown = Vector2Max(rectdown, Vector2Zero());

    // rect min - circle center
    float rectToCircleLenSqr = Vector2LengthSqr(rectdown);
    float radiusSqr = circleradius * circleradius;
    if (rectToCircleLenSqr < radiusSqr) {
        return true;
    } else {
        return false;
    }
}
#endif