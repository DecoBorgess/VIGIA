#ifndef INIMIGO_H
#define INIMIGO_H

#include "raylib.h"

Vector2 CriarInimigo();

void AtualizarInimigo(
    Vector2 *enemyPos,
    float enemySpeed,
    Rectangle player
);

void DesenharInimigo(Vector2 enemyPos);

#endif