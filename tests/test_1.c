#include <windows.h>

// Função para carregar uma imagem BMP
HBITMAP LoadBitmapImage(LPCSTR path) {
    return (HBITMAP)LoadImageA(NULL, path, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

// Função de callback para processar mensagens da janela
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    static HBITMAP hBitmap = NULL;
    switch (uMsg) {
        case WM_CREATE:
            // Carregar a imagem BMP
            hBitmap = LoadBitmapImage("aaa.png");
            if (hBitmap == NULL) {
                MessageBox(hwnd, "Não foi possível carregar a imagem.", "Erro", MB_OK);
                return -1;
            }
            break;

        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            // Criar DC compatível e selecionar a imagem BMP
            HDC hdcMem = CreateCompatibleDC(hdc);
            SelectObject(hdcMem, hBitmap);

            // Obter as dimensões da imagem
            BITMAP bitmap;
            GetObject(hBitmap, sizeof(BITMAP), &bitmap);

            // Copiar a imagem para o contexto de dispositivo da janela
            BitBlt(hdc, 0, 0, bitmap.bmWidth, bitmap.bmHeight, hdcMem, 0, 0, SRCCOPY);

            // Limpar recursos
            DeleteDC(hdcMem);
            EndPaint(hwnd, &ps);
            break;
        }

        case WM_DESTROY:
            DeleteObject(hBitmap);
            PostQuitMessage(0);
            break;

        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Registrar a classe da janela
    const char CLASS_NAME[] = "JanelaComImagem";

    WNDCLASS wc = { };
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    // Criar a janela
    HWND hwnd = CreateWindowEx(
        0,
        CLASS_NAME,
        "Janela com Imagem",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    if (hwnd == NULL) {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    // Loop de mensagens
    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
