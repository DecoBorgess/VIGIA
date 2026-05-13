#ifndef MAPA_H
#define MAPA_H

#include "raylib.h"

#define LIVRE 0
#define PAREDE 1

typedef struct {

    int linhas;
    int colunas;

    int tileSize;

    int grid[25][25];

} Mapa;

// GERA
void GerarMapa(Mapa *mapa, int linhas, int colunas);

// DESENHA
void DesenharMapa(Mapa *mapa);

// COLISÃO
int ColisaoMapa(Mapa *mapa, Rectangle player);

#endif