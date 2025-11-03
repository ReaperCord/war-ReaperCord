//
// Created by junio on 03/11/2025.
//
#include "jogador.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
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

//os jogadores escolheram os seus territórios , o território escolhido receberá o armyColor do jogador
void chooseInitialTerritories(Player jogadores[], int numJogadores, Territory mapa[], int totalTerritories) {

    char escolha[MAX_NAME];
    char escolhaLower[MAX_NAME];

    printf("\n=================== Fase de escolhas de território ===================\n");

    //a fase de escolhas terá 5 rodadas durante essas 5 rodadas cada jogador escolherá 1 território
    for (int r = 0; r < MAX_PLAYER_TERRITORIES; r++) {
        for (int j = 0; j < numJogadores; j++) {
            int find = 0;

            do {
                printf("\n-------------- Teatro de Guerra atual --------------\n");
                for (int m = 0; m < totalTerritories; m++) {
                    if (mapa[m].name[0] == '\0') continue;
                    printf("- %20s | %-15s | Dono: %s\n",
                           mapa[m].name, mapa[m].continent,
                           (mapa[m].dono[0] == '\0') ? "Livre" : mapa[m].dono);
                }

                printf("\n%s (%s), escolha um território disponível: ",
                       jogadores[j].playerName, jogadores[j].armyColor);

                if (fgets(escolha, sizeof(escolha), stdin) == NULL) {
                    escolha[0] = '\0';
                } else {
                    escolha[strcspn(escolha, "\n")] = '\0';
                }

                // lowercase copy for case-insensitive compare
                for (size_t k = 0; k < sizeof(escolhaLower) - 1 && escolha[k]; k++) {
                    escolhaLower[k] = (char)tolower((unsigned char)escolha[k]);
                    escolhaLower[k+1] = '\0';
                }

                // buscar no mapa
                find = 0;
                for (int m = 0; m < totalTerritories; m++) {
                    if (mapa[m].name[0] == '\0') continue;

                    // cria versão lowercase do nome do mapa
                    char mapaLower[MAX_NAME];
                    for (size_t x = 0; x < sizeof(mapaLower) - 1 && mapa[m].name[x]; x++) {
                        mapaLower[x] = (char)tolower((unsigned char)mapa[m].name[x]);
                        mapaLower[x+1] = '\0';
                    }

                    if (strcmp(escolhaLower, mapaLower) == 0) {
                        // encontrado
                        if (mapa[m].dono[0] == '\0') {
                            // atribui dono e copia para os territórios do jogador
                            strncpy(mapa[m].dono, jogadores[j].armyColor, sizeof(mapa[m].dono)-1);
                            mapa[m].dono[sizeof(mapa[m].dono)-1] = '\0';

                            if (jogadores[j].totalTerritories < MAX_PLAYER_TERRITORIES) {
                                jogadores[j].playerTerritories[jogadores[j].totalTerritories++] = mapa[m];
                            }
                            printf("\nParabéns %s conquistou %s!\n", jogadores[j].playerName, mapa[m].name);
                            find = 1;
                            break;
                        } else {
                            printf("\nEsse território já pertence a %s.\n", mapa[m].dono);
                            find = 0;
                            break;
                        }
                    }
                }

                if (!find) {
                    printf("Território não encontrado ou indisponível. Tente novamente.\n");
                }

            } while (!find);
        }
    }

    printf("\n=================== Distribuição completa! ===================\n");

    for (int j = 0; j < numJogadores; j++) {
        printf("\n%s (%s):\n", jogadores[j].playerName, jogadores[j].armyColor);

        for (int t = 0; t < jogadores[j].totalTerritories; t++) {
            printf(" - %s\n", jogadores[j].playerTerritories[t].name);
        }
    }
}
