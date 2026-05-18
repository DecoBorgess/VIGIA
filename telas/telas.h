#ifndef TELAS_H
#define TELAS_H

#include "raylib.h"

typedef enum {

    TELA_INICIAL,
    SOBRE,
    MAPA

} GameScreen;

void AtualizarTela(
    GameScreen *currentScreen,
    Vector2 mouse,
    Rectangle botaoJogar,
    Rectangle botaoSobre,
    Rectangle botaoVoltar
);

void DesenharTela(
    GameScreen currentScreen,
    Rectangle botaoJogar,
    Rectangle botaoSobre,
    Rectangle botaoVoltar
);

void DesenharTelaInicial();

void DesenharTelaSobre();

#endif