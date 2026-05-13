#include "raylib.h"

typedef enum {
    TELA_INICIAL,
    MAPA
} GameScreen;

int main() {

    InitWindow(800, 450, "Meu jogo");

    SetTargetFPS(60);

    GameScreen currentScreen = TELA_INICIAL;

    double startTime = GetTime();

    Rectangle player = {100, 300, 50, 50};

    float speed = 5.0f;

    Vector2 enemyPos = {600, 200};

    float enemySpeed = 2.0f;

    while (!WindowShouldClose()) {
        if (currentScreen == TELA_INICIAL) {
            if (GetTime() - startTime >= 4.0) {
                currentScreen = MAPA;
            }
        }
        if (currentScreen == MAPA) {

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
            Vector2 playerCenter = {
                player.x + player.width / 2,
                player.y + player.height / 2
            };

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
        BeginDrawing();

        ClearBackground(RAYWHITE);

        if (currentScreen == TELA_INICIAL) {

            DrawText("VIGIA", 190, 200, 20, BLACK);

        } else if (currentScreen == MAPA) {

            ClearBackground(BLACK);

            DrawText("Mapa prototipo", 20, 20, 30, WHITE);

            DrawRectangleRec(player, BLUE);

            DrawTriangle(
                (Vector2){enemyPos.x, enemyPos.y - 20},
                (Vector2){enemyPos.x - 20, enemyPos.y + 20},
                (Vector2){enemyPos.x + 20, enemyPos.y + 20},
                RED
            );
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}