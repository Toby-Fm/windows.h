#include "include/main.hpp"

// Die Hauptfunktion des Programms
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lCmdLine, int nCmdShow) {
	MSG msg;
	WNDCLASSEX wc;
	HWND hwnd;

	//HauptFenster
	wc.cbSize = sizeof(WNDCLASSEX); // Größe der Struktur setzen
	wc.lpfnWndProc		= WndProc;
	wc.hInstance		= hInstance;					//Aktuelle Instanz des Programms
	wc.lpszClassName	= "winClass";					//Name der Fensterklasse
	wc.style			= CS_VREDRAW | CS_HREDRAW;		//Fensterstyle Definition
	wc.hbrBackground	= (HBRUSH)(COLOR_WINDOW + 2);	//Hintergrund farbe des Fensters (1 = Weiß, 2 = Grau, 3 = Schwarz)
	wc.hIcon			= LoadIcon(NULL, IDI_ERROR);	//Anwendungssymbol
	wc.hCursor			= LoadCursor(NULL, IDC_ARROW);	//Mauszeigersymbol
	wc.hIconSm			= LoadIcon(NULL, IDI_ERROR); 	//Kleines Anwendungssymbol laden
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
		L"Warum ist das auf Chinesisch",  //Titel des Fensters
		WS_OVERLAPPEDWINDOW, //Stil
		//Größe und Position
		CW_USEDEFAULT,
		CW_USEDEFAULT, 
		620, //Breite des Fensters
		1080, //Höhe des Fensters
		NULL, //Parent Window
		NULL, //Handle für das Menü
		hInstance, //Application Instance
		NULL //Extra Data
	);
	if (hwnd == NULL) {
		// Wenn das Erstellen des Hauptfensters fehlschlägt, wird eine Fehlermeldung angezeigt
		MessageBoxW(NULL, L"Fehler beim Erstellen des Hauptfensters", L"Fehler", MB_OK | MB_ICONERROR);
		return 0;
	}

	//Hinzufügen von Buttons zum Hauptfenster
	HWND button = ButtonCreator::Create(L"Button1", 0, 0, 150, 70, 1, hwnd, hInstance);
	HWND button2 = ButtonCreator::Create(L"Button2", 150, 0, 150, 70, 2, hwnd, hInstance);
	HWND button3 = ButtonCreator::Create(L"Button3", 300, 0, 150, 70, 3, hwnd, hInstance);
	HWND button4 = ButtonCreator::Create(L"Button4", 450, 0, 150, 70, 4, hwnd, hInstance);
	if (button == NULL || button2 == NULL || button3 == NULL || button4 == NULL) {
		// Wenn das Erstellen des Buttons fehlschlägt, wird eine Fehlermeldung angezeigt
		MessageBoxW(NULL, L"Fehler beim Erstellen eines oder mehrerer Buttons", L"Fehler", MB_OK | MB_ICONERROR);
		return 0;
	}
	
	// Erstellen eines Texteingabefelds
	HWND TextField = TextFieldCreator::Create(L"Textfield", 0, 70, 600, 70, 3, hwnd, hInstance);
	//HWND TextField = CreateWindowW(L"EDIT", L"Textfield", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | ES_MULTILINE | ES_WANTRETURN, 0, 70, 600, 70, hwnd, NULL, NULL, NULL);
	if (TextField == NULL) {
		MessageBoxW(hwnd, L"Fehler beim Erstellen des Texteingabefelds", L"Fehler", MB_OK | MB_ICONERROR);
		return 0;
	}

	// Anzeigen des Hauptfensters
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	// Nachrichtenschleife
	while (GetMessage(&msg, NULL, 0, 0) > 0) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}