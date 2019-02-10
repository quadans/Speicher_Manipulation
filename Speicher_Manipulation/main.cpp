#include <iostream>
#include <Windows.h>


int main()
{
	//int neuerWert = 100; Wenn Write statt auslesen s.u.
	int Auslese = 0;

	HWND hwnd = FindWindow(0, "AssaultCube");
	if (!hwnd)
	{
		std::cout << "nichts gefunden";
		Sleep(3000);
		exit(-1);
	}
	else
	{
		std::cout << "Fenster gefunden" << std::endl;

		DWORD procID;
		GetWindowThreadProcessId(hwnd, &procID);
		HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procID);

		if (!procID)
		{
			std::cout << "Prozess nicht gefunden." << std::endl;
			Sleep(3000);
			exit(-1);
		}
		else
		{
			//Aussuchen ob Lesen oder schreiben, Ausgabe unten ändert sich dann auch. 
			//WriteProcessMemory(handle,(LPVOID)0x00D5A4F8, &neuerWert,sizeof(neuerWert),0);
			ReadProcessMemory(handle, (PBYTE*)0x00D5A4F8, &Auslese, sizeof(int), 0);

			std::cout << Auslese << std::endl;
			//cout << "Wert wurde geaendert"<<endl;
		}
	}

}
