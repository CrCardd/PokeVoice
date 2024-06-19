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
        // printf("Something\n");
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


// LRESULT CALLBACK WndProc(HWND hwnd, UINT Msg, WPARAM wParam, LPARAM lParam)
// {
//     switch(Msg)
//     {
//         case WM_PAINT:
//         {
//             PAINTSTRUCT PS;
//             HDC hdc = BeginPaint(hwnd, &PS);
//             EndPaint(hwnd, &PS);
//         }
//         break;
//         case WM_CLOSE:
//             DestroyWindow(hwnd);
//         break;
//         case WM_DESTROY:
//             PostQuitMessage(0);
//         break;
//         default:
//             return DefWindowProc(hwnd, Msg, wParam, lParam);
//     }
//     return 0;
// }

// int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
// {
//     const wchar_t WClassName[]  = L"Terraria 2";
//     MSG Msg;
//     WNDCLASS Window = {};
//     Window.lpfnWndProc = WndProc;
//     Window.hInstance = hInstance;
//     Window.lpszClassName = WClassName;

//     if(!RegisterClass(&Window))
//     {
//         MessageBox(NULL, L"Window Class Registration Failed", L"Error", MB_ICONERROR | MB_OK);
//         return 0;
//     }

//     HWND hwnd = CreateWindowEx
//     (
//         0,
//         WClassName,
//         L"Terraria 2",
//         WS_OVERLAPPEDWINDOW,
//         200, 10, 960, 720,
//         NULL, NULL, hInstance, NULL
//     );
//     if(hwnd == NULL)
//     {
//         MessageBox(NULL, L"Window Creation Failed", L"Error", MB_ICONERROR | MB_OK);
//         return 0;
//     }
//     ShowWindow(hwnd, nCmdShow);
//     UpdateWindow(hwnd);



//     while(GetMessage(&Msg, NULL, 0, 0))
//     {
//         TranslateMessage(&Msg);
//         DispatchMessage(&Msg);
//     }

// }


int main(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    Thread = CreateThread(NULL, 0, Something, NULL, 0, NULL);
    Thread2 = CreateThread(NULL, 0, Outro, NULL, 0, NULL);

    WaitForSingleObject(Thread,Something);
    WaitForSingleObject(Thread2,Outro);
}
