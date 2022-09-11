#define _CRT_SECURE_NO_WARNINGS
#define SIZE_POKEBAR 45

#include <Windows.h>
#include <iostream>
#include <array>

POINT cursor;
HDC dc;
char* name = new char[50];

std::array<char, 3>key{};

std::array<HWND, 2> window{};

std::array<int, 6> pos{}; /*
						   pos[0] = pos_pokebar_x
						   pos[1] = pos_janela_combate_x
						   pos[2] = pos_pokebar_y
						   pos[3] = pos_janela_combate_y
						   */

std::array<int, 2> count{};/*
						   count[0] = define TIME_POKEBAR 2000
						   count[1] = quantidade de pokebolas que o jogador tem
						   */

void __BOT__(void);
void ATAQUE_KEYBOARD(void);
void D_ATAQUE_KEYBOARD(void);
void _CALLBACK_(void);
void ClickCursor(int count_click);
void ATAQUE_TARGET(void);
void TROCA_POKEMON(void);
void marcador(int pox_x, int pos_y);
void BACKUP_CURSOR(void);

int main()
{
	for (std::size_t i = 0; i <= 5; ++i) {
		pos[i] = 0x0;
	}

	SetConsoleTitle("BOT MOVES (BY : SRNAJA)");
	std::cout << "DIGITE O NOME DA JANELA DO POKETIBIA : " << std::endl;
	std::cin >> name;
	std::system("cls");
	std::cout << "Digite a quantidade de pokemons que voce tem no (" << name << ") :" << std::endl;
	std::cin >> count[1];
	std::system("cls");
	std::cout << "DIGITE A KEY QUE VOCE DESEJA LIGAR O BOT:" << std::endl;
	std::cin >> key[0];
	std::system("cls");
	std::cout << "DIGITE A KEY QUE VOCE DESEJA DAR O TARGET DO BOT:" << std::endl;
	std::cin >> key[1];
	std::system("cls");
	std::cout << "DIGITE A KEY QUE VOCE DESEJA PARAR O BOT:" << std::endl;
	std::cin >> key[2];
	std::system("cls");

	while (pos[0] == 0x0 && pos[2] == 0x0) {
		GetCursorPos(&cursor);
		if (GetAsyncKeyState((int)'P')) {
			system("cls");
			std::cout << "SEGURE A LETRA 'P' PARA SALVAR A POSIÇÃO DO PRIMEIRO POKEMON DA POKEBAR!";
			pos[0] = cursor.x;
			pos[2] = cursor.y;
		}
		count[0] = pos[2] + (SIZE_POKEBAR * count[1]);
	}

	while (pos[1] == 0x0 && pos[3] == 0x0) {
		GetCursorPos(&cursor);
		if (GetAsyncKeyState((int)'B')) {
			std::cout << "SEGURE A LETRA 'B' PARA SALVAR A POSIÇÃO DA POKEBAR!";
			system("cls");
			pos[1] = cursor.x;
			pos[3] = cursor.y;
		}
	}

	_CALLBACK_();

	return 0;
}

void _CALLBACK_(void) {
	dc = GetDC(window[0]);

	while (true) {
		__BOT__();
	}
}

