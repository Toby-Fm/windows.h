#include <iostream>
#include <tchar.h>
#include <Windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lparam) {
	switch (uMsg) {
		case WM_PAINT: {
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hwnd, &ps);
			//ALl painting occur here, between BeginPaint and Endpaint.
			FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));
			EndPaint(hwnd,&ps);
		}
		case WM_CLOSE: {
			DestroyWindow(hwnd);
			break;
		}
		case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}
		return 0;
	}
	return DefWindowProc(hwnd, uMsg, wParam, lparam);
}

int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance, LPSTR pCmdline, int nCmdShow) {	
	//RegisterClass
	const wchar_t WindowClass[] = L"WindowFensterKlasse";
	
	WNDCLASS wc = { };

	wc.lpfnWndProc		= DefWindowProc;
	wc.hInstance 		= hinstance; 					//Aktuelle Instanz des Programms
	wc.lpszClassName 	= "WindowClass"; 				//Name der Fensterklasse
	wc.hIcon 			= LoadIcon(NULL, IDI_ERROR); 	//Anwendungssymbol
	wc.style 			= CS_VREDRAW | CS_HREDRAW; 		//Fensterstyle Definition
	wc.hbrBackground 	= (HBRUSH)(COLOR_WINDOW + 3); 	//Hintergrund farbe des Fensters (1 = Weiß, 2 = Grau, 3 = Schwarz)
	wc.cbWndExtra		= 0; 							//Keine zusätlichen Klasseninformationen
	wc.cbClsExtra		= 0; 							//Keine zusätlichen Fentserinformationen
	
	RegisterClass(&wc);

	//Erstellen des Hauptfensters
	HWND hwnd = CreateWindowExW(
		0,
		L"WindowClass", //Name der Klasse
		L"Titel",  //Titel des Fensters
		WS_OVERLAPPEDWINDOW, //Stil
		//Größe und Position
		CW_USEDEFAULT,
		CW_USEDEFAULT, 
		1920, //Breite des Fensters
		1080, //Höhe des Fensters
		NULL, //Parent Window
		NULL, //Handle für das Menü
		hinstance, //Application Instance
		NULL //Extra Data
	);
	if (hwnd == NULL) {
		return 0;
	}

	//Anzeigen des Hauptfensters
	ShowWindow(hwnd, nCmdShow);

	//run the message loop
	MSG msg{ };
	while (GetMessage(&msg, NULL, 0, 0) > 0) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}