#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
class GameOfLife
{
private:
	static const unsigned int COLUMN = 40;
	static const unsigned int ROW = 20;

	char _generation[ROW][COLUMN];
	char _next_generation[ROW][COLUMN];

	int gen_rnd(int min, int max);
	int cell_occupied(int i, int j);



public:


	GameOfLife();
	void set_start();
	void next_generation();
	void draw();


};
