#ifndef BUILDMAP
#define BUILDMAP

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

#define HEIGHT 63
#define LENGHT 79
#define CHARACTER Ω;


void showMap(int map[HEIGHT][LENGHT])
{
    for (int i = 0; i < HEIGHT; i++)
        {
            for (int j = 0; j < LENGHT; j++)
                if (map[i][j] == 0)
                    printf("   ");
                else
                    printf("%d  ",map[i][j]);      

            printf("\n");  
        }
}


void buildLine(int mode, int map[HEIGHT][LENGHT],int coord_x, int coord_y, int size)
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


void buildSquare(int mode, int map[HEIGHT][LENGHT], int coordUpY, int coordUpX, int coordDownY, int coordDownX)
{
    int lenght = coordDownX - coordUpX;
    int height = coordDownY - coordUpY;
    int biggest = (height>lenght)?height:lenght;
    if (mode == 1)
    {
        for(float i=0; i<=biggest; i++)
        {
            map[coordUpY + (int)((i/biggest)*height)][coordUpX] = 1;
            map[coordDownY - (int)((i/biggest)*height)][coordDownX] = 1;
            map[coordUpY][coordUpX + (int)((i/biggest)*lenght)] = 1;
            map[coordDownY][coordDownX - (int)((i/biggest)*lenght)] = 1;
        }
    }else if (mode == 2)
    {
        for(float i=0; i<=biggest; i++)
        {
            map[coordUpY + (int)((i/biggest)*height)][coordUpX] = 1;
            map[coordDownY - (int)((i/biggest)*height)][coordDownX] = 1;
            map[coordUpY][coordUpX + (int)((i/biggest)*lenght)] = 1;
            printf("xx yy");
        }
    
    }else{
        map[coordDownY][coordDownX] = 5;
    }
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < LENGHT; j++)
        {
            if(map[i][j])
                printf("%d  ", map[i][j]);
            else    
                printf("   ");
        }
        
    }
    
}

#endif 