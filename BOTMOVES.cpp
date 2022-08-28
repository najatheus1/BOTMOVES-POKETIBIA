#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include <iostream>
#include <array>

#define S_ 30
#define TIME_POKEBAR 1700

std::array<char, 2>key{};

std::array<HWND, 2> window{};
std::array<POINT, 2> cursor{}; /*
								cursor[0] = cursor da pokebar
								cursor[1] = janela de batalha
								*/

std::array<int, 4> pox_pokebar{}; /*
						   pox[0] = pox_pokebar_x
						   pox[1] = pox_pokebar_x_backup
						   pox[2] = pox_pokebar_y
						   pox[3] = pox_pokebar_y_backup
						   */

std::array<int, 3> count{};/*
						   count[0] = define TIME_POKEBAR 2000
						   count[1] = quantidade de pokebolas que o jogador tem
						   count[2] = verifica se o jogador cofigurou o mouse
						   */

std::array<int, 2> v{};

void MousePokebar() {
	if (count[2] >= 1) {
		if (v[0] >= 1) {
			if (v[1] >= 1) {
				SetCursorPos(pox_pokebar[1], pox_pokebar[3]);
				mouse_event(0x0002, NULL, NULL, NULL, NULL);
				mouse_event(0x0004, NULL, NULL, NULL, NULL);
				Sleep(300);
				SetCursorPos(pox_pokebar[0], pox_pokebar[2]);
			}

			if (count[0] >= S_ * count[1]) {
				count[0] = S_;
				pox_pokebar[2] = cursor[0].y - count[0] + count[0];
				SetCursorPos(pox_pokebar[0], pox_pokebar[2]);
				mouse_event(0x0002, NULL, NULL, NULL, NULL);
				mouse_event(0x0004, NULL, NULL, NULL, NULL);
				Sleep(TIME_POKEBAR);
			}

			mouse_event(0x0002, NULL, NULL, NULL, NULL);
			mouse_event(0x0004, NULL, NULL, NULL, NULL);
			count[0] = count[0] + S_;
			std::cout << count[0] << std::endl;
			pox_pokebar[2] = cursor[0].y + count[0];
			SetCursorPos(pox_pokebar[0], pox_pokebar[2]);
			Sleep(TIME_POKEBAR);
			mouse_event(0x0002, NULL, NULL, NULL, NULL);
			mouse_event(0x0004, NULL, NULL, NULL, NULL);
		}
	}
}

int main()
{
	SetConsoleTitle("BOT MOVES (BY : SRNAJA)");

	char* name = new char[50];
	std::cout << "DIGITE O NOME DA JANELA DO POKETIBIA : " << std::endl;
	std::cin >> name;
	std::system("cls");
	std::cout << "Digite a quantidade de pokemons que voce tem no (" << name << ") :" << std::endl;
	std::cin >> count[1];
	std::system("cls");
	std::cout << "DIGITE A KEY QUE VOCE DESEJA LIGAR O BOT:" << std::endl;
	std::cin >> key[0];
	std::system("cls");
	std::cout << "DIGITE A KEY QUE VOCE DESEJA DESLIGAR O BOT:" << std::endl;
	std::cin >> key[1];
	std::system("cls");

	
	while (true) {
		window[0] = FindWindow(name, NULL);
		if (window[0]) {
			window[1] = GetForegroundWindow();
			if (window[0] == window[1]) {
				if (GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(VK_SHIFT) && GetAsyncKeyState(0x50)) {
					std::cout << "COLOQUE O MOUSE EM CIMA DA POKEBAR!" << std::endl;
					GetCursorPos(&cursor[0]);
					pox_pokebar[0] = cursor[0].x;
					pox_pokebar[2] = cursor[0].y;
					v[0] = 1;
					count[2] = 1;
				}

				if (GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(VK_SHIFT) && GetAsyncKeyState(0x42)) {
					std::cout << "COLOQUE O MOUSE EM CIMA DA JANELA DE BATALHA!" << std::endl;
					GetCursorPos(&cursor[1]);
					pox_pokebar[1] = cursor[1].x;
					pox_pokebar[3] = cursor[1].y;
					v[1] = 1;
					count[2] = 1;
				}

				MousePokebar();


				if (GetAsyncKeyState(toupper(key[1]))) {
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
					keybd_event(VK_F11, NULL, KEYEVENTF_KEYUP, NULL);
					keybd_event(VK_F12, NULL, KEYEVENTF_KEYUP, NULL);
					std::system("cls");
					std::cout << "BOT PARADO!" << std::endl;
					std::cout << "CLIQUE DA POKEBAR PARADO!" << std::endl;
					v[0] = 0;
					v[1] = 0;
				}

				if (GetAsyncKeyState(toupper(key[0]))) {
					v[0] = 1;
					v[1] = 1;
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
					keybd_event(VK_F11, NULL, NULL, NULL);
					keybd_event(VK_F12, NULL, NULL, NULL);
					MousePokebar();
					std::system("cls");
					std::cout << "BOT iniciado!" << std::endl;
				}
			}
			else {
				std::system("cls");
				std::cout << "BOT PARADO!" << std::endl;
				std::cout << "CLIQUE DA POKEBAR PARADO!" << std::endl;
				v[0] = 0;
				v[1] = 0;
			}
		}
	}

	return 0;
}

