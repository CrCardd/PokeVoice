#ifndef RENDER_H
#define RENDER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "terminal.c"
#include "main.h"
#include <windows.h>
#include <math.h>



// Função para renderizar o mapa e seus personagens ou objetos com base nos valores de renderização definidos à eles
void showMap(Room *game, MapData screenData)
{
    HIDE_CURSOR();
    MOVE_HOME();
    fflush(stdout); // métodos para diminuir o delay de impressão no terminal


    // variáveis auxiliares para melhor visualização
    int wall = game->objects.renderWall;
    int up;
    int down;
    int right;
    int left; 

        //looping que percorre o mapa passado como parâmetro
        for (int i = 0; i < screenData.rows; i++) 
        {
            for (int j = 0; j < screenData.collums; j++)
            
            
                if(screenData.map[i][j].value == game->player.renderValue) // verificação para o player
                    printf("%c%c%c",218,234,191);
                else if (screenData.map[i][j].value == wall)                                 // verificação para a direção das paredes e conexão das mesmas
                {
                    up = (i==0) ? 0 : screenData.map[i-1][j].value;
                    down = (i==screenData.rows-1) ? 0 : screenData.map[i+1][j].value;
                    left = (j==0) ? 0 : screenData.map[i][j-1].value;
                    right = (j==screenData.collums-1) ? 0 : screenData.map[i][j+1].value;
                    if(game->objects.renderWallColorSecond == 1)
                        FOREGROUND_COLOR(255, 10 , 80);
                    else if (game->objects.renderWallColorSecond == 0)
                        FOREGROUND_COLOR(10, 50 , 255);
                    
                    if(up == wall && right == wall && down == wall && left == wall)
                        printf("%c%c%c",205,206,205);
                    else if(up == wall && right == wall && down == wall && left != wall)
                        printf(" %c%c",204,205);
                    else if(up == wall && right == wall && down != wall && left != wall)
                        printf(" %c%c",200,205);
                    else if(right == wall && down == wall && left == wall && up != wall)
                        printf("%c%c%c",205,203,205);
                    else if(right == wall && down == wall && left != wall && up != wall)
                        printf(" %c%c",201,205);
                    else if(down == wall && left == wall && up == wall && right != wall)
                        printf("%c%c ",205,185);
                    else if(down == wall && left == wall && up != wall && right != wall)
                        printf("%c%c ",205,187);
                    else if(left == wall && up == wall && right == wall && down != wall)
                        printf("%c%c%c",205,202,205);
                    else if(left == wall && up == wall && right != wall && down != wall)
                        printf("%c%c ",205,188);
                    else if(left == wall && right != wall && up != wall && down != wall)
                            printf("%c%c ",205,205);
                    else if(left != wall && right == wall && up != wall && down != wall)
                            printf(" %c%c",205,205);
                    else if(left == wall && right == wall && up != wall && down != wall)
                            printf("%c%c%c",205,205,205);
                    else //if((up || down) && right != wall && left != wall)
                        printf(" %c ",186);
                    RESET_FOREGROUND();
                }
                else if (screenData.map[i][j].value == game->objects.renderStep)  
                {                                                                           // verificação para as escadas que só é permitido a descida
                    FOREGROUND_COLOR(100,100,100);
                    printf("%c%c%c",176,176,176);
                    RESET_FOREGROUND();
                }
                else if (screenData.map[i][j].value == game->objects.renderPokeball)
                {
                    FOREGROUND_COLOR(255,0,0);
                    printf("{");              
                    RESET_FOREGROUND();                                                                     // verificação para pokebola
                    printf("o}");                                                               // verificação para pokebola
                }
                else if(!screenData.map[i][j].value)
                    printf("   ");                                                                  // verificação para espaçoes vazios


                else if(screenData.map[i][j].value == game->objects.renderHole)                     // verificação para buracos
                    printf("%c%c%c",177,177,177);
                else if(screenData.map[i][j].value == game->objects.renderEnemy)
                    printf("<_>");                                                                  // verificação para inimigos
                
                else if(screenData.map[i][j].value == MESSAGE)                                      // método para printar mensagem na matriz sem desordena-la
                {   
                    int size = strlen((char*)screenData.map[i][j].entity);
                    printf("%s",(char*)screenData.map[i][j].entity);        //print da mensagem
                    for(int k=0; k < (3 - (size%3)); k++)   
                        printf(" ");                                        // preenceher o resto que é necessário para manter o padrão
                    size = size/3 + (pow(size%3,0))-1;                      // calculo de quantos valores foram ocupados

                    j += size;                                              // acréscimo nas colunas para evitar desordenação
                }

            printf("\n");
        }

    fflush(stdout);

}

#endif