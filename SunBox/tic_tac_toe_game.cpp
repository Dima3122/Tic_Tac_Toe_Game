#include "tic_tac_toe_game.h"

tic_tac_toe_game::tic_tac_toe_game()
{
	cage = new int* [3];
	for (int i = 0; i < 3; i++)
	{
		cage[i] = new int[3];
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cage[i][j] = Game::Empty_cage;
		}
	}
	count_free_field = 9;
}

tic_tac_toe_game::~tic_tac_toe_game()
{
	for (int i = 0; i < 3; i++)
	{
		delete(cage[i]);
	}
	delete(cage);
}

void tic_tac_toe_game::start()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cage[i][j] = Game::Empty_cage;
		}
	}
	count_free_field = 9;
}

void tic_tac_toe_game::make_a_move(Players player)
{
	if (count_free_field == 0)
	{
		return;
	}
	int i = 0, j = 0;
	if (player == Players::player)
	{
		do
		{
			tic_tac_toe_game::player.get_the_coordinates_of_the_move(i, j);
		} while (checking_move(i,j));
		cage[i][j] = Game::Cross;
	}
	else
	{
		tic_tac_toe_game::enemy.get_the_coordinates_of_the_move(i,j, cage);
		if (checking_move(i,j))
		{
			tic_tac_toe_game::enemy.get_random_coordinate(i, j, cage);
		}
		cage[i][j] = Game::Zero;
	}
	count_free_field--;
}

bool tic_tac_toe_game::checking_move(int i, int j)
{
	if (cage[i][j] == Game::Empty_cage)
	{
		return false;
	}
	return true;
}

bool tic_tac_toe_game::stoping()
{
	int count_player[2] = { 0 };
	int count_Enemy[2] = { 0 };
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (cage[i][j] == Game::Cross)
			{
				count_player[0]++;
			}
			if (cage[i][j] == Game::Zero)
			{
				count_Enemy[0]++;
			}
			if (cage[j][i] == Game::Cross)
			{
				count_player[1]++;
			}
			if (cage[j][i] == Game::Zero)
			{
				count_Enemy[1]++;
			}
		}
		if (count_Enemy[0] == 3 || count_Enemy[1] == 3)
		{
			std::fstream fout("result.csv", std::ofstream::app);
			if (!fout.is_open())
			{
				std::cout << "Ошибка открытия файла!" << std::endl;
			}
			else
			{
				fout << "Победу одержал компьютер!\n";
			}
			fout.close();
			return false;
		}
		if (count_player[0] == 3 || count_player[1] == 3)
		{
			std::fstream fout("result.csv", std::ofstream::app);
			if (!fout.is_open())
			{
				std::cout << "Ошибка открытия файла!" << std::endl;
			}
			else
			{
				fout << "Победу одержал игрок!\n";
			}
			fout.close();
			return false;
		}
		count_player[0] = 0;
		count_player[1] = 0;
		count_Enemy[0] = 0;
		count_Enemy[1] = 0;
	}
	if (cage[1][1] == Game::Cross && cage[2][0] == Game::Cross && cage[0][2] == Game::Cross)//обратная диагональ
	{
		std::fstream fout("result.csv", std::ofstream::app);
		if (!fout.is_open())
		{
			std::cout << "Ошибка открытия файла!" << std::endl;
		}
		else
		{
			fout << "Победу одержал игрок!\n";
		}
		fout.close();
		return false;
	}
	if (cage[1][1] == Game::Zero && cage[2][0] == Game::Zero && cage[0][2] == Game::Zero)//обратная диагональ
	{
		std::fstream fout("result.csv", std::ofstream::app);
		if (!fout.is_open())
		{
			std::cout << "Ошибка открытия файла!" << std::endl;
		}
		else
		{
			fout << "Победу одержал компьютер!\n";
		}
		fout.close();
		return false;
	}
	for (int i = 0; i < 3; i++)
	{
		if (cage[i][i] == Game::Cross)
		{
			count_player[1]++;
		}
		if (cage[i][i] == Game::Zero)
		{
			count_Enemy[1]++;
		}
	}
	if (count_Enemy[0] == 3 || count_Enemy[1] == 3)
	{
		std::fstream fout("result.csv", std::ofstream::app);
		if (!fout.is_open())
		{
			std::cout << "Ошибка открытия файла!" << std::endl;
		}
		else
		{
			fout << "Победу одержал компьютер!\n";
		}
		fout.close();
		return false;
	}
	if (count_player[0] == 3 || count_player[1] == 3)
	{
		std::fstream fout("result.csv", std::ofstream::app);
		if (!fout.is_open())
		{
			std::cout << "Ошибка открытия файла!" << std::endl;
		}
		else
		{
			fout << "Победу одержал игрок!\n";
		}
		fout.close();
		return false;
	}
	return Is_Field_empty();
}

void tic_tac_toe_game::set_player(Player player)
{
	this->player = player;
}

void tic_tac_toe_game::set_enemy(Enemy enemy)
{
	this->enemy = enemy;
}

void tic_tac_toe_game::set_cage(int **cage)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			this->cage[i][j] = cage[i][j];
		}
	}
}

Player tic_tac_toe_game::get_player()
{
	return player;
}

Enemy tic_tac_toe_game::get_enemy()
{
	return enemy;
}

int** tic_tac_toe_game::get_cage()
{
	return cage;
}

bool tic_tac_toe_game::Is_Field_empty()
{
	if (count_free_field == 0)
	{
		std::fstream fout("result.csv", std::ofstream::app);
		if (!fout.is_open())
		{
			std::cout << "Ошибка открытия файла!" << std::endl;
		}
		else
		{
			fout << "НИЧЬЯ!\n";
		}
		fout.close();
		return false;
	}
	return true;
}

void tic_tac_toe_game::print_playing_field()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << "|";
			if (cage[i][j] == Game::Cross)
			{
				std::cout << "X";
			}
			else if (cage[i][j] == Game::Zero)
			{
				std::cout << "0";
			}
			else
			{
				std::cout << " ";
			}
			std::cout << "|";
		}
		std::cout << std::endl;
	}
}