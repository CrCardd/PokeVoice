#include <windows.h>

LRESULT WinProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM Param){
    
    return DefWindowProcA(hwnd, uMsg,wParam, Param);

}
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE a, PWSTR b, int nCmdShow) {
    WNDCLASSA class = {
        0,
        WinProc,
        0,
        0,
        hInstance,
        NULL,
        NULL,
        NULL,
        NULL,
        "NirsClass"
    };

    RegisterClassA(&class);

    HWND windowHandle = CreateWindow("NirsClass", "Hello", WS_CAPTION | WS_POPUP | WS_SYSMENU, 50, 50, 500, 500, NULL, NULL, hInstance, NULL);

    ShowWindow(windowHandle, nCmdShow);
    return 0;
};


