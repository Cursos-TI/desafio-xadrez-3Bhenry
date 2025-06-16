// xadrez.c
#include <stdio.h>

// Recursividade - Torre: movimentos verticais e horizontais
void moverTorreCima(int casas) {
    if (casas == 0) return;
    printf("Cima\n");
    moverTorreCima(casas - 1);
}

void moverTorreDireita(int casas) {
    if (casas == 0) return;
    printf("Direita\n");
    moverTorreDireita(casas - 1);
}

// Recursividade - Bispo (diagonal): loops aninhados + recursividade
void moverBispoDiagonal(int vertical, int horizontal) {
    if (vertical == 0 || horizontal == 0) return;
    printf("Diagonal superior direita\n");
    moverBispoDiagonal(vertical - 1, horizontal - 1);
}

// Loops aninhados para o Bispo (alternativa à recursão)
void moverBispoComLoops(int passos) {
    for (int i = 0; i < passos; i++) {
        for (int j = 0; j < passos; j++) {
            if (i == j) {
                printf("Diagonal superior direita\n");
            }
        }
    }
}

// Recursividade - Rainha: combina torre e bispo
void moverRainha(int casasVerticais, int casasHorizontais) {
    if (casasVerticais > 0) {
        printf("Cima\n");
        moverRainha(casasVerticais - 1, casasHorizontais);
    } else if (casasHorizontais > 0) {
        printf("Direita\n");
        moverRainha(0, casasHorizontais - 1);
    }
}

// Cavalo - loops complexos: 2 cima e 1 direita
void moverCavalo() {
    int movimentosVerticais[] = {-2};
    int movimentosHorizontais[] = {1};
    
    for (int i = 0; i < 1; i++) {
        for (int j = 0; j < 1; j++) {
            int v = movimentosVerticais[i];
            int h = movimentosHorizontais[j];
            if (v == -2 && h == 1) {
                printf("Cavalo: Duas casas para cima e uma para a direita\n");
            } else {
                continue;
            }
        }
    }
}

int main() {
    int casasTorre = 3;
    int casasBispo = 3;
    int casasRainhaV = 2;
    int casasRainhaH = 2;

    // Movimentos da Torre
    printf("Movimentos da Torre:\n");
    moverTorreCima(casasTorre);
    moverTorreDireita(casasTorre);
    printf("\n");

    // Movimentos do Bispo (com recursão)
    printf("Movimentos do Bispo com recursão:\n");
    moverBispoDiagonal(casasBispo, casasBispo);
    printf("\n");

    // Movimentos do Bispo (com loops aninhados)
    printf("Movimentos do Bispo com loops:\n");
    moverBispoComLoops(casasBispo);
    printf("\n");

    // Movimentos da Rainha
    printf("Movimentos da Rainha:\n");
    moverRainha(casasRainhaV, casasRainhaH);
    printf("\n");

    // Movimentos do Cavalo
    printf("Movimentos do Cavalo:\n");
    moverCavalo();
    printf("\n");

    return 0;
}
