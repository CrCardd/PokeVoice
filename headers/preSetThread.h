#ifndef PRESETTHREAD_H
#define PRESETTHREAD_H

#include <pthread.h>
#include "render.h"
#include "main.h"
#include "moves.h"


pthread_mutex_t mutex;

void * showMapThread(void* arg)
{
    Map *game = (Map*)arg;
    while(1)
    {
        pthread_mutex_lock(&mutex);
        showMap(game);
        pthread_mutex_unlock(&mutex);
    }
}


void * actionsThread(void* arg)
{
    Map *game = (Map*)arg;
    while(1)
    {
        pthread_mutex_lock(&mutex);
        checkWalk(game);
        checkInteract(game);
        pthread_mutex_unlock(&mutex);
    }
}

#endif //PRESETTHREAD_H