#ifndef MOVES_H 
#define MOVES_H 
 
#include <windows.h>
#include "keycodes.h"
#include "stack.h"
#include "main.h"
#include"renderValues.h"
#include "buildMap.h"



int up;
int down;
int right;
int left;


void checkMove(Room * game, MapData * screen)
{  

    // Verificação de colisão no mapa
    up    = (game->player.pY > 0 && screen->map[game->player.pY-1][game->player.pX].value != game->objects.renderWall && screen->map[game->player.pY-1][game->player.pX].value != game->objects.renderStep) ? 1 : 0;
    down  = (game->player.pY < screen->rows-1 && screen->map[game->player.pY+1][game->player.pX].value != game->objects.renderWall) ? 1 : 0;
    left  = (game->player.pX > 0 && screen->map[game->player.pY][game->player.pX-1].value != game->objects.renderWall) ? 1 : 0;
    right = (game->player.pX < screen->collums-1 && screen->map[game->player.pY][game->player.pX+1].value != game->objects.renderWall) ? 1 : 0;



    // substituição do valor da coordenada atual pelo valor da coordenada guardada no player (é iniciada em 0)
    screen->map[game->player.pY][game->player.pX] = game->player.lastCoord;

    // acréscimo ou decréscimo nas coordenadas do player com base no teclado
    if(GetAsyncKeyState(VK_W) && up)
        game->player.pY--;
    else if(GetAsyncKeyState(VK_S) && down)
        game->player.pY++;
    else if(GetAsyncKeyState(VK_A) && left)
        game->player.pX--;
    else if(GetAsyncKeyState(VK_D) && right)
        game->player.pX++;

    
    // Guardamos o valor da nova coordenada para quando nos movermos ele ser devolvido ao seu local
    game->player.lastCoord = screen->map[game->player.pY][game->player.pX];
    // atribuição do valor do player ao novo local que acessou
    screen->map[game->player.pY][game->player.pX].value = game->player.renderValue;

    Sleep(100);
}


int selectOption(Room * game, MapData * mapData)
{   

    


    // verificação para nao sair dos limites da caixa de seleção
    up    = (game->actions.pY != 0) ? 1 : 0;
    down  = (game->actions.pY != mapData->selectOptions.rows-1) ? 1 : 0;
    left  = (game->actions.pX != 0) ? 1 : 0;
    right = (game->actions.pX != mapData->selectOptions.collums-1) ? 1 : 0;

    
    // apagando quadrado de seleção que é mostrado no programa 
    buildSquare(mapData->map,mapData->selectOptions.options[game->actions.pY][game->actions.pX].optY,mapData->selectOptions.options[game->actions.pY][game->actions.pX].optX,mapData->selectOptions.options[game->actions.pY][game->actions.pX].optY_,mapData->selectOptions.options[game->actions.pY][game->actions.pX].optX_,0);

    //verificação de movimento entre as oopções
    if(GetAsyncKeyState(VK_W) && up)
        game->actions.pY--;
    else if(GetAsyncKeyState(VK_S) && down)
        game->actions.pY++;
    else if(GetAsyncKeyState(VK_A) && left)
        game->actions.pX--;
    else if(GetAsyncKeyState(VK_D) && right)
        game->actions.pX++;
    

    // recriando quadrado de seleção mostrado no programa em suas novas coordenadas
    buildSquare(mapData->map,mapData->selectOptions.options[game->actions.pY][game->actions.pX].optY,mapData->selectOptions.options[game->actions.pY][game->actions.pX].optX,mapData->selectOptions.options[game->actions.pY][game->actions.pX].optY_,mapData->selectOptions.options[game->actions.pY][game->actions.pX].optX_,1);
    Sleep(100);

    // verificação para saber se foi decido uma das opções ou não.
    // se sim, retornará um número equivalente a opção desejada
    if(GetAsyncKeyState(VK_ENTER))
        return game->actions.pY * mapData->selectOptions.collums + game->actions.pX;
    else
        return -1; // se não retornará um número que não se encaixa no resto do programa

}

