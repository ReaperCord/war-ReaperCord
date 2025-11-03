//
// Created by junio on 03/11/2025.
//
#ifndef WAR_REAPERCORD_TERRITORIO_H
#define WAR_REAPERCORD_TERRITORIO_H

#define MAX_NAME 30
#define MAX_TERRITORIES 20

typedef struct territory {
    char name[MAX_NAME];
    char continent[MAX_NAME];
    char armyColor[10];
    int troops;
    char dono[MAX_NAME];
} Territory;

// carrega os nomes dos territórios, sem número fixo
void initTerritories(Territory mapa[]);
Territory* getTerritoryByName(const char *name);

#endif