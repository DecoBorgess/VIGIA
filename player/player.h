#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
#include "../mapa/mapa.h"

Rectangle CriarPlayer(Mapa *mapa);

void AtualizarPlayer(
    Rectangle *player,
    float speed,
    Mapa *mapa
);

void DesenharPlayer(Rectangle player);

#endif