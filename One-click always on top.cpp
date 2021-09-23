#include <Windows.h>
#include <iostream>
using namespace std;
#define ID 1

int main() {
    // 注册热键 ~
    if (0 == RegisterHotKey(NULL, ID, NULL, VK_OEM_3)) {
        cout << "RegisterHotKey error : " << GetLastError() << endl;
        system("pause");
        return 0;
    }
    cout << "Please switch to a window" << endl;
    cout << "Then click '~' on your keyboard and the window will be always on top" << endl;
    MSG msg = { 0 };
    while (GetMessage(&msg, NULL, 0, 0)) {
        if (WM_HOTKEY == msg.message && ID == msg.wParam) {
            HWND h = GetForegroundWindow();
            if (SetWindowPos(h, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE + SWP_NOSIZE)) {
                cout << "Success!" << endl;
            }
            else {
                cout << "Fail!" << endl;
            }
            UnregisterHotKey(NULL, ID);
            Sleep(3000);
            break;
        }
    }
    return 0;
}