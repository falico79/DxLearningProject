#include "Window.h"

int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    PSTR lpCmdLine,
    int nCmdShow )
{
    Window wnd(800, 300, L"Test Program");

    // message pump
    MSG msg;
    BOOL gResult;
    while ( (gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    if (gResult == -1)
    {
        return -1;
    }
    else
    {
        return msg.wParam;
    }
}