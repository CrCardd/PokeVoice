#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // Adiciona a biblioteca string.h para usar strlen

int main() {
    void *frase = "nao sei-oqi";

    // Calcula o tamanho da string usando strlen
    printf("%zu\n", strlen((char *)frase));

    return 0;
}
