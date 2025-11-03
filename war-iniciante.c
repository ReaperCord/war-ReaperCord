//imports
#include<stdio.h>
#include "territorio.h"
#include "jogador.h"

int main() {
    Territory mapa[MAX_TERRITORIES];
    Player jogadores[MAX_PLAYERS];
    int numJogadores = 0;

    MapBoard(mapa);

    printf("========================== Welcome to the War! ==========================\n");

    playerRegistry(jogadores, &numJogadores);

    printf("\n========================== TERRITÓRIOS DISPONÍVEIS ==========================\n");
    for (int i = 0; i < MAX_TERRITORIES; i++) {
        printf("Território disponível: %s (%s)\n", mapa[i].name, mapa[i].continent);
    }

    return 0;
}