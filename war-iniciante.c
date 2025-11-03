//imports
#include<stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "territorio.h"
#include "jogador.h"

#ifdef _WIN32
#include <windows.h>
#endif


void chooseInitialTerritories(Player * players, int num_jogadores, Territory * mapa, int i);

int main() {
    // Configurar UTF-8 logo no início
    #ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    #endif
    
    setlocale(LC_ALL, "pt_BR.UTF-8");

    Territory mapa[MAX_TERRITORIES];
    Player jogadores[MAX_PLAYERS];
    int numJogadores = 0;

    printf("========================== Welcome to the War! ==========================\n");

    // Passo 1: Registrar jogadores
    playerRegistry(jogadores, &numJogadores);

    // Passo 2: Inicia o mapa;
    initTerritories(mapa);

    // Passo 3: Distribuir territórios entre os jogadores (exemplo futuro)
    chooseInitialTerritories(jogadores, numJogadores, mapa, MAX_TERRITORIES);

    printf("\n============================ Guerra iniciada============================\n");

    return 0;
}