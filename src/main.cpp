#include "include/main.hpp"

// Die Hauptfunktion des Programms
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lCmdLine, int nCmdShow) {
	WNDCLASSEX wc;
	HWND hwnd;
	MSG msg;

	//Definieren des Fensterklassennamens
	//const wchar_t g_szClassName[] = L"myWindowClass";
	const wchar_t winClass[] = L"WindowClass";

	//Initialisieren der Fensterklassenstruktur
	wc.cbSize = sizeof(WNDCLASSEX); // Größe der Struktur setzen
	wc.lpfnWndProc		= WndProc;
	wc.hInstance		= hInstance;					//Aktuelle Instanz des Programms
	wc.lpszClassName	= "winClass";					//Name der Fensterklasse
	wc.style			= CS_VREDRAW | CS_HREDRAW;		//Fensterstyle Definition
	wc.hbrBackground	= (HBRUSH)(COLOR_WINDOW + 2);	//Hintergrund farbe des Fensters (1 = Weiß, 2 = Grau, 3 = Schwarz)
	wc.hIcon			= LoadIcon(NULL, IDI_ERROR);	//Anwendungssymbol
	wc.hCursor			= LoadCursor(NULL, IDC_ARROW);	//Mauszeigersymbol
	wc.hIconSm			= LoadIcon(NULL, IDI_APPLICATION); //Kleines Anwendungssymbol laden
	wc.cbWndExtra		= 0;							//Keine zusätlichen Klasseninformationen
	wc.cbClsExtra		= 0;							//Keine zusätlichen Fentserinformationen
	wc.lpszMenuName		= NULL;							// Kein Menü in der Titelleiste

	// Registrieren der Fensterklasse
	if (!RegisterClassEx(&wc)) {
		// Wenn die Registrierung fehlschlägt, wird eine Fehlermeldung angezeigt
		MessageBoxW(NULL, L"Fehler beim Registrieren der Fensterklasse", L"Fehler", MB_OK);
		return 0;
	}

	// Erstellen des Hauptfensters
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
		hInstance, //Application Instance
		NULL //Extra Data
	);
	if (hwnd == NULL) {
		// Wenn das Erstellen des Hauptfensters fehlschlägt, wird eine Fehlermeldung angezeigt
		MessageBoxW(NULL, L"Fehler beim Erstellen des Hauptfensters", L"Fehler", MB_OK);
		return 0;
	}

	// Hinzufügen eines Buttons zum Fenster
	HWND button = ButtonCreator::Create(L"Button", 500, 500, 350, 150, 1, hwnd, hInstance);
	HWND button2 = ButtonCreator::Create(L"Button2", 500,700, 350, 150, 2, hwnd, hInstance);
	if (button == NULL) {
		// Wenn das Erstellen des Buttons fehlschlägt, wird eine Fehlermeldung angezeigt
		MessageBoxW(NULL, L"Fehler beim Erstellen des Buttons", L"Fehler", MB_OK);
		return 0;
	}

	// Anzeigen des Hauptfensters
	ShowWindow(hwnd, nCmdShow);
	//UpdateWindow(hwnd);

	// Nachrichtenschleife
	while (GetMessage(&msg, NULL, 0, 0) > 0) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}
