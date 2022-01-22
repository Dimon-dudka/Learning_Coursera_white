#include<iostream>
#include<conio.h>

#pragma warning(disable:4996)

using namespace std;

void loading();
int menu();
void Game();
void Print_Pole();
void User_Enter_X();
void User_Enter_0();
void Win(char letter);
void Proverka();
void Nichja();

const int SIZE = 9;
bool end_bool;
char PoleArrey[SIZE];

int main() {

	loading();
	menu();

	return 0;
}

void loading() {
	int score_prozent = 0;
	while (score_prozent != 100) {
		cout << "\t\t\t\t\t\tLoading " << score_prozent << "%\n";
		_sleep(50);
		system("cls");
		score_prozent++;
	}
}

int menu() {
	int wahl;

	for (int i = 0; i < SIZE; i++) {
		PoleArrey[i] = '-';
	}

	do {
		cout << "\n\t\t\t\t\t\t'KRESTIKI NOLIKI'\n\t\t\t\t\t\t\t\t\t\t\t\tv 0.1 by Dimas_Dudka\n\n\n";
		cout << "1)\tNew Game\n";
		cout << "2)\tExit\n";
		cout << "\n\n\n\n";

		cout << "Enter the number of yor wahl: ";
		cin >> wahl;
		system("cls");
	} while (wahl != 1 && wahl != 2);
	switch (wahl)
	{
	case 1:
		system("cls");
		Game();
		break;
	case 2:
		system("cls");
		return 0;
		break;
	}
}

void Game() {
	end_bool = true;
	while (end_bool) {
		Print_Pole();
		User_Enter_X();
		system("cls");
		Proverka();
		Print_Pole();
		User_Enter_0();
		system("cls");
		Print_Pole();
		Proverka();
		system("cls");
	}
	menu();
}

void Print_Pole() {

	for (int i = 0; i < SIZE; i++) {
		if (i % 3 == 0) {
			cout << endl << endl << endl << endl;
		}
		cout << "\t" << PoleArrey[i] << "\t";
	}
	cout << endl << endl;
}

void User_Enter_X() {
	int user_Wwod;
popitka:
	do {
		cout << "Enter the num of gex: ";
		cin >> user_Wwod;
	} while (user_Wwod != 1 && user_Wwod != 2 && user_Wwod != 3 && user_Wwod != 4
		&& user_Wwod != 5 && user_Wwod != 6 && user_Wwod != 7 && user_Wwod != 8 && user_Wwod != 9);
	if (PoleArrey[user_Wwod - 1] == 'X' || PoleArrey[user_Wwod - 1] == '0') {
		cout << "\t\tError, this gex is full. Enter please another gex\n";
		_sleep(2000);
		goto popitka;
	}
	else {
		PoleArrey[user_Wwod - 1] = 'X';
	}
}

void User_Enter_0() {
	int user_Wwod;
popitkatwo:
	do {
		cout << "Enter the num of gex: ";
		cin >> user_Wwod;
	} while (user_Wwod != 1 && user_Wwod != 2 && user_Wwod != 3 && user_Wwod != 4
		&& user_Wwod != 5 && user_Wwod != 6 && user_Wwod != 7 && user_Wwod != 8 && user_Wwod != 9);
	if (PoleArrey[user_Wwod - 1] == 'X' || PoleArrey[user_Wwod - 1] == '0') {
		cout << "\t\tError, this gex is full. Enter please another gex\n";
		_sleep(2000);
		goto popitkatwo;
	}
	else {
		PoleArrey[user_Wwod - 1] = '0';
	}
}

void Proverka() {
	char rezult;

	if ((PoleArrey[0] == 'X') && (PoleArrey[1] == 'X') && (PoleArrey[2] == 'X')){
		rezult = 'X';
		Win(rezult);
}
	else if ((PoleArrey[3] == 'X') && (PoleArrey[4] == 'X') && (PoleArrey[5] == 'X')) {
		rezult = 'X';
		Win(rezult);
	}
	else if ((PoleArrey[6] == 'X') && (PoleArrey[7] == 'X') && (PoleArrey[8] == 'X')) {
		rezult = 'X';
		Win(rezult);
	}
	else if ((PoleArrey[0] == 'X') && (PoleArrey[3] == 'X') && (PoleArrey[6] == 'X')) {
		rezult = 'X';
		Win(rezult);
	}
	else if ((PoleArrey[1] == 'X') && (PoleArrey[4] == 'X') && (PoleArrey[7] == 'X')) {
		rezult = 'X';
		Win(rezult);
	}
	else if ((PoleArrey[2] == 'X') && (PoleArrey[5] == 'X') && (PoleArrey[8] == 'X')) {
		rezult = 'X';
		Win(rezult);
	}
	else if ((PoleArrey[0] == 'X') && (PoleArrey[4] == 'X') && (PoleArrey[8] == 'X')) {
		rezult = 'X';
		Win(rezult);
	}
	else if ((PoleArrey[2] == 'X') && (PoleArrey[4] == 'X') && (PoleArrey[6] == 'X')) {
		rezult = 'X';
		Win(rezult);
	}
	

	if ((PoleArrey[0] == '0') && (PoleArrey[1] == '0') && (PoleArrey[2] == '0')) {
		rezult = '0';
		Win(rezult);
	}
	else if ((PoleArrey[3] == '0') && (PoleArrey[4] == '0') && (PoleArrey[5] == '0')) {
		rezult = '0';
		Win(rezult);
	}
	else if ((PoleArrey[6] == '0') && (PoleArrey[7] == '0') && (PoleArrey[8] == '0')) {
		rezult = '0';
		Win(rezult);
	}
	else if ((PoleArrey[0] == '0') && (PoleArrey[3] == '0') && (PoleArrey[6] == '0')) {
		rezult = '0';
		Win(rezult);
	}
	else if ((PoleArrey[1] == '0') && (PoleArrey[4] == '0') && (PoleArrey[7] == '0')) {
		rezult = '0';
		Win(rezult);
	}
	else if ((PoleArrey[2] == '0') && (PoleArrey[5] == '0') && (PoleArrey[8] == '0')) {
		rezult = '0';
		Win(rezult);
	}
	else if ((PoleArrey[0] == '0') && (PoleArrey[4] == '0') && (PoleArrey[8] == '0')) {
		rezult = '0';
		Win(rezult);
	}
	else if ((PoleArrey[2] == '0') && (PoleArrey[4] == '0') && (PoleArrey[6] == '0')) {
		rezult = '0';
		Win(rezult);
	}
	int count = 0;
	for (int i = 0; i < SIZE; i++) {
		if (PoleArrey[i] != '-') {
			count++;
		}
	}
	if (count == SIZE) {
		Nichja();
	}
}

void Win(char letter) {


	if (letter == 'X') {
		cout << "\n\n\n\t\t\t\t\tPlayer with 'X' win!!!\n";
		_sleep(2000);
		system("cls");
		cout << "\n\t\t\t\t\tPlayer with 'X' win!!!\n";
		_sleep(2000);
		system("cls");
		end_bool = false;
		menu();
	}
	else if (letter == '0') {
		cout << "\n\n\n\t\t\t\t\tPlayer with '0' win!!!\n";
		_sleep(2000);
		system("cls");
		cout << "\n\t\t\t\t\tPlayer with '0' win!!!\n";
		_sleep(2000);
		system("cls");
		end_bool = false;
		menu();
	}

}

void Nichja() {
	cout << "\t\t\t\tThe game ended in a draw\n";
	_sleep(3000);
	system("cls");
	menu();
}