void __BOT__(void) {
	window[0] = FindWindow(name, NULL);
	if (window[0]) {
		window[1] = GetForegroundWindow();
		if (window[0] == window[1]) {
			GetCursorPos(&cursor);
			if (!dc) {
				dc = GetDC(window[0]);
			}

			if (pos[2] >= count[0]) {
				pos[2] = pos[2] - (SIZE_POKEBAR * count[1]);
			}

			marcador(pos[0], pos[2]);
			marcador(pos[1], pos[3]);
			pos[4] = cursor.x;
			pos[5] = cursor.y;

			if (GetAsyncKeyState((int)'P')) {
				system("cls");
				std::cout << "SEGURE A LETRA 'P' PARA SALVAR A POSIÇÃO DO PRIMEIRO POKEMON DA POKEBAR!";
				pos[0] = cursor.x;
				pos[2] = cursor.y;
				count[0] = pos[2] + (SIZE_POKEBAR * count[1]);
			}

			if (GetAsyncKeyState((int)'B')) {
				std::cout << "SEGURE A LETRA 'B' PARA SALVAR A POSIÇÃO DA JANELA DE COMBATE!";
				system("cls");
				pos[1] = cursor.x;
				pos[3] = cursor.y;
			}

			if (GetAsyncKeyState(toupper(key[0]))) {
				ATAQUE_KEYBOARD();
				ATAQUE_TARGET();
			}
			else if (GetAsyncKeyState(toupper(key[1]))) {
				TROCA_POKEMON();
			}
			else if (GetAsyncKeyState(toupper(key[2]))) {
				D_ATAQUE_KEYBOARD();
			}
		}
	}
}

void marcador(int pox_x, int pos_y) {
	SetPixel(dc, pox_x, pos_y, RGB(0, 0, 0));
	SetPixel(dc, pox_x + 1, pos_y, RGB(0, 0, 0));
	SetPixel(dc, pox_x, pos_y + 1, RGB(0, 0, 0));
	SetPixel(dc, pox_x + 1, pos_y + 1, RGB(0, 0, 0));
	SetPixel(dc, pox_x - 1, pos_y, RGB(0, 0, 0));
	SetPixel(dc, pox_x, pos_y - 1, RGB(0, 0, 0));
	SetPixel(dc, pox_x - 1, pos_y - 1, RGB(0, 0, 0));
	SetPixel(dc, pox_x + 2, pos_y, RGB(0, 0, 0));
	SetPixel(dc, pox_x, pos_y + 2, RGB(0, 0, 0));
	SetPixel(dc, pox_x + 2, pos_y + 2, RGB(0, 0, 0));
	SetPixel(dc, pox_x - 2, pos_y, RGB(0, 0, 0));
	SetPixel(dc, pox_x, pos_y - 2, RGB(0, 0, 0));
	SetPixel(dc, pox_x - 2, pos_y - 2, RGB(0, 0, 0));
}

void ATAQUE_KEYBOARD(void) {
	for (BYTE i = VK_F1; i <= VK_F12; i++) {
		keybd_event(i, NULL, NULL, NULL);
	}
}
void D_ATAQUE_KEYBOARD(void) {
	for (BYTE i = VK_F1; i <= VK_F12; ++i) {
		keybd_event(i, NULL, KEYEVENTF_KEYUP, NULL);
	}
}

void ClickCursor(int count_click) {
	for (std::size_t i = 1; i <= count_click; i++) {
		Sleep(200);
		mouse_event(0x0002, NULL, NULL, NULL, NULL);
		mouse_event(0x0004, NULL, NULL, NULL, NULL);
		Sleep(200);
	}
}

void ATAQUE_TARGET(void) {
	GetCursorPos(&cursor);
	while ((cursor.x != pos[1]) && (cursor.y != pos[3])) {
		GetCursorPos(&cursor);
		SetPhysicalCursorPos(pos[1], pos[3]);
	}

	ClickCursor(1);
	BACKUP_CURSOR();
}

void TROCA_POKEMON(void) {
	GetCursorPos(&cursor);
	while ((cursor.x != pos[0]) && (cursor.y != pos[2])) {
		GetCursorPos(&cursor);
		SetPhysicalCursorPos(pos[0], pos[2]);
	}

	ClickCursor(1);
	pos[2] = pos[2] + SIZE_POKEBAR;
	BACKUP_CURSOR();
}

void BACKUP_CURSOR(void) {
	GetCursorPos(&cursor);
	while ((cursor.x != pos[4]) && (cursor.y != pos[5])) {
		GetCursorPos(&cursor);
		SetPhysicalCursorPos(pos[4], pos[5]);
	}
}
