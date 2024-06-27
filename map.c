#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

#define HEIGHT 63
#define LENGHT 79
#define CHARACTER Ω;


int main()
{
    system("color 50");
    int map[HEIGHT][LENGHT] = {{0}};

// createLine(1, map, 0, 62, 10);
createLine(2, map, 25, 30, 15);

showMap(map);


return 0;
}
