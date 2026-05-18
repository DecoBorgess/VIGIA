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
}

void AtualizarTela(
    GameScreen *currentScreen,
    Vector2 mouse,
    Rectangle botaoJogar,
    Rectangle botaoSobre,
    Rectangle botaoVoltar
) {

    if (*currentScreen == TELA_INICIAL) {

        if (
            CheckCollisionPointRec(mouse, botaoJogar) &&
            IsMouseButtonPressed(MOUSE_LEFT_BUTTON)
        ) {

            *currentScreen = MAPA;
        }

        if (
            CheckCollisionPointRec(mouse, botaoSobre) &&
            IsMouseButtonPressed(MOUSE_LEFT_BUTTON)
        ) {

            *currentScreen = SOBRE;
        }
    }

    else if (*currentScreen == SOBRE) {

        if (
            CheckCollisionPointRec(mouse, botaoVoltar) &&
            IsMouseButtonPressed(MOUSE_LEFT_BUTTON)
        ) {

            *currentScreen = TELA_INICIAL;
        }
    }
}

void DesenharTela(
    GameScreen currentScreen,
    Rectangle botaoJogar,
    Rectangle botaoSobre,
    Rectangle botaoVoltar
) {

    if (currentScreen == TELA_INICIAL) {

        DesenharTelaInicial();

        DrawRectangleRec(
            botaoJogar,
            DARKGREEN
        );

        DrawText(
            "JOGAR",
            530,
            340,
            30,
            WHITE
        );

        DrawRectangleRec(
            botaoSobre,
            DARKBLUE
        );

        DrawText(
            "SOBRE",
            530,
            450,
            30,
            WHITE
        );
    }

    else if (currentScreen == SOBRE) {

        DesenharTelaSobre();

        DrawRectangleRec(
            botaoVoltar,
            RED
        );

        DrawText(
            "VOLTAR",
            50,
            45,
            30,
            WHITE
        );
    }
}