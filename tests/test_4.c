#include <stdio.h>
#include <math.h>

#define M_PI 3.14159265358979323846


int main(){

    for(int i=0; i<4; i++)
    {
        int lin =sin(i*0.5* M_PI);
        int col =cos(i*0.5* M_PI);
        printf("sin: %d cos: %d\n",lin,col);    
    }
}