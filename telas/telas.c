#include "telas.h"
void DesenharTelaInicial() {

    DrawText(
        "VIGIA",
        470,
        150,
        70,
        RED
    );
}

// ========================================
// TELA SOBRE
// ========================================
void DesenharTelaSobre() {

    DrawText(
        "SOBRE O JOGO",
        390,
        120,
        40,
        WHITE
    );

    DrawText(
        "VIGIA e um jogo arcade em labirinto.",
        170,
        240,
        30,
        WHITE
    );

    DrawText(
        "O jogador deve explorar o mapa.",
        170,
        290,
        30,
        WHITE
    );

    DrawText(
        "Colete itens e evite os inimigos.",
        170,
        340,
        30,
        WHITE
    );

    DrawText(
        "Os inimigos ficam mais fortes.",
        170,
        390,
        30,
        WHITE
    );

    DrawText(
        "A dificuldade aumenta a cada fase.",
        170,
        440,
        30,
        WHITE
    );

    DrawText(
        "Sobreviva e consiga a maior pontuacao.",
        170,
        490,
        30,
        WHITE
    );
}