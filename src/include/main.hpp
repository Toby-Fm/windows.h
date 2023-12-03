#include <iostream>
#include <Windows.h>
#include <WinUser.h>
#include <string>
#include <CommCtrl.h> // Für Steuerelemente wie Textfelder

#define BUTTON_ID_OFFSET    100
#define TEXTFIELD_ID_OFFSET 200

class ButtonCreator { //Classe für die Erstellung von Buttons
public:
	static HWND Create(LPCWSTR buttonText, int x, int y, int width, int height, int id, HWND hwnd, HINSTANCE hInstance) {
		return CreateWindowW(
			L"BUTTON",
			buttonText,
			WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			x, 
			y, 
			width, 
			height,
			hwnd,
			(HMENU)IntToPtr(id + BUTTON_ID_OFFSET),
			hInstance,
			NULL
		);
	}
};

class TextFieldCreator {//Classe für die Erstellung eines Input  Textfeldes
public:
	static HWND Create(LPCWSTR Text, int x, int y, int width, int height, int id, HWND hwnd, HINSTANCE hInstance) {
		return CreateWindowW(
			L"EDIT",
			Text,
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | ES_AUTOVSCROLL | ES_MULTILINE | ES_WANTRETURN,
			x,
			y,
			width,
			height,
			hwnd,
			(HMENU)IntToPtr(id + TEXTFIELD_ID_OFFSET),
			hInstance,
			NULL
		);
	}
};

// Die Window Procedure-Funktion, die Nachrichten für unser Fenster verarbeitet
LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg) {
		case WM_CLOSE: {
			PostQuitMessage(0); //Sendet eine "Beenden-Nachricht" an die schleife
			break;
		}
		case WM_DESTROY: {
			DestroyWindow(hwnd); //Zerstört das Fenster
			break;
		}
		case WM_COMMAND: {
			int buttonID = LOWORD(wParam);
			switch(buttonID) {
				case (1 + BUTTON_ID_OFFSET): {
					MessageBeep(MB_DEFBUTTON1);
					MessageBoxW(hwnd, L"der Button 1 wurde geklickt!", L"Button-Klick", MB_OK);
					break;
				}
				case (2 + BUTTON_ID_OFFSET): {
					MessageBeep(MB_ICONERROR);
					MessageBoxW(hwnd, L"der Button 2 wurde geklickt!", L"Button-Klick", MB_OK);
					break;
				}
				case (3 + BUTTON_ID_OFFSET): {
					MessageBeep(MB_ERR_INVALID_CHARS);
					MessageBoxW(hwnd, L"der Button 3 wurde geklickt!", L"Button-Klick", MB_OK);
					break;
				}
				case (4 + BUTTON_ID_OFFSET): {
					MessageBeep(MB_ICONASTERISK);
					MessageBoxW(hwnd, L"der Button 4 wurde geklickt!", L"Button-Klick", MB_OK);
					break;
				}
			}
			break;
		}
		case WM_CREATE: {
			break;
		}
		default: {
			return DefWindowProcW(hwnd, uMsg, wParam, lParam);
		}
	}
	return 0;
}