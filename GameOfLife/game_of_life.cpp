#include "game_of_life.h"
#include <ctime>
#include <iostream>

bool game_of_life::slucajna_vrijednost()
{
	return (rand() % 100) < 25;
}

bool game_of_life::celija_zauzeta(int i, int j)
{
	int  br_susjednih_celija=0;
	for (int k = 0; k < 3; k++)
	{
		for (int l = 0; l < 3; l++)
		{
			bool out_of_bounds_k = ((i - 1 + k)<0 || (i - 1 + k)>=this->REDAKA);
			bool out_of_bounds_l = ((j - 1 + l)<0 || (j - 1 + l) >=this->STUPACA);
			bool out_of_bounds = (out_of_bounds_k || out_of_bounds_l);
			if (!out_of_bounds)
			{
				if (this->_generacija[i - 1 + k][j - 1 + l] && !(k==1 && l==1))
				{
					br_susjednih_celija++; 
				}
			}
		}
	}
	if (this->_generacija[i][j] && (br_susjednih_celija==2||br_susjednih_celija==3))
	{
		return true;
	}
	else if (!this->_generacija[i][j] && br_susjednih_celija == 3)
	{
		return true;
	}
	else
	{
		return false;
	}
}

game_of_life::game_of_life()
{
	srand(time(nullptr));
	for (int i = 0; i < this->REDAKA; i++)
	{
		for (int j = 0; j < this->STUPACA; j++)
		{
			this->_generacija[i][j] = slucajna_vrijednost();
		}
	}
}

void game_of_life::sljedeca_generacija()
{
	for (int i = 0; i < this->REDAKA; i++)
	{
		for (int j = 0; j < this->STUPACA; j++)
		{
			_sljedeca_generacija[i][j] = celija_zauzeta(i, j);
		}
	}
	for (int i = 0; i < this->REDAKA; i++)
	{
		for (int j = 0; j < this->STUPACA; j++)
		{
			this->_generacija[i][j] = this->_sljedeca_generacija[i][j];
		}
	}
}

void game_of_life::iscrtaj()
{
	system("CLS");
	for (int i = 0; i < this->REDAKA; i++)
	{
		for (int j = 0; j < this->STUPACA; j++)
		{
			if (this->_generacija[i][j])
			{
				cout << "*";
			}
			else
			{
				cout << "-";
			}
		}
		cout << endl;
	}
	
}
