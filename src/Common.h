#ifndef COMMON_H_E_
#define COMMON_H_E_
#include "stdlib.h"

int Get_Rand(int min, int max) {
    return min + rand() % max;
}

Vector2 GetVecort_Rand() {
    Vector2 result = (Vector2){0};
    result.x=Get_Rand(10,790);
    result.y=Get_Rand(10,440);
    return result;
}


#endif