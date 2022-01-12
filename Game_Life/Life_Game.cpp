#include "Life_Game.h"
#include "enums.h"

Life_Game::Life_Game()
{
	playing_field = new int* [size_game_field];
	for (int i = 0; i < size_game_field; i++)
	{
		playing_field[i] = new int[size_game_field];
	}
	old_playing_field = new int* [size_game_field];
	for (int i = 0; i < size_game_field; i++)
	{
		old_playing_field[i] = new int[size_game_field];
	}
	for (int i = 0; i < size_game_field; i++)
	{
		for (int j = 0; j < size_game_field; j++)
		{
			playing_field[i][j] = Fields::Empty_field;
		}
	}
}

Life_Game::~Life_Game()
{
	for (int i = 0; i < size_game_field; i++)
	{
		delete(playing_field[i]);
	}
	delete(playing_field);
}

bool Life_Game::check_this_point(int point1, int point2)
{
	int count = 0;
	for (int x = { std::max(point1, 1) - 1 }; x < std::min(point1 + 2, size_game_field); ++x)
	{
		for (int y = { std::max(point2, 1) - 1 }; y < std::min(point2 + 2, size_game_field); ++y)
		{
			if (x == point1 && y == point2)
			{
				continue;
			}
			count += old_playing_field[x][y];
		}
	}
	if (count <= 1 || count >= 4)
	{
		return true;
	}
	return false;
}

void Life_Game::print_Universe()
{
	for (int i = 0; i < size_game_field; i++)
	{
		for (int j = 0; j < size_game_field; j++)
		{
			if (playing_field[i][j] == Fields::Life)
			{
				std::cout << "*";
			}
			else
			{
				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}
}

void Life_Game::init_new_generation()
{
	for (int i = 0; i < size_game_field; i++)
	{
		for (int j = 0; j < size_game_field; j++)
		{
			if (!check_this_point(i,j))
			{
				playing_field[i][j] = Fields::Life;
			}
			else
			{
				playing_field[i][j] = Fields::Empty_field;
			}
		}
	}
}

void Life_Game::generation_new_game()
{
	for (int i = 0; i < size_game_field; i++)
	{
		for (int j = 0; j < size_game_field; j++)
		{
			if ((rand() % 1000) % 10 == 0)
			{
				playing_field[i][j] = Fields::Life;
			}
		}
	}
}

void Life_Game::copy_field()
{
	for (int i = 0; i < size_game_field; i++)
	{
		for (int j = 0; j < size_game_field; j++)
		{
			old_playing_field[i][j] = playing_field[i][j];
		}
	}
}
