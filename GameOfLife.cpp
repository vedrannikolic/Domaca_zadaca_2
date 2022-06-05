#include "gameOfLife.h"

int GameOfLife::cell_occupied(int i, int j)
{
	

	int n = 0;

	if (this->_generation[i - 1][j - 1] == '*')
		n++;
	if (this->_generation[i][j - 1] == '*')
		n++;
	if (this->_generation[i - 1][j] == '*')
		n++;
	if (this->_generation[i - 1][j + 1] == '*')
		n++;
	if (this->_generation[i + 1][j - 1] == '*')
		n++;
	if (this->_generation[i + 1][j] == '*')
		n++;
	if (this->_generation[i][j + 1] == '*')
		n++;
	if (this->_generation[i + 1][j + 1] == '*')
		n++;

	return n;
}

int GameOfLife::gen_rnd(int min, int max)
{

	return rand() % (max - min + 1) + min;
}

GameOfLife::GameOfLife()
{

	this->_generation[0][0] = '-';
	this->_next_generation[0][0] = '-';

}

void GameOfLife::set_start()
{
	srand(time(nullptr)); 



	for (int i = 0; i < this->ROW; i++)
	{
		for (int j = 0; j < this->COLUMN; j++)
		{
			this->_generation[i][j] = '-';
		}
	}

	for (int i = 0; i < this->ROW; i++)
	{
		for (int j = 0; j < this->COLUMN; j++)
		{
			
			if (this->gen_rnd(1, 4) == 4) {
				this->_generation[i][j] = '*';
			}
		}
	}
}

void GameOfLife::next_generation()
{
	int n;

	for (int i = 0; i < this->ROW; i++)
	{
		for (int j = 0; j < this->COLUMN; j++)
		{
			
			n = this->cell_occupied(i, j);
			if (n < 2)
				this->_next_generation[i][j] = '-';
			else if (n > 3)
				this->_next_generation[i][j] = '-';
			else if (n == 3)
				this->_next_generation[i][j] = '*';
			else if (this->_generation[i][j] == '*' && n == 2)
				this->_next_generation[i][j] = '*';
			else
				_next_generation[i][j] = '-';
		}

	}
	
	for (int i = 0; i < this->ROW; i++)
	{
		for (int j = 0; j < this->COLUMN; j++)
		{
			this->_generation[i][j] = this->_next_generation[i][j];
		}
	}
}

void GameOfLife::draw()
{
	for (int i = 0; i < this->ROW; i++)
	{
		for (int j = 0; j < this->COLUMN; j++)
		{
			if (this->_generation[i][j] != '*')
				this->_generation[i][j] = '-';

			cout << this->_generation[i][j];

		}
		cout << endl;
	}
}
