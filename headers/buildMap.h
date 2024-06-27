#ifndef BUILDMAP_H
#define BUILDMAP_H

#define LENGHT 79
#define HEIGHT 63



void buildSquare(int map[HEIGHT][LENGHT], int coordY, int coordX, int coordY_, int coordX_)
{
    int lenght = coordX_ - coordX;
    int height = coordY_ - coordY;
    int biggest = (height>lenght)?height:lenght;
    printf("biggest: %d  lenght: %d height: %d\n\n",biggest,lenght,height);
    for(float i=0; i<=biggest; i++)
    {
        printf("i: %f  conf: %d\n\n",i,(int)((i/biggest)*lenght));
        map[coordY + (int)((i/biggest)*height)][coordX] = 1;
        map[coordY_ - (int)((i/biggest)*height)][coordX_] = 1;
        map[coordY][coordX + (int)((i/biggest)*lenght)] = 1;
        map[coordY_][coordX_ - (int)((i/biggest)*lenght)] = 1;
    }
}




#endif