#include <stdio.h>
#include <stdlib.h>

typedef struct {
    void *mode;
} ScreenModes;

int main() {
    ScreenModes A;
    A.mode = "Fight";  // Atribuindo uma string

    // Para acessar o valor armazenado em A.mode, precisamos fazer o cast apropriado
    printf("Mode: %s\n", (char *)A.mode);

    // Atribuindo um inteiro
    int battleMode = 1;
    A.mode = &battleMode;  // Atribuindo um inteiro

    // Para acessar o valor armazenado em A.mode, precisamos fazer o cast apropriado
    printf("Battle mode: %d\n", *(int *)A.mode);

    // Atribuindo uma estrutura
    typedef struct {
        int level;
        float difficulty;
    } GameMode;

    GameMode gm = {5, 3.5};
    A.mode = &gm;  // Atribuindo uma estrutura

    // Para acessar o valor armazenado em A.mode, precisamos fazer o cast apropriado
    printf("Game mode level: %d, difficulty: %.1f\n", ((GameMode *)A.mode)->level, ((GameMode *)A.mode)->difficulty);

    return 0;
}
