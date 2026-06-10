#pragma once

#include <windows.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }

    return DefWindowProc(hwnd, msg, wParam, lParam);
}

HWND CreateAppWindow(const char* name)
{
    HINSTANCE instance = GetModuleHandle(NULL);

    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WndProc;
    wc.hInstance = instance;
    wc.lpszClassName = name;

    RegisterClass(&wc);

    HWND window = CreateWindowEx(
        0,
        name,
        name,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        800,
        600,
        NULL,
        NULL,
        instance,
        NULL
    );

    ShowWindow(window, SW_SHOW);

    return window;
}

int HandleAppWindow(void)
{
    MSG msg;
    int running = 1;

    while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
    {
        if (msg.message == WM_QUIT)
            running = 0;

        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return running;
}