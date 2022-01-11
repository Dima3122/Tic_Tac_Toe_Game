#include <iostream>
#include "tic_tac_toe_game.h"

int main()
{
	setlocale(LC_ALL, "ru");
	tic_tac_toe_game game;
	int count_game = 0;
	bool change_player = true;
	std::cout << "Сколько раз хотите сыграть?: ";
	std::cin >> count_game;
	for (int i = 0; i < count_game; i++)
	{
		game.start();
		change_player = true;
		while (game.stoping())
		{
			if (change_player == true)
			{
				change_player = false;
				game.make_a_move(Players::player);
			}
			else
			{
				game.make_a_move(Players::enemy);
				change_player = true;
			}
			game.print_playing_field();
			std::cout << std::endl;
		}
	}
	return 0;
}