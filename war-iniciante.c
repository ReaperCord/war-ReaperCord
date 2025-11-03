//imports
#include<stdio.h>
#include<string.h>

#define MAX_PLAYER_TERRITORIES 5
#define MAX_TERRITORIES 20
#define MAX_NAME 30
#define MAX_PLAYERS 4


void limparBufferDeEntrada() {
    int c; while ((c = getchar()) != '\n' && c != EOF);
}


//TODO: Criar uma struct chamada território

typedef struct territory{
    char name[MAX_NAME];
    char continent[MAX_NAME];
    char armyColor[10];
    int troops;
} Territory;


//TODO: Usar um 1 vetor estático de 5 elementos para armazenar territórios.
typedef struct playerHand {
    char playername[MAX_NAME];
    Territory playerTerritories[MAX_PLAYER_TERRITORIES];
    int totalTerritories;
} PlayerHand;


//TODO: Cadastrar os dados de cada território: Nome, Cor do Exército e Numero de tropas.

void MapBoard(Territory mapa[]) {
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

    strcpy(mapa[18].name, "Japão");
    strcpy(mapa[18].continent, "Ásia");
    mapa[18].troops = 0;

    strcpy(mapa[19].name, "Rússia");
    strcpy(mapa[19].continent, "Ásia");
    mapa[19].troops = 0;
}


//TODO: Criando os Exercitos

typedef struct  exercitos{
    char playerName[MAX_NAME];
    char armyColor[10];
    Territory playerTerritories[MAX_PLAYER_TERRITORIES];
    int totalTerritories;
    int totalTroops;
}Player;


//TODO: Função de registo de jogadores:

void playerRegistry(Player jogadores[], int *numJogadores) {
    printf("\n========================== REGISTRO DE JOGADORES ==========================\n");
    printf("Quantidade de jogadores: %d\n",MAX_PLAYERS);
    scanf("%d",&(*numJogadores));
    limparBufferDeEntrada();

    while (*numJogadores < 2 || *numJogadores > MAX_PLAYERS) {
        printf("Numero de jogadores invalido! Digite um numero entre 2 e %d: ",MAX_PLAYERS);
        scanf("%d",&(*numJogadores));
        limparBufferDeEntrada();
    }

    for (int i = 0; i < *numJogadores; i++) {
        printf("\n--- Jogador %d ---\n", i + 1);
        printf("Nome do Jogador: ");
        fgets(jogadores[i].playerName, MAX_NAME, stdin);
        jogadores[i].playerName[strlen(jogadores[i].playerName) - 1] = '\0';

        printf("Digite a cor do seu exercito (ex: Vermelho, Azul, Preto ou Amarelo): ");
        fgets(jogadores[i].armyColor, 10, stdin);
        jogadores[i].armyColor[strcspn(jogadores[i].armyColor, "\n")] = '\0';

        //inicializa o jogador
        jogadores[i].totalTerritories = 0;
        jogadores[i].totalTroops = 0;
    }

    printf("\n=================== Generais alistados! Preparem-se para guerra! ===================");
    for (int i = 0; i < *numJogadores; i++) {
        printf("\n--- Jogador %d, General %s Exército: %s  ---\n",
            i + 1,
            jogadores[i].playerName, jogadores[i].armyColor);
    }
    printf("\n====================================================================================");
}


//TODO: Exibir estado atual do tabuleiro



int main() {
    Territory mapa[MAX_TERRITORIES];
    Player jogadores[MAX_PLAYERS];
    int numJogadores = 0;

    MapBoard(mapa);

    printf("========================== Welcome to the War! ==========================\n");

    // Registrar jogadores
    playerRegistry(jogadores, &numJogadores);

    printf("\n========================== TERRITÓRIOS DISPONÍVEIS ==========================\n");
    for (int i = 0; i < MAX_TERRITORIES; i++) {
        printf("Território disponível para escolha: - %s (%s)\n", mapa[i].name, mapa[i].continent);
    }

    return 0;

}