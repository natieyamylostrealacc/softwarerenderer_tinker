#include <stdint.h>

#include "winhandling.h"

uint32_t framebuffer[800 * 600];

void ClearScreen(uint32_t);
void RenderBuffer(HWND);

void toBuff(void) {
    for (int y = 0; y < 600; y++) {
        for (int x = 0; x < 800; x++) {
            if (x > 200 && y > 150 && y < 300 && x < 400) {
                framebuffer[y * 800 + x] = 0x00FF0000;
            }
        }
    }
}

int main() {
    HWND win = CreateAppWindow("Hello!");

    int running = 1;

    while (running == 1) {
        running = HandleAppWindow();

        ClearScreen(0x000000);

        toBuff();

        RenderBuffer(win);
    }

    return 0;
}

void ClearScreen(uint32_t color) {
    for (int i = 0; i < 800 * 600; i++) {
        framebuffer[i] = color;
    }
}

void RenderBuffer(HWND window) {
    BITMAPINFO bmi = { 0 };
    bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    bmi.bmiHeader.biWidth = 800;
    bmi.bmiHeader.biHeight = -600;
    bmi.bmiHeader.biPlanes = 1;
    bmi.bmiHeader.biBitCount = 32;
    bmi.bmiHeader.biCompression = BI_RGB;

    HDC hdc = GetDC(window);

    StretchDIBits(
        hdc,
        0, 0, 800, 600,
        0, 0, 800, 600,
        framebuffer,
        &bmi,
        DIB_RGB_COLORS,
        SRCCOPY
    );

    ReleaseDC(window, hdc);
}