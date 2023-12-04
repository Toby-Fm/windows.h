#include <iostream>
#include <Windows.h>
#include <WinUser.h>
#include <string>
#include <CommCtrl.h> // Für Steuerelemente wie Textfelder

#define BUTTON_ID_OFFSET    100
#define TEXTFIELD_ID_OFFSET 200

HINSTANCE hInstance;

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