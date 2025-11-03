//
// Created by junio on 03/11/2025.
//

#include "territorio.h"
#include <string.h>

static Territory territory[MAX_TERRITORIES];
static int totalTerritory = 0;

void initTerritories(Territory mapa[]) {
    // zera todo o vetor para evitar lixo
    for (int i = 0; i < MAX_TERRITORIES; i++) {
        mapa[i].name[0] = '\0';
        mapa[i].continent[0] = '\0';
        mapa[i].armyColor[0] = '\0';
        mapa[i].troops = 0;
        mapa[i].dono[0] = '\0';
    }

    // América do Sul
    strcpy(mapa[0].name, "Brasil");
    strcpy(mapa[0].continent, "América do Sul");
    mapa[0].troops = 0;

    strcpy(mapa[1].name, "Argentina");
    strcpy(mapa[1].continent, "América do Sul");
    mapa[1].troops = 0;

    strcpy(mapa[2].name, "Venezuela");
    strcpy(mapa[2].continent, "América do Sul");
    mapa[2].troops = 0;

    strcpy(mapa[3].name, "Peru");
    strcpy(mapa[3].continent, "América do Sul");
    mapa[3].troops = 0;

    // América do Norte
    strcpy(mapa[4].name, "México");
    strcpy(mapa[4].continent, "América do Norte");
    mapa[4].troops = 0;

    strcpy(mapa[5].name, "Alasca");
    strcpy(mapa[5].continent, "América do Norte");
    mapa[5].troops = 0;

    strcpy(mapa[6].name, "Califórnia");
    strcpy(mapa[6].continent, "América do Norte");
    mapa[6].troops = 0;

    strcpy(mapa[7].name, "Nova York");
    strcpy(mapa[7].continent, "América do Norte");
    mapa[7].troops = 0;

    // Europa
    strcpy(mapa[8].name, "Reino Unido");
    strcpy(mapa[8].continent, "Europa");
    mapa[8].troops = 0;

    strcpy(mapa[9].name, "Alemanha");
    strcpy(mapa[9].continent, "Europa");
    mapa[9].troops = 0;

    strcpy(mapa[10].name, "França");
    strcpy(mapa[10].continent, "Europa");
    mapa[10].troops = 0;

    strcpy(mapa[11].name, "Espanha");
    strcpy(mapa[11].continent, "Europa");
    mapa[11].troops = 0;

    // África
    strcpy(mapa[12].name, "Egito");
    strcpy(mapa[12].continent, "África");
    mapa[12].troops = 0;

    strcpy(mapa[13].name, "Nigéria");
    strcpy(mapa[13].continent, "África");
    mapa[13].troops = 0;

    strcpy(mapa[14].name, "África do Sul");
    strcpy(mapa[14].continent, "África");
    mapa[14].troops = 0;

    strcpy(mapa[15].name, "Congo");
    strcpy(mapa[15].continent, "África");
    mapa[15].troops = 0;

    // Ásia
    strcpy(mapa[16].name, "China");
    strcpy(mapa[16].continent, "Ásia");
    mapa[16].troops = 0;

    strcpy(mapa[17].name, "Índia");
    strcpy(mapa[17].continent, "Ásia");
    mapa[17].troops = 0;

    // completando até MAX_TERRITORIES com nomes válidos (exemplo)
    strcpy(mapa[18].name, "Japão");
    strcpy(mapa[18].continent, "Ásia");
    mapa[18].troops = 0;

    strcpy(mapa[19].name, "Rússia");
    strcpy(mapa[19].continent, "Ásia/Europa");
    mapa[19].troops = 0;
}

Territory* getTerritoryByName(const char *name) {
    for (int i = 0; i < totalTerritory; i++) {
        if (strcmp(territory[i].name, name) == 0)
            return &territory[i];
    }
    return NULL;
}
