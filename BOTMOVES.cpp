#include <Windows.h>
#include <iostream>

int main()
{
	SetConsoleTitle("BOT MOVES (BY : SRNAJA)");

	char key, key2;
	char* name = new char[50];
	std::cout << "DIGITE O NOME DA JANELA DO POKETIBIA : " << std::endl;
	std::cin >> name;
	std::system("cls");
	std::cout << "DIGITE A KEY QUE VOCE DESEJA LIGAR O BOT:" << std::endl;
	std::cin >> key;
	std::system("cls");
	std::cout << "DIGITE A KEY QUE VOCE DESEJA DESLIGAR O BOT:" << std::endl;
	std::cin >> key2;
	std::system("cls");
	HWND window = 0x00, window_ = 0x00;

	while (true) {
		window = FindWindow(name, NULL);
		if (window) {
			window_ = GetForegroundWindow();
			if (window == window_) {
				if (GetAsyncKeyState(toupper(key2))) {
					keybd_event(VK_F1, NULL, KEYEVENTF_KEYUP, NULL);
					keybd_event(VK_F2, NULL, KEYEVENTF_KEYUP, NULL);
					keybd_event(VK_F3, NULL, KEYEVENTF_KEYUP, NULL);
					keybd_event(VK_F4, NULL, KEYEVENTF_KEYUP, NULL);
					keybd_event(VK_F5, NULL, KEYEVENTF_KEYUP, NULL);
					keybd_event(VK_F6, NULL, KEYEVENTF_KEYUP, NULL);
					keybd_event(VK_F7, NULL, KEYEVENTF_KEYUP, NULL);
					keybd_event(VK_F8, NULL, KEYEVENTF_KEYUP, NULL);
					keybd_event(VK_F9, NULL, KEYEVENTF_KEYUP, NULL);
					keybd_event(VK_F10, NULL, KEYEVENTF_KEYUP, NULL);
					std::system("cls");
					std::cout << "BOT PARADO!" << std::endl;
				}
				if (GetAsyncKeyState(toupper(key))) {
					keybd_event(VK_F1, NULL, NULL, NULL);
					keybd_event(VK_F2, NULL, NULL, NULL);
					keybd_event(VK_F3, NULL, NULL, NULL);
					keybd_event(VK_F4, NULL, NULL, NULL);
					keybd_event(VK_F5, NULL, NULL, NULL);
					keybd_event(VK_F6, NULL, NULL, NULL);
					keybd_event(VK_F7, NULL, NULL, NULL);
					keybd_event(VK_F8, NULL, NULL, NULL);
					keybd_event(VK_F9, NULL, NULL, NULL);
					keybd_event(VK_F10, NULL, NULL, NULL);
					std::system("cls");
					std::cout << "BOT iniciado!" << std::endl;
				}
			}
			else {
				std::system("cls");
				std::cout << "BOT PARADO!" << std::endl;
			}
		}
	}

	return 0;
}

