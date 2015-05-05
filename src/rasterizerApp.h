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
    
    HINSTANCE appInst()const;
    HWND mainWnd() const;
    
    bool initMainWindow();
    int run();
    void render();

    LRESULT  MsgProc (HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

private:
    HINSTANCE hInst;
    HWND hWnd;
    WNDCLASSEX wcex;
};

#endif // RASTERIZERAPP_H