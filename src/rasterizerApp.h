#ifndef RASTERIZERAPP_H
#define RASTERIZERAPP_H

#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>

class rasterizerApp {
public:
    rasterizerApp(HINSTANCE hinstance) { hInst = hinstance; };
    vritual ~rasterizerApp();
    
    
    bool initMainWindow();
    int run();
    void render();

    LRESULT  MsgProc (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

private:
    HINSTANCE hInst;
    HWND hWnd;
    WNDCLASSEX wcex;
};

#endif // RASTERIZERAPP_H