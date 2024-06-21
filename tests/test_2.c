#include "../headers/headers.h"
#include "../headers/draw.c"

HANDLE Thread;
DWORD ThreadID;

DWORD WINAPI MainThread(LPVOID lpParam)
{
    HWND hwnd = *((HWND*) lpParam);

    int x = 10;
    int y = 10;
    wchar_t * img = L"images/criamander.bmp";

    SetThreadPriority(Thread, 2);


    SendMessage(hwnd, WM_SETREDRAW, FALSE, 0);
    HDC hdc = GetDC(hwnd);
    DrawImg(hdc, 0, 0, 960, 720, L"imagens/background.bmp");
    SendMessage(hwnd, WM_SETREDRAW, TRUE, 0);



    //====================
    DrawImg(hdc, 480, 360, 100, 80, img);
    //====================


    Sleep(20);
    ReleaseDC(hwnd, hdc);
    
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
    switch(Msg)
    {
        case WM_SETREDRAW:
        {

        }
        break;
        case WM_PAINT:
        {
            PAINTSTRUCT PS;
            HDC hdc = BeginPaint(hwnd, &PS);
            HBRUSH hBrush = CreateSolidBrush(RGB(255,255,255));                      // *
            FillRect(hdc, &PS.rcPaint,hBrush);
            //DrawImg(hdc, 0, 0, 960, 720, L"imagens/BackGround.bmp");
            EndPaint(hwnd, &PS);
            DeleteObject(hBrush);                                                    // *
        }
        break;
        case WM_CLOSE:
            DestroyWindow(hwnd);
        break;
        case WM_DESTROY:
            PostQuitMessage(0);
        break;
        default:
            return DefWindowProc(hwnd, Msg, wParam, lParam);
    }
    return 0;
}



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    const wchar_t WClassName[]  = L"POKE";
    MSG Msg;
    WNDCLASS Window = {};
    Window.lpfnWndProc = WndProc;
    Window.hInstance = hInstance;
    Window.lpszClassName = WClassName;


    if(!RegisterClass(&Window))
    {
        MessageBox(NULL, L"Window Class Registration Failed", L"Error", MB_ICONERROR | MB_OK);
        return 0;
    }

    HWND hwnd = CreateWindowEx
    (
        0,
        WClassName,
        L"TESTE_2",
        WS_OVERLAPPEDWINDOW,
        200, 10, 975, 720,
        NULL, NULL, hInstance, NULL
    );

    if(hwnd == NULL)
    {
        MessageBox(NULL, L"Window Creation Failed", L"Error", MB_ICONERROR | MB_OK);
        return 0;
    }

    HICON hIcon = (HICON)LoadImage(NULL, L"images/icone", IMAGE_ICON, 32, 32, LR_LOADFROMFILE);                         // *
    
    if (hIcon != NULL) {
        // Definindo o ícone grande da janela
        SendMessage(hwnd, WM_SETICON, ICON_BIG, (LPARAM)hIcon);
        // Definindo o ícone pequeno da janela
        SendMessage(hwnd, WM_SETICON, ICON_SMALL, (LPARAM)hIcon);
    } else {
        MessageBox(NULL, L"Erro ao carregar o icone!", L"Erro", MB_ICONERROR);
    }
    
    
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    Thread = CreateThread(NULL, 0, MainThread, &hwnd, 0, &ThreadID);

    while(GetMessage(&Msg, NULL, 0, 0))
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return 0;
}
