/* Compile:
gcc main.c -o Ternaria.exe -l gdi32 -l msimg32
*/

#include "headers/headers.h"


#define LIM_X 79
#define LIM_Y 63


int main()
{   
    int game[LIM_Y][LIM_X] = {{0}};
        
    int y=10;
    int x=10;
    game[y][x] = 1;


    while (1) {
        
        for(int i=0; i<LIM_Y; i++)
            for(int j=0; j<LIM_X; j++)
            if(game[i][j])
                printf("%d  ", game[i][j]);
            else
                printf("   ");

        game[y][x] = 0;
        checkWalk(&x, LIM_X, &y, LIM_Y);
        game[y][x] = 1;

        Sleep(100);
        system("cls");


        }
}