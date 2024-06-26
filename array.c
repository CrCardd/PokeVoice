#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define ROWS 63
#define COLS 79

int main() {
    int matrix[ROWS][COLS];

    // Prepare a formatted string to store all matrix elements
    char formattedString[100]; // Adjust size as needed

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = 0;
        }
    }

    // Use sprintf to construct the formatted string
    int offset = 0; // Offset to keep track of the position in the string
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            offset += sprintf(formattedString + offset, "%d  ", matrix[i][j]);
        }
    }

    // Print the formatted string containing all matrix elements
    while (1)
    {
    printf("Matrix:\n%s\n", formattedString);
    Sleep(1000);
    system("cls");

        /* code */
    }
    

    return 0;
}
