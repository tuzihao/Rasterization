#include <iostream>
#include "rasterizerApp.h"
using namespace std;

int WINAPI WinMain ( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) 
{ 
    rasterizerApp mApp(hInstance);
    if (!mApp.initMainWindow()) return 0;

    return mApp.run();
}
