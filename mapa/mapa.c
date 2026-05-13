#include "mapa.h"
#include <stdlib.h>

// ========================================
// CRIAR LINHA HORIZONTAL
// ========================================
void LinhaHorizontal(
    Mapa *mapa,
    int y,
    int x1,
    int x2
) {

    for (int x = x1; x <= x2; x++) {

        mapa->grid[y][x] = PAREDE;
    }
}

// ========================================
// CRIAR LINHA VERTICAL
// ========================================
void LinhaVertical(
    Mapa *mapa,
    int x,
    int y1,
    int y2
) {

    for (int y = y1; y <= y2; y++) {

        mapa->grid[y][x] = PAREDE;
    }
}

// ========================================
// GERA MAPA
// ========================================
void GerarMapa(Mapa *mapa, int linhas, int colunas) {

    mapa->linhas = linhas;
    mapa->colunas = colunas;

    mapa->tileSize =
        GetScreenWidth() / colunas;

    // ========================================
    // TUDO LIVRE
    // ========================================

    for (int i = 0; i < linhas; i++) {

        for (int j = 0; j < colunas; j++) {

            mapa->grid[i][j] = LIVRE;
        }
    }

    // ========================================
    // BORDA EXTERNA
    // ========================================

    LinhaHorizontal(mapa, 0, 0, colunas - 1);
    LinhaHorizontal(mapa, linhas - 1, 0, colunas - 1);

    LinhaVertical(mapa, 0, 0, linhas - 1);
    LinhaVertical(mapa, colunas - 1, 0, linhas - 1);

    // ========================================
    // CORREDORES INTERNOS
    // ========================================

    LinhaHorizontal(mapa, 3, 2, 8);
    LinhaHorizontal(mapa, 3, 11, 17);

    LinhaHorizontal(mapa, 7, 4, 14);

    LinhaHorizontal(mapa, 11, 2, 8);
    LinhaHorizontal(mapa, 11, 11, 17);

    LinhaVertical(mapa, 5, 3, 7);
    LinhaVertical(mapa, 13, 7, 11);

    // ========================================
    // CASA CENTRAL
    // ========================================

    LinhaHorizontal(mapa, 5, 8, 10);
    LinhaHorizontal(mapa, 8, 8, 10);

    LinhaVertical(mapa, 8, 5, 8);
    LinhaVertical(mapa, 10, 5, 8);

    // porta
    mapa->grid[5][9] = LIVRE;

    // ========================================
    // ABERTURAS
    // ========================================

    mapa->grid[7][0] = LIVRE;
    mapa->grid[7][colunas - 1] = LIVRE;
}

// ========================================
// DESENHAR
// ========================================
void DesenharMapa(Mapa *mapa) {

    for (int i = 0; i < mapa->linhas; i++) {

        for (int j = 0; j < mapa->colunas; j++) {

            int x = j * mapa->tileSize;
            int y = i * mapa->tileSize;

            // FUNDO
            DrawRectangle(
                x,
                y,
                mapa->tileSize,
                mapa->tileSize,
                BLACK
            );

            // PAREDES
            if (mapa->grid[i][j] == PAREDE) {

                Rectangle rect = {

                    x + 4,
                    y + 4,

                    mapa->tileSize - 8,
                    mapa->tileSize - 8
                };

                DrawRectangleRounded(
                    rect,
                    0.3f,
                    10,
                    BLUE
                );
            }
            else {

                // pellets
                DrawCircle(
                    x + mapa->tileSize / 2,
                    y + mapa->tileSize / 2,
                    3,
                    BEIGE
                );
            }
        }
    }
}

// ========================================
// COLISÃO
// ========================================
int ColisaoMapa(
    Mapa *mapa,
    Rectangle player
) {

    int leftTile =
        player.x / mapa->tileSize;

    int rightTile =
        (player.x + player.width)
        / mapa->tileSize;

    int topTile =
        player.y / mapa->tileSize;

    int bottomTile =
        (player.y + player.height)
        / mapa->tileSize;

    for (int i = topTile; i <= bottomTile; i++) {

        for (int j = leftTile; j <= rightTile; j++) {

            // fora do mapa
            if (i < 0 ||
                j < 0 ||
                i >= mapa->linhas ||
                j >= mapa->colunas) {

                return 1;
            }

            // parede
            if (mapa->grid[i][j] == PAREDE) {

                return 1;
            }
        }
    }

    return 0;
}