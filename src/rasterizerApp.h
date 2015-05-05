#ifndef RASTERIZERAPP_H
#define RASTERIZERAPP_H

#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>

class rasterizerApp {
public:
    rasterizerApp(HINSTANCE hinstance) { hInst = hinstance; };
    ~rasterizerApp();
    bool initMainWindow();
    int run();
    void render();

    LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM);

private:
    HINSTANCE hInst;
    WNDCLASSEX wcex;
};

#endif // RASTERIZERAPP_H