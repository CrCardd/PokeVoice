#include <stdio.h>
#include <string.h>

// Definições de estruturas (exemplo)
typedef struct {
    void *entity;
    int value;
} MapEntry;

typedef struct {
    MapEntry map[100][100];
} AttackScreen;

typedef struct {
    AttackScreen attackScreen;
} Game;

int main() {
    Game game;

    // Declarando e inicializando as frases
    char phrase1[50] = "Ataque 1";
    char phrase2[50] = "Ataque 2";
    char phrase3[50] = "Ataque 3";
    char phrase4[50] = "Ataque 4";

    // Atribuindo as frases aos campos entity como void*
    game.attackScreen.map[42][42].entity = (void*)phrase1;
    game.attackScreen.map[42][42].value = 1; // Exemplo de valor

    game.attackScreen.map[42][64].entity = (void*)phrase2;
    game.attackScreen.map[42][64].value = 2;

    game.attackScreen.map[54][42].entity = (void*)phrase3;
    game.attackScreen.map[54][42].value = 3;

    game.attackScreen.map[54][64].entity = (void*)phrase4;
    game.attackScreen.map[54][64].value = 4;

    // Acessando e imprimindo os valores
    printf("Frase 1: %s\n", (char*)game.attackScreen.map[42][42].entity);

    printf("Frase 2: %s\n", (char*)game.attackScreen.map[42][64].entity);

    printf("Frase 3: %s\n", (char*)game.attackScreen.map[54][42].entity);

    printf("Frase 4: %s\n", (char*)game.attackScreen.map[54][64].entity);

    return 0;
}
