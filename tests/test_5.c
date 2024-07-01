#include <stdio.h>

void ptrValue(int * a)
{
    *a = 10;
}


int main()
{
    int b = 3;
    ptrValue(&b);
    printf("%d",b);
}