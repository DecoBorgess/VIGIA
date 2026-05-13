#include "raylib.h"
#include "mapa/mapa.h"

#include <stdlib.h>
#include <time.h>

typedef enum {
    TELA_INICIAL,
    MAPA
} GameScreen;

int main() {

    // ========================================
    // JANELA
    // ========================================

    InitWindow(1200, 900, "VIGIA");

    SetTargetFPS(60);

    srand(time(NULL));

    // ========================================
    // TELAS
    // ========================================

    GameScreen currentScreen = TELA_INICIAL;

    double startTime = GetTime();

    // ========================================
    // MAPA
    // ========================================

    Mapa mapa;

    // linhas, colunas
    GerarMapa(&mapa, 15, 20);

    // ========================================
    // PLAYER
    // ========================================

    Rectangle player = {

        60,
        60,

        mapa.tileSize / 2,
        mapa.tileSize / 2
    };

    float speed = 4.0f;

    // ========================================
    // INIMIGO
    // ========================================

    Vector2 enemyPos = {

        900,
        600
    };

    float enemySpeed = 2.0f;

    // ========================================
    // LOOP PRINCIPAL
    // ========================================

    while (!WindowShouldClose()) {

        // ========================================
        // TELA INICIAL
        // ========================================

        if (currentScreen == TELA_INICIAL) {

            if (GetTime() - startTime >= 4.0) {

                currentScreen = MAPA;
            }
        }

        // ========================================
        // GAMEPLAY
        // ========================================

        if (currentScreen == MAPA) {

            Rectangle oldPlayer = player;

            // ========================================
            // MOVIMENTO PLAYER
            // ========================================

            if (IsKeyDown(KEY_D)) {
                player.x += speed;
            }

            if (IsKeyDown(KEY_A)) {
                player.x -= speed;
            }

            if (IsKeyDown(KEY_W)) {
                player.y -= speed;
            }

            if (IsKeyDown(KEY_S)) {
                player.y += speed;
            }

            // ========================================
            // COLISÃO MAPA
            // ========================================

            if (ColisaoMapa(&mapa, player)) {

                player = oldPlayer;
            }

            // ========================================
            // CENTRO PLAYER
            // ========================================

            Vector2 playerCenter = {

                player.x + player.width / 2,
                player.y + player.height / 2
            };

            // ========================================
            // IA INIMIGO
            // ========================================

            if (enemyPos.x < playerCenter.x) {
                enemyPos.x += enemySpeed;
            }

            if (enemyPos.x > playerCenter.x) {
                enemyPos.x -= enemySpeed;
            }

            if (enemyPos.y < playerCenter.y) {
                enemyPos.y += enemySpeed;
            }

            if (enemyPos.y > playerCenter.y) {
                enemyPos.y -= enemySpeed;
            }
        }

        // ========================================
        // DESENHO
        // ========================================

        BeginDrawing();

        ClearBackground(BLACK);

        // ========================================
        // TELA INICIAL
        // ========================================

        if (currentScreen == TELA_INICIAL) {

            DrawText(
                "VIGIA",
                500,
                400,
                50,
                WHITE
            );
        }

        // ========================================
        // MAPA
        // ========================================

        else if (currentScreen == MAPA) {

            // MAPA
            DesenharMapa(&mapa);

            // PLAYER
            DrawCircle(

                player.x + player.width / 2,
                player.y + player.height / 2,

                player.width / 2,

                YELLOW
            );

            // INIMIGO
            DrawTriangle(

                (Vector2){
                    enemyPos.x,
                    enemyPos.y - 20
                },

                (Vector2){
                    enemyPos.x - 20,
                    enemyPos.y + 20
                },

                (Vector2){
                    enemyPos.x + 20,
                    enemyPos.y + 20
                },

                RED
            );
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}