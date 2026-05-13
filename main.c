#include "raylib.h"
#include "mapa/mapa.h"
#include <stdlib.h>
#include <time.h>

typedef enum {

    TELA_INICIAL,
    TELA_SOBRE,
    MAPA

} GameScreen;

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

    Rectangle player = {

        60,
        60,

        mapa.tileSize / 2,
        mapa.tileSize / 2
    };

    float speed = 4.0f;

    Vector2 enemyPos = {

        900,
        600
    };

    float enemySpeed = 2.0f;


    while (!WindowShouldClose()) {

        Vector2 mouse = GetMousePosition();

        if (currentScreen == TELA_INICIAL) {

            if (CheckCollisionPointRec(mouse, botaoJogar) &&
                IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {

                currentScreen = MAPA;
            }

            if (CheckCollisionPointRec(mouse, botaoSobre) &&
                IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {

                currentScreen = TELA_SOBRE;
            }
        }

        else if (currentScreen == TELA_SOBRE) {

            if (CheckCollisionPointRec(mouse, botaoVoltar) &&
                IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {

                currentScreen = TELA_INICIAL;
            }
        }

        else if (currentScreen == MAPA) {

            Rectangle oldPlayer = player;

            if (IsKeyDown(KEY_D)) player.x += speed;
            if (IsKeyDown(KEY_A)) player.x -= speed;
            if (IsKeyDown(KEY_W)) player.y -= speed;
            if (IsKeyDown(KEY_S)) player.y += speed;

            if (ColisaoMapa(&mapa, player)) {

                player = oldPlayer;
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

        ClearBackground(BLACK);

        if (currentScreen == TELA_INICIAL) {

            DrawText(
                "VIGIA",
                470,
                150,
                70,
                RED
            );

            // BOTÃO JOGAR
            DrawRectangleRounded(
                botaoJogar,
                0.3f,
                10,
                DARKBLUE
            );

            DrawText(
                "JOGAR",
                535,
                340,
                35,
                WHITE
            );

            // BOTÃO SOBRE
            DrawRectangleRounded(
                botaoSobre,
                0.3f,
                10,
                DARKBLUE
            );

            DrawText(
                "SOBRE O JOGO",
                485,
                450,
                30,
                WHITE
            );
        }

        else if (currentScreen == TELA_SOBRE) {

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

            // BOTÃO VOLTAR
            DrawRectangleRounded(
                botaoVoltar,
                0.3f,
                10,
                DARKBLUE
            );

            DrawText(
                "VOLTAR",
                65,
                48,
                28,
                WHITE
            );
        }

        else if (currentScreen == MAPA) {

            DesenharMapa(&mapa);

            DrawCircle(

                player.x + player.width / 2,
                player.y + player.height / 2,

                player.width / 2,

                YELLOW
            );


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
