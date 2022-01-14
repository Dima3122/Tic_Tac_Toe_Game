#include <iostream>
#include "tic_tac_toe_game.h"

int main()
{
	setlocale(LC_ALL, "ru");//ставим русский язык в консольку
	tic_tac_toe_game game;//создаем обьект класса
	int count_game = 0, change = 0;//вспомогательные переменные, что бы направлять код куда нужно
	bool change_player = true, first_move_enemy = true;
	do
	{
		std::cout << "Выберете кто будет играть, вы или случайный игрок? \n1)Буду играть сам!\n2)Случайный игрок" << std::endl;
		std::cin >> change;
	} while ((change != 1) && (change != 2));//запрашиваем и проверяем данные, пока не введут правильные
	do
	{
		std::cout << "Сколько раз хотите сыграть?: ";
		std::cin >> count_game;
	} while (count_game < 0);//тоже ждем правильный ввод, а не -1
	if (change == 1)//смотрим, что же выбрал человек
	{
		game.set_play_random_player(false);//ставим, что играем с человеком
		for (int i = 0; i < count_game; i++)//основной цикл игры
		{
			std::cout << "Новая игра" << std::endl;
			first_move_enemy == true ? first_move_enemy = false : first_move_enemy = true;
			change_player = first_move_enemy;
			game.set_enemy_is_zero(first_move_enemy);
			game.start();//происходит предварительная подготовка, что бы постоянно менялись стороны
			while (game.stoping())//пока игра не остановлена, то играем
			{
				if (change_player == true)//смена игроков с помощью булевой переменной
				{
					std::cout << "Ходит игрок" << std::endl;
					game.make_a_move(Players::player);
					change_player = false;
				}
				else
				{
					std::cout << "Ходит противник" << std::endl; 
					game.make_a_move(Players::enemy);
					change_player = true;
				}
				game.print_playing_field();//печатаем на экран новый ход
				std::cout << std::endl;
			}
		}
	}
	else
	{
		game.set_play_random_player(true);//тоже самое только рандом играет с компьютером
		for (int i = 0; i < count_game; i++)
		{
			std::cout << "Новая игра" << std::endl;
			first_move_enemy == true ? first_move_enemy = false : first_move_enemy = true;
			change_player = first_move_enemy;
			game.set_enemy_is_zero(first_move_enemy);
			game.start();
			while (game.stoping())
			{
				if (change_player == true)
				{
					std::cout << "Ходит случайный игрок" << std::endl;
					change_player = false;
					game.make_a_move(Players::random_player);
				}
				else
				{
					std::cout << "Ходит противник" << std::endl;
					game.make_a_move(Players::enemy);
					change_player = true;
				}
				game.print_playing_field();
				std::cout << std::endl;
			}
		}
	}
	return 0;
}