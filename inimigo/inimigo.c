#include "inimigo.h"

Vector2 CriarInimigo() {

    Vector2 enemyPos = {

        900,
        600
    };

    return enemyPos;
}

void AtualizarInimigo(
    Vector2 *enemyPos,
    float enemySpeed,
    Rectangle player
) {

    Vector2 playerCenter = {

        player.x + player.width / 2,
        player.y + player.height / 2
    };

    if (enemyPos->x < playerCenter.x) {
        enemyPos->x += enemySpeed;
    }

    if (enemyPos->x > playerCenter.x) {
        enemyPos->x -= enemySpeed;
    }

    if (enemyPos->y < playerCenter.y) {
        enemyPos->y += enemySpeed;
    }

    if (enemyPos->y > playerCenter.y) {
        enemyPos->y -= enemySpeed;
    }
}

void DesenharInimigo(Vector2 enemyPos) {

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