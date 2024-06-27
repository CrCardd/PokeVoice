#include "buildMap.h"


int main()
{
    int map[HEIGHT][LENGHT] = {{0}};
    system("color 50");


createLine(1, map, 0, 62, 10);
createLine(2, map, 25, 30, 15);

showMap(map);

return 0;
}
