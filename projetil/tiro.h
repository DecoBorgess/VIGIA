#ifndef TIRO_H
#define TIRO_H

#include "raylib.h"

#define MAX_TIROS 100

typedef struct {

    Vector2 pos;
    Vector2 dir;

    float speed;

    bool ativo;

} Tiro;

typedef struct {

    Tiro tiros[MAX_TIROS];

} SistemaTiros;

void InicializarSistemaTiros(
    SistemaTiros *sistema
);

void AtualizarSistemaTiros(
    SistemaTiros *sistema,
    Rectangle player
);

void DesenharSistemaTiros(
    SistemaTiros sistema
);

#endif