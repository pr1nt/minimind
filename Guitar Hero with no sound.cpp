﻿// Guitar Hero with no sound.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>
#include <fstream>

using namespace std;

void Game();
void Nickname();
void SeqGenerate();
void DecodedOutput(int inCode);
int scoreToWrite;
int row[100];

int main()
{
	SetConsoleCP(437);
	SetConsoleOutputCP(437);
	Game();
	system("pause");
	return 0;
}

void Nickname() {
	ofstream gamersBase;
	gamersBase.open("scores.txt", ios_base::app);
	string name;
	cout << "Input player name: ";
	cin >> name;
	gamersBase << name << "  " << scoreToWrite << "\n";
	gamersBase.close();
	cout << "Done, restarting...";
}

void Game() {
	int inRow[100];
	SeqGenerate();
	int score = 1;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < score; j++) {
			DecodedOutput(row[j]);
			Sleep(700);
		}
		Sleep(1500);
		system("cls");
		cout << "Go!\n";
		for (int j = 0; j < score; j++) {
			inRow[j] = _getch();
			inRow[j] = _getch();
			DecodedOutput(inRow[j]);
		}
		cout << "\n";
		for (int j = 0; j < score; j++) {
			if (row[j] == inRow[j]) {
				continue;
			}
			else{
				cout << "Opps! Try again\n";
				cout << "You ended with " << score << " points\n";
				scoreToWrite = score;
				Nickname();
				Sleep(3000);
				system("cls");
				int row[100];
				Game();
			}
		}
		cout << "Your current score: " << score << "\n";
		score++;
	}
}

void SeqGenerate() {
	int randSeedArr[100];
	for (int i = 0; i < 100; i++) {
		randSeedArr[i] = rand() % 4 + 1;
	}
	for (int i = 0; i < 100; i++) {
		if (randSeedArr[i] == 1) {
			row[i] = 75;
		}
		if (randSeedArr[i] == 2) {
			row[i] = 72;
		}
		if (randSeedArr[i] == 3) {
			row[i] = 80;
		}
		if (randSeedArr[i] == 4) {
			row[i] = 77;
		}
	}
}

void DecodedOutput(int inCode) {
	switch (inCode) {
	case 75: cout << (char)0x1B;
		break;
	case 72: cout << (char)0x18;
		break;
	case 80: cout << (char)0x19;
		break;
	case 77: cout << (char)0x1A;
		break;
	}
}