#include "Enemy.h"

void Enemy::get_random_coordinate(int& param1, int& param2, int **cage)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (cage[i][j] == Game::Empty_cage)
			{
				param1 = i;
				param2 = j;
				return;
			}
		}
	}
}

void Enemy::get_the_coordinates_of_the_move(int& param1, int& param2, int **cage)
{
	if (cage[1][1] == Game::Empty_cage)//—тараемс€ зан€ть центр
	{
		param1 = 1;
		param2 = 1;
		return;
	}
	int count_of_zeros[3] = { 0 };
	for (int i = 0; i < 3; i++)//Ќачинаем искать свободные позиции по столбцам и строкам
	{						   //≈сли нашли, где можно доставить крестик, то пытаемс€ его поставить
		if (cage[i][i] == Game::Zero)//“ак же стараемс€ пройти по диагонали.
		{							 //иначе, генерируем рандомную позицию и выходим.
			count_of_zeros[2]++;
		}
		for (int j = 0; j < 3; j++)
		{
			if (cage[i][j] == Game::Zero)
			{
				count_of_zeros[0]++;
			}
			if (cage[j][i] == Game::Zero)
			{
				count_of_zeros[1]++;
			}
		}
		if (count_of_zeros[2] >= 1)
		{
			for (int i = 0; i < 3; i++)
			{
				if (cage[i][i] == Game::Empty_cage)
				{
					param1 = param2 = i;
					return;
				}
			}
		}
		if (count_of_zeros[0] >= 1)
		{
			for (int j = 0; j < 3; j++)
			{
				if (cage[i][j] == Game::Empty_cage)
				{
					param1 = i;
					param2 = j;
					return;
				}
			}
			get_random_coordinate(param1, param2, cage);
			return;
		}
		if (count_of_zeros[1] >= 1)
		{
			for (int j = 0; j < 3; j++)
			{
				if (cage[j][i] == Game::Empty_cage)
				{
					param1 = i;
					param2 = j;
					return;
				}
			}
			get_random_coordinate(param1, param2, cage);
			return;
		}
		count_of_zeros[0] = 0;
		count_of_zeros[1] = 0;
	}
	return;
}
