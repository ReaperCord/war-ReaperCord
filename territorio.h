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
} Territory;

void MapBoard(Territory mapa[]);

#endif