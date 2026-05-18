#include "player.h"

Rectangle CriarPlayer(Mapa *mapa) {

    Rectangle player = {

        60,
        60,

        mapa->tileSize / 2,
        mapa->tileSize / 2
    };

    return player;
}

void AtualizarPlayer(
    Rectangle *player,
    float speed,
    Mapa *mapa
) {

    Rectangle oldPlayer = *player;

    if (IsKeyDown(KEY_D)) player->x += speed;
    if (IsKeyDown(KEY_A)) player->x -= speed;
    if (IsKeyDown(KEY_W)) player->y -= speed;
    if (IsKeyDown(KEY_S)) player->y += speed;

    if (ColisaoMapa(mapa, *player)) {

        *player = oldPlayer;
    }
}

void DesenharPlayer(Rectangle player) {

    DrawCircle(

        player.x + player.width / 2,
        player.y + player.height / 2,

        player.width / 2,

        YELLOW
    );
}