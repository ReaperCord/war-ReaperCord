//
// Created by junio on 03/11/2025.
//

#ifndef WAR_REAPERCORD_JOGADOR_H
#define WAR_REAPERCORD_JOGADOR_H

#include "territorio.h"

#define MAX_PLAYERS 4
#define MAX_PLAYER_TERRITORIES 5

typedef struct exercitos {
    char playerName[MAX_NAME];
    char armyColor[10];
    Territory playerTerritories[MAX_PLAYER_TERRITORIES];
    int totalTerritories;
    int totalTroops;
} Player;

void playerRegistry(Player jogadores[], int *numJogadores);

#endif