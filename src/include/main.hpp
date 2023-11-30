#include <iostream>
#include <tchar.h>
#include <Windows.h>
#include <WinUser.h>
#include <string>
#include <CommCtrl.h>

//HWND g_hInputField = NULL;
HWND g_hButton = NULL;

class ButtonCreator {
public:
    static HWND Create(LPCWSTR buttonText, int x, int y, int width, int height, boolean id, HWND parentWnd, HINSTANCE hInstance) {
        return CreateWindowW(
            L"BUTTON",
            buttonText,
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, // Fügen Sie hier BS_DEFPUSHBUTTON hinzu
            x, y, width, height,
            parentWnd,
            (HMENU)1,
            hInstance,
            NULL
        );
    }
};


LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg) {
		case WM_CLOSE: {
			DestroyWindow(hwnd); //Zerstört das Fenster
			break;
		}
		case WM_DESTROY: {
			PostQuitMessage(0); //Sendet eine "Beenden-Nachricht" an die schleife
			break;
		}
		case WM_COMMAND: {
			OutputDebugString("WM_COMMAND received\n");
			if (LOWORD(wParam) == 1) {
				MessageBoxW(hwnd, L"der Button wurde geklickt!", L"Button-Klick", MB_OK);
				break;
			}
			break;
		}
		case WM_CREATE: {
			OutputDebugString("WM_CREATE received\n");
			//HWND button = ButtonCreator::Create(L"Button erzeugen", 500, 500, 150, 70, true, hwnd, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE));
			break;
		}
		break;
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}