#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


HANDLE Thread;
HANDLE Thread2;
HANDLE Mutex;

DWORD Something()
{
    for (int i = 0; i < 15; i++)
    {
        WaitForSingleObject(Mutex, INFINITE); 

        printf("%d\n",i);
        Sleep(1000);

        ReleaseMutex(Mutex);
    }
    return 0;          
}

DWORD Outro()
{
    for (int i = 0; i < 15; i++)
    {
        WaitForSingleObject(Mutex, INFINITE); 

        printf("eduardo\n");    
        Sleep(1000);

        ReleaseMutex(Mutex);
    }   
    return 0;      
}


int main(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

    Mutex = CreateMutex(NULL, FALSE, NULL);

    Thread = CreateThread(NULL, 0, Something, NULL, 0, NULL);
    Thread2 = CreateThread(NULL, 0, Outro, NULL, 0, NULL);

    WaitForSingleObject(Thread,Something);
    WaitForSingleObject(Thread2,Outro);

     CloseHandle(Mutex);
}
