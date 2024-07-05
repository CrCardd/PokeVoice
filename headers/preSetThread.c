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
        
        MapData * event = peek(&map->stackEvents);
        WaitForSingleObject(Mutex, INFINITE);

    
            showMap(map,*event);

        
        ReleaseMutex(Mutex);
    }   
}


DWORD checkKeyboard(void *arg)
{
    Room * map = (Room*) arg;
    
    while(1)
    {
        MapData * event = peek(&map->stackEvents);
        WaitForSingleObject(Mutex, INFINITE);


        if(!map->screenModes.Fight)
        {
            checkEnemy(map);

            checkMove(map,event);

            checkHole(map);
        }
        else
        {
            int option = selectOption(map,event);
            event->func(map, option);
        }

        ReleaseMutex(Mutex);

        if(map->player.checkAct)
        {
            enemyRound(map, &map->player.team, (Enemy*)map->player.currentEntity);
        }



    }
}


#endif //PRESETTHREAD_H