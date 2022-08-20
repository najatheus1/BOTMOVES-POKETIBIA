#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include <string>
#include <iostream>

std::string getLocalTime() {
	time_t time_;

	std::time(&time_);
	tm* s = localtime(&time_);

	std::string time__ = std::to_string(s->tm_mday) + "/" + std::to_string(s->tm_mon + 1) +
		"/" + std::to_string(s->tm_year + 1900) + " [Horas:" + std::to_string(s->tm_hour) +
		" Minutos: " + std::to_string(s->tm_min) + " Segundo: " + std::to_string(s->tm_sec) +
		+"]";

	return time__;
}

int main()
{
	SetConsoleTitle("BOT MOVES (BY : SRNAJA)");

	char key;
	char* name = new char[50];
	std::cout << "DIGITE O NOME DA JANELA DO POKETIBIA : " << std::endl;
	std::cin >> name;
	std::system("cls");
	std::cout << "DIGITE A KEY:" << std::endl;
	std::cin >> key;
	std::system("cls");
	HWND window = 0x00, window_ = 0x00;

	while (true) {
		window = FindWindow(name, NULL);
		if (window) {
			window_ = GetForegroundWindow();
			if (window == window_) {
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
					std::cout << getLocalTime() << "ATAQUE CONCLUIDO" << std::endl;
				}
			}
		}
	}

	return 0;
}

