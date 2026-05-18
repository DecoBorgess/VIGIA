#include "raylib.h"
#include "mapa/mapa.h"
#include "telas.h"
#include "player.h"
#include "inimigo.h"

#include <stdlib.h>
#include <time.h>

int main() {

    InitWindow(1200, 900, "VIGIA");

    SetTargetFPS(60);

    srand(time(NULL));

    GameScreen currentScreen = TELA_INICIAL;

    Rectangle botaoJogar = {

        450,
        320,

        300,
        70
    };

    Rectangle botaoSobre = {

        450,
        430,

        300,
        70
    };

    Rectangle botaoVoltar = {

        30,
        30,

        180,
        60
    };

    Mapa mapa;

    GerarMapa(&mapa, 15, 20);

    Rectangle player = CriarPlayer(&mapa);

    float speed = 4.0f;

    Vector2 enemyPos = CriarInimigo();

    float enemySpeed = 2.0f;

    while (!WindowShouldClose()) {

        Vector2 mouse = GetMousePosition();

        AtualizarTela(
            &currentScreen,
            mouse,
            botaoJogar,
            botaoSobre,
            botaoVoltar
        );

        if (currentScreen == MAPA) {

            AtualizarPlayer(
                &player,
                speed,
                &mapa
            );

            AtualizarInimigo(
                &enemyPos,
                enemySpeed,
                player
            );
        }

        BeginDrawing();

        ClearBackground(BLACK);

        DesenharTela(
            currentScreen,
            botaoJogar,
            botaoSobre,
            botaoVoltar
        );

        if (currentScreen == MAPA) {

            DesenharMapa(&mapa);

            DesenharPlayer(player);

            DesenharInimigo(enemyPos);
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}