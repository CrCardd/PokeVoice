#include "../headers/terminal.h"

int main() {
    // Configure o terminal
    configureTerminal();

    // Limpa a tela e move o cursor para a posição inicial
    ERASE_ALL();
    MOVE_HOME();
    fflush(stdout);

    // Demonstração de impressão fluida no terminal
    for (int i = 0; i < 10; ++i) {
        // Salva a posição do cursor
        SAVE_CURSOR();
        
        // Muda a cor do texto
        FOREGROUND_COLOR(255, 0, 0); // Vermelho
        printf("Contador: %d\n", i);
        RESET_COLOR();

        // Restaura a posição do cursor
        LOAD_CURSOR();
        
        // Espera um pouco antes de atualizar novamente
        sleep(500000); // 0.5 segundos

        // Limpa a linha anterior
        ERASE_LEND();
        fflush(stdout);
    }

    // Mostra o cursor novamente antes de sair
    SHOW_CURSOR();
    fflush(stdout);

    return 0;
}
