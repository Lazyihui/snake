#ifndef INPUTENEEITY_H__
#define INPUTENEEITY_H__
#include <stdio.h>
#include "..\include\raylib.h"
#include "..\include\raymath.h"

typedef struct InputEntity {
    Vector2 moveAxis;

} InputEntity;

void Input_Process(InputEntity *input) {
    if (IsKeyDown(KEY_W)) {
        input->moveAxis.y = -1;
    } else if (IsKeyDown(KEY_S)) {
        input->moveAxis.y = 1;
    } else if (IsKeyDown(KEY_A)) {
        input->moveAxis.x = -1;
    }else

}

#endif