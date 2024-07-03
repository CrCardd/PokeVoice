#include <stdio.h>

// Definindo um tipo de função que aceita dois inteiros e retorna um inteiro
typedef int (*FuncPointer)(int, int);

// Função que soma dois inteiros
int soma(int a, int b) {
    return a + b;
}

// Definindo a struct com um ponteiro para função
typedef struct {
    FuncPointer func;
} MinhaStruct;

int main() {
    // Criando uma instância da struct
    MinhaStruct exemplo;
    
    // Atribuindo a função à struct
    exemplo.func = soma;
    
    // Chamando a função através do ponteiro e imprimindo o resultado
    int resultado = exemplo.func(5, 3);
    printf("Resultado: %d\n", resultado);
    
    return 0;
}