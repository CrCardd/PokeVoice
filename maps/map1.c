#include "buildMap.h"
#include "create.h"

int main()
{
Player player = playerInnit(0,0);
Map map = gameInnit(63,79, player);

buildLine(1,&map, 0, 0, 79);
buildLine(1,&map, 0, 62, 79);
buildLine(2,&map, 0, 0, 62);
buildLine(2,&map, 78, 0, 62);

// buildSquare(1, &map, 0, 0, 24, 36);

buildLine(2,&map, 29, 0, 24);

buildLine(1, &map, 0, 24, 78);
buildLine(2, &map, 58, 0, 24);

buildLine(2, &map, 20, 24, 33);
buildLine(1, &map, 20, 54, 15);
buildLine(2, &map, 35, 24, 38);

buildLine(1, &map, 50, 45, 28);
buildLine(2, &map, 50, 24, 26);


showMap(&map);
}

