#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Definição da estrutura que contém o ponteiro void *
typedef struct {
    void *entity;
} MyStruct;

// Função para atribuir o conteúdo de uma string a entity
void assignStringToEntity(MyStruct *obj, const char *name) {
    // Aloca memória para a string dentro de entity
    obj->entity = malloc(strlen(name) + 1);
    if (obj->entity != NULL) {
        // Copia o conteúdo da string para a memória alocada
        strcpy((char *)obj->entity, name);
    } else {
        // Tratamento de erro se a alocação de memória falhar
        fprintf(stderr, "Erro ao alocar memória para entity.\n");
    }
}

// Função para liberar a memória alocada para entity
void freeEntity(MyStruct *obj) {
    free(obj->entity);
    obj->entity = NULL;
}

int main() {
    MyStruct obj;

    // Exemplo de uso:
    const char *name1 = "Squirtle";
    assignStringToEntity(&obj, name1);
    printf("Entity: %s\n", (char *)obj.entity);

    const char *name2 = "Bulbasaur";
    assignStringToEntity(&obj, name2);
    printf("Entity: %s\n", (char *)obj.entity);

    // Liberando a memória alocada
    freeEntity(&obj);

    return 0;
}
