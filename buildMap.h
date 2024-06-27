#ifndef BUILDMAP
#define BUILDMAP

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

#define HEIGHT 63
#define LENGHT 79
#define CHARACTER Ω;


void showMap(int matrix[HEIGHT][LENGHT])
{
    for (int i = 0; i < HEIGHT; i++)
        {
            for (int j = 0; j < LENGHT; j++)
            {
                if (matrix[i][j] == 0)
                {
                    printf("   ");
                }else{
                    printf("%d  ",matrix[i][j]);
                } 
            }      
            printf("\n");  
        }
}


void createLine(int mode, int map[HEIGHT][LENGHT],int coord_x, int coord_y, int size)
{
    if(mode == 1)
    {
        for (int i = coord_x; i < coord_x + size; i++)
            map[coord_y][i] = 1;
        
    }else if (mode == 2)
    {
        for (int i = coord_y; i < coord_y + size; i++)
            map[i][coord_x] = 1;
    }else
    {
        map[coord_x][coord_y] = 5;
    }    
}


#endif // !BUILD_MAP