#include "raylib.h"

int main() {

    InitWindow(800, 450, "Meu jogo");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Raylib funcionando!", 200, 200, 20, BLACK);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}