//Função genérica para verificar se o player está em contato com algo
int checkInteract(Room * game, MapData * screen, int entity, int put)
{
    int interact = 0;


    up    = screen->map[game->player.pY-1][game->player.pX].value;
    down  = screen->map[game->player.pY+1][game->player.pX].value;
    right = screen->map[game->player.pY][game->player.pX+1].value;
    left  = screen->map[game->player.pY][game->player.pX-1].value;

    if(GetAsyncKeyState(VK_ENTER))
    {
        if(up == entity)  //IF ITEM UP
        {
            game->player.currentEntity = screen->map[game->player.pY-1][game->player.pX].entity;
            screen->map[game->player.pY-1][game->player.pX].value = put;
            interact = 1;
        }

        if(down == entity) //IF ITEM DOWN
        {   
            game->player.currentEntity = screen->map[game->player.pY+1][game->player.pX].entity;
            screen->map[game->player.pY+1][game->player.pX].value = put;
            interact = 1;
        }

        if(right == entity) //IF ITEM RIGHT
        {   
            game->player.currentEntity = screen->map[game->player.pY][game->player.pX+1].entity;
            screen->map[game->player.pY][game->player.pX+1].value = put;
            interact = 1;
        }

        if(left == entity) //IF ITEM LEFT
        {
            game->player.currentEntity = screen->map[game->player.pY][game->player.pX-1].entity;
            screen->map[game->player.pY][game->player.pX-1].value = put;
            interact = 1;
        }
    }
    return interact;
}

// Função que verifica se o player está em cima de um buraco e se tomou uma ação
void checkHole(Room * game)
{
    if(GetAsyncKeyState(VK_ENTER) && game->player.lastCoord.value == game->objects.renderHole)
    {
        if(game->screenModes.Map)                                                                       // verifica em que mapa estamos para realiar a troca
        {
            game->mapScreen.map[game->player.pY][game->player.pX] = game->player.lastCoord;
            push(&game->stackEvents,&game->secondMapScreen);
            game->screenModes.Map = 0;
            game->screenModes.SecondMap = 1;
            game->player.lastCoord = game->secondMapScreen.map[game->player.pY][game->player.pX];
            
            game->objects.renderWallColorSecond = 1; 
            Sleep(100);
        }
        else if(game->screenModes.SecondMap)                                                             // verifica em que mapa estamos para realizar a troca
        {
            game->secondMapScreen.map[game->player.pY][game->player.pX] = game->player.lastCoord;
            pop(&game->stackEvents);
            game->screenModes.Map = 1;
            game->screenModes.SecondMap = 0;
            game->player.lastCoord = game->mapScreen.map[game->player.pY][game->player.pX];

            game->objects.renderWallColorSecond = 0; 
            Sleep(100);
        }
    }
}

// Função que verifica se há um inimigo próximo ao jogador
void checkEnemy(Room * game)
{

    int interact = checkInteract(game, &game->mapScreen,game->objects.renderEnemy,game->objects.renderEnemy);

    if(GetAsyncKeyState(VK_ENTER) && interact && ((Enemy*)game->player.currentEntity)->team.alive == 'a')
    {
        game->fightScreen.map[54][6].value =  MESSAGE;                              // atruivção de valor para indicar que há uma mensagem a ser mostrada nessa posição
        game->fightScreen.map[54][6].entity = game->player.team.pokes[0].name;      // mensagem a ser mostrada
        whatWillDo(game->fightScreen.map);
        fightScreenConstruct(game->fightScreen.map, game->player.team.pokes[0], ((Enemy*)game->player.currentEntity)->team.pokes[0]);

        push(&game->stackEvents, &game->fightScreen);
        game->actions = playerInnit(0,0,0);                                         // inicialização de um "player" que serve para caminhas entre as caixas de seleção
        game->screenModes.Fight = 1;                                                // ativamos a batalha pois encontramos com um inimigo  
        game->screenModes.Map = 0;                                                  // desativamos o mapa pois agora estamos no modo batalha
        game->objects.renderWallColorSecond = -1;
    }   
    
}


#endif