#include "rasterizerApp.h"

using namespace std;

namespace
{
    rasterizerApp *myRasterizerApp = 0;
}

LRESULT CALLBACK
MainWndProc (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    return myRasterizerApp -> MsgProc(hWnd, msg, wParam, lParam);
}

bool rasterizerApp::initMainWindow()
{
    wcex.cbSize                 = sizeof(WNDCLASSEX);
    wcex.style                   = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc        = MainWndProc;
    wcex.cbClsExtra           = 0;
    wcex.cbWndExtra        = 0;
    wcex.hInstance             = hInst;
    wcex.hIcon                    = LoadIcon(hInst, MAKEINTRESOURCE(IDI_APPLICATION));
    wcex.hCursor                = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground    = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName    = NULL;
    wcex.lpszClassName   = _T("MainWindow");
    wcex.hIconSm               = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));   

    if (!RegisterClassEx(&wcex))
    {
        MessageBox(NULL, _T("Call to RegisterClassEx failed!"), _T("Win32 Guided Tour"), NULL);
        return false;
    }

    hWnd = CreateWindow(
        _T("MainWindow"),
        _T("Rasterizer"),
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        500, 100,
        NULL,
        NULL,
        hInst,
        NULL
    );

    if (!hWnd)
    {
        MessageBox(NULL, _T("Call to CreateWindow failed!"), _T("Win32 Guided Tour"), NULL);
        return false;
    }
    ShowWindow(hWnd, SW_SHOW);
    UpdateWindow(hWnd);

    return true;
}

LRESULT  MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc;
    TCHAR greeting[] = _T("Hello, World!");
    switch (msg)
    {
    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);

        TextOut(hdc,
            5, 5,
            greeting, _tcslen(greeting));

        EndPaint(hWnd, &ps);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        break;
    }

    return  DefWindowProc(hWnd, msg, wParam, lParam);
}

int rasterizerApp::run() 
{
        // Main message loop:
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int) msg.wParam;

}

void rasterizerApp::render()
{}
