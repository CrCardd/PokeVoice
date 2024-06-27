#include "buildMap.h"


int main()
{
    int map[HEIGHT][LENGHT] = {{0}};
    system("color 50");


// buildLine(1, map, 0, 62, 10);
// buildLine(2, map, 25, 30, 15);
buildSquare(1, map, 10, 20, 25, 35);

// showMap(map);

return 0;
}
