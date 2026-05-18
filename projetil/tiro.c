#include "tiro.h"

#include <math.h>

static void CriarTiro(
    Tiro *tiro,
    Rectangle player,
    Vector2 mouse
) {

    tiro->pos = (Vector2){

        player.x + player.width/2,
        player.y + player.height/2
    };

    Vector2 dir = {

        mouse.x - tiro->pos.x,
        mouse.y - tiro->pos.y
    };

    float tamanho = sqrtf(
        dir.x * dir.x +
        dir.y * dir.y
    );

    tiro->dir.x = dir.x / tamanho;
    tiro->dir.y = dir.y / tamanho;

    tiro->speed = 10.0f;

    tiro->ativo = true;
}

void InicializarSistemaTiros(
    SistemaTiros *sistema
) {

    for (int i = 0; i < MAX_TIROS; i++) {

        sistema->tiros[i].ativo = false;
    }
}

void AtualizarSistemaTiros(
    SistemaTiros *sistema,
    Rectangle player
) {

    Vector2 mouse = GetMousePosition();

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {

        for (int i = 0; i < MAX_TIROS; i++) {

            if (!sistema->tiros[i].ativo) {

                CriarTiro(
                    &sistema->tiros[i],
                    player,
                    mouse
                );

                break;
            }
        }
    }

    for (int i = 0; i < MAX_TIROS; i++) {

        Tiro *tiro = &sistema->tiros[i];

        if (!tiro->ativo) continue;

        tiro->pos.x += tiro->dir.x * tiro->speed;
        tiro->pos.y += tiro->dir.y * tiro->speed;

        if (
            tiro->pos.x < 0 ||
            tiro->pos.x > 1200 ||
            tiro->pos.y < 0 ||
            tiro->pos.y > 900
        ) {

            tiro->ativo = false;
        }
    }
}

void DesenharSistemaTiros(
    SistemaTiros sistema
) {

    for (int i = 0; i < MAX_TIROS; i++) {

        if (sistema.tiros[i].ativo) {

            DrawCircleV(
                sistema.tiros[i].pos,
                5,
                RED
            );
        }
    }
}