#include <iostream>
#include <string>
#include <fstream>
#include "gameOfLife.h"
using namespace std;

int main() {

	GameOfLife the_game;
	;
	string again;
	the_game.set_start();
	do {

		the_game.draw();
		the_game.next_generation();

		cout << "again (yes/no): ";
		cin >> again;
		system("CLS");
		} while (again=="yes");

	return 0;
}