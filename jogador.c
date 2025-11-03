//
// Created by junio on 03/11/2025.
//
#include "jogador.h"
#include <stdio.h>
#include <string.h>
#include "utils.h"

void playerRegistry(Player jogadores[], int *numJogadores) {
    printf("\n========================== REGISTRO DE JOGADORES ==========================\n");
    printf("Quantidade de jogadores (2 a %d): ", MAX_PLAYERS);
    scanf("%d", numJogadores);
    limparBufferDeEntrada();

    while (*numJogadores < 2 || *numJogadores > MAX_PLAYERS) {
        printf("Número inválido! Digite um valor entre 2 e %d: ", MAX_PLAYERS);
        scanf("%d", numJogadores);
        limparBufferDeEntrada();
    }

    for (int i = 0; i < *numJogadores; i++) {
        printf("\n--- Jogador %d ---\n", i + 1);
        printf("Nome do Jogador: ");
        fgets(jogadores[i].playerName, MAX_NAME, stdin);
        jogadores[i].playerName[strcspn(jogadores[i].playerName, "\n")] = '\0';

        printf("Cor do exército (ex: Vermelho, Azul, Preto ou Amarelo): ");
        fgets(jogadores[i].armyColor, 10, stdin);
        jogadores[i].armyColor[strcspn(jogadores[i].armyColor, "\n")] = '\0';

        jogadores[i].totalTerritories = 0;
        jogadores[i].totalTroops = 0;
    }

    printf("\n=================== Generais alistados! Preparem-se para guerra! ===================\n");
    for (int i = 0; i < *numJogadores; i++) {
        printf("Jogador %d: General %s - Exército: %s\n",
               i + 1, jogadores[i].playerName, jogadores[i].armyColor);
    }
}

void initPlayers(Player jogadores[]) {

}
