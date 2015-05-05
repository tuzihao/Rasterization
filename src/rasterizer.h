#ifndef  RASTERIZER_H
#define RASTERIZER_H

#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>

class rasterizerApp {
public:
    rasterizerApp(HINSTANCE hinstance) { hInst = hinstance};
    ~rasterizerApp();
    bool initMainWindow();
    int run();
    void render();

    TCHAR szWindowClass[] = _T("MainWindow");
    TCHAR szTitle[] = _T("Rasterizer");

    LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM);

private:
    HINSTANCE hInst;
    WNDCLASSEX wcex;
};

#endif // RASTERIZER_H