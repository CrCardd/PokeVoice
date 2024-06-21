#include <stdio.h>
#include <string.h>

int main(){
    FILE *file;
    char line[32];
    char name[32];
    char dmg[32];
    char uses[32];
    char *token;

    // Open file for reading
    file = fopen("../moves.txt", "r");

    // Read and process each line
    while (fgets(line, sizeof(line), file) != NULL) {
        // Do something with the line, for example, print it
        token = strtok(line, ","),

        strcpy(name, token);
        token = strtok(NULL, ",");
        strcpy(dmg, token);
        token = strtok(NULL, ",");
        strcpy(uses, token);
        
        printf("\n %s", name);
        printf("\n %s", dmg);
        printf("\n %s", uses);
    }

    // Close the file
    fclose(file);
}