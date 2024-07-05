#ifndef PRESETTHREAD_H
#define PRESETTHREAD_H

#include "render.h"
#include "stack.h"
#include "main.h"
#include "moves.h"

#include <stdio.h>

HANDLE Mutex;

DWORD showScreen(void *arg)
{
    Room * map = (Room*) arg;
    while(1)
    {
        
        MapData * event = peek(&map->stackEvents); // recolhe o elemento do topo da pilha para renderização do evento
        WaitForSingleObject(Mutex, INFINITE);

        showMap(map,*event);                       // renderiza o evento seja ele qual for
        
        ReleaseMutex(Mutex);
    }   
}


DWORD checkKeyboard(void *arg)
{
    Room * map = (Room*) arg;
    
    while(1)
    {
        MapData * event = peek(&map->stackEvents);   // recolhe o elemento do topo da pilha para processamento de dados
        WaitForSingleObject(Mutex, INFINITE);


        if(!map->screenModes.Fight) // verifica se estamos em batalha
        {
            checkEnemy(map);       // confere se está em contato com um oponente
            checkMove(map,event);  // confere se está em movimento
            checkHole(map);        // confere se esta em contato com um buraco
        }
        else                        // verifica se estamos em batalha
        {
            int option = selectOption(map,event); // utiliza da funcção de seleção para enviar o evento e assim retornar uma escolha do jogador, semelhante a um 'scanf'
            event->func(map, option);             // executa o ponteiro de função atribuido na inicialização do evento, enviando a opção escolhida, lá esse dado será trabalhado
        }

        ReleaseMutex(Mutex);

        if(map->player.checkAct) // caso o player tenha feito uma ação o seu oponente poderá inflingir seu ataque
            enemyRound(map, &map->player.team, (Enemy*)map->player.currentEntity); 
        
    }
}


#endif //PRESETTHREAD_H