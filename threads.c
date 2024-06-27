#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


HANDLE Thread;
HANDLE Thread2;

DWORD Something()
{
    for (int i = 0; i < 5; i++)
    {
        int n;
        scanf("%d", &n);
        Sleep(1000);
    }
    return 0;          
}

DWORD Outro()
{
    for (int i = 0; i < 15; i++)
    {
        printf("eduardo\n");    
        Sleep(1000);
    }   
    return 0;      
}


int main(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    Thread = CreateThread(NULL, 0, Something, NULL, 0, NULL);
    Thread2 = CreateThread(NULL, 0, Outro, NULL, 0, NULL);

    WaitForSingleObject(Thread,Something);
    WaitForSingleObject(Thread2,Outro);
}
