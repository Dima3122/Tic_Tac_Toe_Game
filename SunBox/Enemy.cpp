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
				if (check_coordinate(param1, param2, cage))
				{
					get_random_coordinate(param1, param2, cage);
				}
				return;
			}
		}
	}
}

void Enemy::get_the_coordinates_of_the_move(int& param1, int& param2, int **cage)
{
	Game enemy_is;
	Game player_is;
	if (enemy_is_zero == true)
	{
		enemy_is = Game::Zero;
		player_is = Game::Cross;
	}
	else
	{
		enemy_is = Game::Cross;
		player_is = Game::Zero;
	}
	if (cage[1][1] == Game::Empty_cage)//если есть такая возможность занимаем центр
	{
		param1 = 1;
		param2 = 1;
		return;
	}
	bool It_free_there[2] = { true, true };
	int count_in_a_row[4] = { 0 };
	for (int i = 0; i < 3; i++)//Если центр занят то пробуем пробиться на главную диагональ
	{
		if (cage[i][i] == enemy_is)//Мы смотрим, что там стоит из "наших"
		{
			count_in_a_row[2]++;
		}
		else if(cage[i][i] == player_is)//И смотрим стоят ли чужие
		{
			It_free_there[0] = false;		//если стоят, то запоминаем это
		}
	}
	if (It_free_there[0] == true && count_in_a_row[2] >= 1)//Далее смотрим, если там свободно и есть 
	{													//"наши" то идем туда ставить еще наших
		for (int i = 0; i < 3; i++)						//проходимся по главной диагонали и 
		{												//ищем свободную клеточку, находим, ставим.
			if (!check_coordinate(i, i, cage))
			{
				param1 = i;
				param2 = i;
				return;
			}
		}
	}
	for (int i = 0; i < 3; i++)    //если главная диагональ не сработала, начинаем смотреть на столбцы и строки
	{							  
		count_in_a_row[0] = 0; count_in_a_row[1] = 0;	   
		It_free_there[0] = true; It_free_there[1] = true;
		for (int j = 0; j < 3; j++) //проходимся по полю и начинаем собирать информацию смотря на количество занятых
		{							//клеток по столбцам и строкам
			if (cage[i][j] == player_is)//Разглядываем строки
			{
				It_free_there[0] = false;
			}
			if (cage[i][j] == enemy_is)
			{
				count_in_a_row[0]++;
			}
			if (cage[j][i] == player_is)//разглядываем столбцы
			{
				It_free_there[1] = false;
			}
			if (cage[j][i] == enemy_is)
			{
				count_in_a_row[1]++;
			}
			//собрали всю информацию, начинаем смотреть, что мы имеем
		}
		if (It_free_there[0] == true && count_in_a_row[0] >= 1)//условие для нужной строки
		{
			for (int j = 0; j < 3; j++)						//проходимся по главной диагонали и 
			{												//ищем свободную клеточку, находим, ставим.
				if (!check_coordinate(i, j, cage))
				{
					param1 = i;
					param2 = j;
					return;
				}
			}
		}
		if (It_free_there[1] == true && count_in_a_row[1] >= 1)//условие для нужной строки
		{
			for (int j = 0; j < 3; j++)						//проходимся по главной диагонали и 
			{												//ищем свободную клеточку, находим, ставим.
				if (!check_coordinate(i, j, cage))
				{
					param1 = i;
					param2 = j;
					return;
				}
			}
		}
	}
	//ну и посмотрим обратную диагональ. мало ли что
	int number1 = 0, number2 = 2;
	It_free_there[0] = true;
	for (int i = 0; i < 3; i++)
	{
		if (cage[number1 + i][number2 - i] == enemy_is)
		{
			count_in_a_row[3]++;
		}
		if (cage[number1 + i][number2 - i] == player_is)
		{
			It_free_there[0] = false;
		}
	}
	if (It_free_there[1] == true && count_in_a_row[3] >= 1)
	{
		for (int j = 0; j < 3; j++)						//проходимся по главной диагонали и 
		{												//ищем свободную клеточку, находим, ставим.
			int parametr1 = number1 + j;				//считаем индексы
			int parametr2 = number2 - j;				//проверяем индексы и если все здорово то подставляем
			if (!check_coordinate(parametr1, parametr2, cage))
			{
				param1 = parametr1;
				param2 = parametr2;
				return;
			}
		}
	}
	get_random_coordinate(param1, param2, cage);//если вариантов нет, то рандом нам в помощь
	return;			
}