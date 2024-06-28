// /* Compile:
// gcc main.c -o Poke.exe -l gdi32 -l msimg32
// */

// #include "headers/headers.h"



// int main()
// {
//     pthread_t showMapThreads,checkWalkThreads;

//     configureTerminal();

//     Player player = playerInnit(PLAYER,15,15);
//     Map game = gameInnit(ROWS, COLLUMS, player,WALLS,POKEBALL);
//     buildSquare(&game, 10,10,50,50);
    

//     pthread_mutex_init(&mutex, NULL);

//     pthread_create(&showMapThreads, NULL, actionsThread, (void*)&game);
//     pthread_create(&showMapThreads, NULL, showMapThread, (void*)&game); 
//     pthread_join(checkWalkThreads, NULL);
//     pthread_join(showMapThreads, NULL);

//     pthread_mutex_destroy(&mutex);

//     return 0;

// }
