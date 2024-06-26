#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

#define HEIGHT 63
#define LENGHT 79
#define CHARACTER Ω;

void createMap(int matrix[HEIGHT][LENGHT])
{
    for (int i = 0; i <HEIGHT ; i++)
    {
        for (int j = 0; j < LENGHT; j++)
        { 
        // if ((j == column_start && i <= row)|| (j == column_stop && i <= row)||
        // (i == row && (j > column_start && j < column_stop))) // horizontal limits
        // {
        //     matrix[i][j] = 1;
        // }else{
        //     matrix[i][j] = 0;
        // }   
        matrix[i][j] = 0;
        }
        
    }
}
void createLineX(int map[HEIGHT][LENGHT],int coord_x, int coord_y, int size)
{
    for (int i = coord_x; i < size; i++)
        map[coord_y][i] = 1;
}
// void build_map(int mode, int coord, int coord2, int lenght, int map[HEIGHT][LENGHT])
// {
//     switch (mode)
//     {
//     case 1:
//         for(int i=0; i<coord2; i++)
//             map[]
//         break;
    
//     default:
//         break;
//     }
// }

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
        for (int i = coord_x; i < size+coord_x; i++)
            map[coord_y][i] = 1;
        
    }else if (mode == 2)
    {
        for (int i = coord_y; i < coord_y-size; i--)
        {
            map[i][coord_x] = 1;
            printf("%d\n",i);
        }
    }else
    {
        map[coord_x][coord_y] = 5;
    }
    
    
}
int main()
{
    system("color 50");
    int map[HEIGHT][LENGHT] = {{0}};

// createLine(1, map, 0, 62, 10);
createLine(2, map, 25, 30, 15);

showMap(map);
    // for (int i = 0; i < HEIGHT; i++)
    // {
    //     for (int j = 0; j < LENGHT; j++)
    //     {
    //         if ((j == 63 && i <= 20)|| (j == 73 && i <= 20)||
    //         (i == 20 && (j > 63 && j < 73)))
    //         {
    //             map[i][j] = 1;
    //         }else{
    //             map[i][j] = 0;
    //         }        
    //     }        
    // }


return 0;
}
