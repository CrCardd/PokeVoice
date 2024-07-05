#include <stdio.h>

// Definições das macros
#define FOREGROUND_COLOR(r, g, b) printf("\e[38;2;%d;%d;%dm", r, g, b)
#define BACKGROUND_COLOR(r, g, b) printf("\e[48;2;%d;%d;%dm", r, g, b)
#define RESET_FOREGROUND() printf("\e[39m")
#define RESET_BACKGROUND() printf("\e[49m")
#define RESET_COLOR() printf("\e[0m")

int main() {
    // Definir a cor do texto para vermelho
    FOREGROUND_COLOR(255, 0, 0);
    printf("Texto em vermelho\n");

    // Resetar a cor do texto para a cor padrão
    RESET_FOREGROUND();

    // Definir a cor do plano de fundo para azul
    BACKGROUND_COLOR(0, 0, 255);
    printf("Texto com plano de fundo azul\n");

    // Resetar a cor do plano de fundo para a cor padrão
    RESET_BACKGROUND();

    // Definir a cor do texto para verde e plano de fundo para amarelo
    FOREGROUND_COLOR(0, 255, 0);
    BACKGROUND_COLOR(255, 255, 0);
    printf("Texto verde com fundo amarelo\n");

    // Resetar as cores do texto e plano de fundo para as cores padrão
    RESET_COLOR();

    return 0;
}
