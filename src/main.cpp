#include "include/main.hpp"

int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance, LPSTR pCmdline, int nCmdShow) {
	HWND hwnd;
	//RegisterClass
	const wchar_t winClass[] = L"WindowClass";
	
	WNDCLASS wc;
	wc.lpfnWndProc		= DefWindowProc;
	wc.hInstance		= hinstance;					//Aktuelle Instanz des Programms
	wc.lpszClassName	= "winClass";					//Name der Fensterklasse
	wc.style			= CS_VREDRAW | CS_HREDRAW;		//Fensterstyle Definition
	wc.hbrBackground	= (HBRUSH)(COLOR_WINDOW + 2);	//Hintergrund farbe des Fensters (1 = Weiß, 2 = Grau, 3 = Schwarz)
	wc.hIcon			= LoadIcon(NULL, IDI_ERROR);	//Anwendungssymbol
	wc.hCursor			= LoadCursor(NULL, IDC_ARROW);	//Mauszeigersymbol
	wc.cbWndExtra		= 0;							//Keine zusätlichen Klasseninformationen
	wc.cbClsExtra		= 0;							//Keine zusätlichen Fentserinformationen

	RegisterClass(&wc);

	//Erstellen des Hauptfensters
	hwnd = CreateWindowExW(
		0,
		L"winClass", //Name der Klasse
		L"Haupt Fenster",  //Titel des Fensters
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
	if (hwnd == NULL) { //Wenn das Erstellen des Hauptfensters fehlschlägt, wird eine Fehlermeldung angezeigt
		MessageBoxW(NULL, L"Fehler beim Registrieren der Fensterklasse", L"Fehler", MB_OK);
		return 0;
	}

	//Button erzeugen
	HWND button = ButtonCreator::Create(L"Button", 500, 500, 150, 70, true, hwnd, hinstance);
	if (button == NULL) {//Wenn das Erstellen des Buttons fehlschlägt, wird eine Fehlermeldung angezeigt
		MessageBoxW(NULL, L"Fehler beim Erstellen des Buttons", L"Fehler", MB_OK);
		return 0;
	}
	//Anzeigen des Hauptfensters
	ShowWindow(hwnd, nCmdShow);

	MSG msg;
	//run the message loop
	while (GetMessage(&msg, NULL, 0, 0) > 0) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}