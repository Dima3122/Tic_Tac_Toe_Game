#include "tic_tac_toe_game.h"

tic_tac_toe_game::tic_tac_toe_game()//конструктор, инициализирует все поля
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

tic_tac_toe_game::~tic_tac_toe_game()//деструктор убивает все динамические поля
{
	for (int i = 0; i < 3; i++)
	{
		delete(cage[i]);
	}
	delete(cage);
}

void tic_tac_toe_game::start()//обнуление всех полей, что бы начать игру снова, а так же установление нужных
{							  //значений в классы, что бы они понимали кто они крестик или нолик
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cage[i][j] = Game::Empty_cage;
		}
	}
	enemy.set_enemy_is_zero(enemy_is_zero);
	gamer.set_enemy_is_zero(enemy_is_zero);
	count_free_field = 9;
}

void tic_tac_toe_game::make_a_move(Players player)//сделать ход. передаем того кто ходит и вызываем метод
{												  //нужного нам игрока
	if (count_free_field == 0)
	{
		return;
	}
	int i = 0, j = 0;
	if (player == Players::player)
	{
		tic_tac_toe_game::gamer.get_the_coordinates_of_the_move(i, j, cage);
		enemy_is_zero == true ? cage[i][j] = Game::Cross : cage[i][j] = Game::Zero;
	}
	else if(player == Players::enemy)
	{
		tic_tac_toe_game::enemy.get_the_coordinates_of_the_move(i,j, cage);
		enemy_is_zero == true ? cage[i][j] = Game::Zero : cage[i][j] = Game::Cross;
		
	}
	else if(player == Players::random_player)
	{
		tic_tac_toe_game::random_player.get_the_coordinates_of_the_move(i,j,cage);
		enemy_is_zero == true ? cage[i][j] = Game::Cross : cage[i][j] = Game::Zero; 
	}
	count_free_field--;
}

void tic_tac_toe_game::print_winner(Game winner)//вывести победителя!
{												//передаем какая фигура выйграла, а затем начинаем выводить
	std::fstream fout("result.csv", std::ofstream::app);//победителя зная кто за какую фигуру играл
	if (fout.is_open())
	{
		if (winner == Game::Cross)
		{
			if (enemy_is_zero == true)
			{
				if (play_random_player == true)
				{
					fout << "Победу одержал случайный игрок!;Он играл за крестики\n";
					std::cout << "Победу одержал случайный игрок! Он играл за крестики\n" << std::endl;
					random_player.increment_one_stats(Increment_Stats::wins_cross);
					enemy.increment_one_stats(Increment_Stats::lose_zero);
				}
				else
				{
					fout << "Победу одержал игрок!;Он играл за крестики\n";
					std::cout << "Победу одержал игрок! Он играл за крестики\n" << std::endl;
					gamer.increment_one_stats(Increment_Stats::wins_cross);
					enemy.increment_one_stats(Increment_Stats::lose_zero);
				}
			}
			else
			{
				fout << "Победу одержал противник!;Он играл за крестики\n";
				std::cout << "Победу одержал противник! Он играл за крестики\n" << std::endl;
				if (play_random_player == true)
				{
					enemy.increment_one_stats(Increment_Stats::wins_cross);
					random_player.increment_one_stats(Increment_Stats::lose_zero);
				}
				else
				{
					enemy.increment_one_stats(Increment_Stats::wins_cross);
					gamer.increment_one_stats(Increment_Stats::lose_zero);
				}
			}			 
		}
		else
		{
			if (enemy_is_zero == true)
			{
				fout << "Победу одержал противник!;Он играл за нолики\n";
				std::cout << "Победу одержал противник! Он играл за нолики\n" << std::endl;
				if (play_random_player == true)
				{
					enemy.increment_one_stats(Increment_Stats::wins_zero);
					random_player.increment_one_stats(Increment_Stats::lose_cross);
				}
				else
				{
					gamer.increment_one_stats(Increment_Stats::lose_cross);
					enemy.increment_one_stats(Increment_Stats::wins_zero);
				}
			}
			else
			{
				if (play_random_player == true)
				{
					fout << "Победу одержал случайный игрок!;Он играл за нолики\n";
					std::cout << "Победу одержал случайный игрок! Он играл за нолики\n" << std::endl;
					random_player.increment_one_stats(Increment_Stats::wins_zero);
					enemy.increment_one_stats(Increment_Stats::lose_cross);
				}
				else
				{
					fout << "Победу одержал  игрок!;Он играл за нолики\n";
					std::cout << "Победу одержал  игрок! Он играл за нолики\n" << std::endl;
					gamer.increment_one_stats(Increment_Stats::wins_zero);
					enemy.increment_one_stats(Increment_Stats::lose_cross);
				}
			}
		}
	}
	else
	{
		std::cout << "Ошибка открытия файла!" << std::endl;
	}
	fout.close();
}

bool tic_tac_toe_game::stoping()//метод, которая каждый раз сканирует поле и определяет, победил ли кто-нибудь
{								//рассматривает все случаи, если не находит, вызывает метод проверки,
	int count_zero[2] = { 0 };	//который проверяет есть ли еще оставшиеся поля
	int count_cross[2] = { 0 };
	for (int i = 0; i < 3; i++)//проверка по строкам и столбцам
	{
		for (int j = 0; j < 3; j++)
		{
			if (cage[i][j] == Game::Cross)
			{
				count_cross[0]++;
			}
			if (cage[i][j] == Game::Zero)
			{
				count_zero[0]++;
			}
			if (cage[j][i] == Game::Cross)
			{
				count_cross[1]++;
			}
			if (cage[j][i] == Game::Zero)
			{
				count_zero[1]++;
			}
		}
		if (count_cross[0] == 3 || count_cross[1] == 3)
		{
			print_winner(Game::Cross);
			return false;
		}
		if (count_zero[0] == 3 || count_zero[1] == 3)
		{
			print_winner(Game::Zero);
			return false;
		}
		count_zero[0] = 0;
		count_zero[1] = 0;
		count_cross[0] = 0;
		count_cross[1] = 0;
	}
	if (cage[1][1] == Game::Cross && cage[2][0] == Game::Cross && cage[0][2] == Game::Cross)//обратная диагональ
	{
		print_winner(Game::Cross);
		return false;
	}
	if (cage[1][1] == Game::Zero && cage[2][0] == Game::Zero && cage[0][2] == Game::Zero)//обратная диагональ
	{
		print_winner(Game::Zero);
		return false;
	}
	if (cage[0][0] == Game::Zero && cage[1][1] == Game::Zero && cage[2][2] == Game::Zero)//прямая диагональ
	{
		print_winner(Game::Zero);
		return false;
	}
	if (cage[0][0] == Game::Cross && cage[1][1] == Game::Cross && cage[2][2] == Game::Cross)//прямая диагональ
	{
		print_winner(Game::Cross);
		return false;
	}
	return Is_Field_empty();
}

void tic_tac_toe_game::set_player(Gamer gamer)//геттеры и сеттеры можно пропустить
{
	this->gamer = gamer;
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

Gamer tic_tac_toe_game::get_player()
{
	return gamer;
}

Enemy tic_tac_toe_game::get_enemy()
{
	return enemy;
}

int** tic_tac_toe_game::get_cage()
{
	return cage;
}

bool tic_tac_toe_game::get_enemy_is_zero()
{
	return enemy_is_zero;
}
bool tic_tac_toe_game::get_play_random_player()
{
	return play_random_player;
}
void tic_tac_toe_game::set_enemy_is_zero(bool enemy_is_zero)
{
	this->enemy_is_zero = enemy_is_zero;
}

void tic_tac_toe_game::set_play_random_player(bool play_random_player)
{
	this->play_random_player = play_random_player;
}

void tic_tac_toe_game::print_final_score()
{
	std::fstream fout("result.csv", std::ofstream::app);
	if (fout.is_open())
	{
		Stats stats = tic_tac_toe_game::enemy.get_stats();
		if (play_random_player == true)
		{
			fout << "Количество побед у умного соперника крестиками: " << stats.wins_cross << "Ноликами " 
				 << stats.wins_zero << " Проигрышей крестиками: " << stats.lose_cross << " Ноликами "
				 << stats.lose_zero << " Ничьих: " << stats.draw << "\n";
			std::cout << "Количество побед у умного соперника крестиками: " << stats.wins_cross << "Ноликами "
					  << stats.wins_zero << "Проигрышей крестиками: " << stats.lose_cross << "Ноликами "
					  << stats.lose_zero << "Ничьих: " << stats.draw << std::endl;
			stats = tic_tac_toe_game::random_player.get_stats();
			fout << "Количество побед у случайного игрока крестиками: " << stats.wins_cross << "Ноликами "
				 << stats.wins_zero << "Проигрышей крестиками: " << stats.lose_cross << "Ноликами "
				 << stats.lose_zero << "Ничьих: " << stats.draw << "\n";
			std::cout << "Количество побед у случайного игрока крестиками: " << stats.wins_cross << "Ноликами "
				<< stats.wins_zero << "Проигрышей крестиками: " << stats.lose_cross << "Ноликами "
				<< stats.lose_zero << "Ничьих: " << stats.draw << std::endl;
		}
		else
		{
			fout << "Количество побед у умного соперника крестиками: " << stats.wins_cross << "Ноликами "
				<< stats.wins_zero << "Проигрышей крестиками: " << stats.lose_cross << "Ноликами "
				<< stats.lose_zero << "Ничьих: " << stats.draw << "\n";
			std::cout << "Количество побед у умного соперника крестиками: " << stats.wins_cross << "Ноликами "
				<< stats.wins_zero << "Проигрышей крестиками: " << stats.lose_cross << "Ноликами "
				<< stats.lose_zero << "Ничьих: " << stats.draw << std::endl;
			stats = tic_tac_toe_game::gamer.get_stats();
			fout << "Количество побед у игрока крестиками: " << stats.wins_cross << "Ноликами "
				<< stats.wins_zero << "Проигрышей крестиками: " << stats.lose_cross << "Ноликами "
				<< stats.lose_zero << "Ничьих: " << stats.draw << "\n";
			std::cout << "Количество побед у игрока крестиками: " << stats.wins_cross << "Ноликами "
				<< stats.wins_zero << "Проигрышей крестиками: " << stats.lose_cross << "Ноликами "
				<< stats.lose_zero << "Ничьих: " << stats.draw << std::endl;
		}
	}
}

bool tic_tac_toe_game::Is_Field_empty()//проверка на заполненность поля. смотрит на поле класса и если оно 
{									   //равно 0, то выводит в файлик, что это ничья!
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
			std::cout << "Ничья" << std::endl;
			gamer.increment_one_stats(Increment_Stats::draw);
			random_player.increment_one_stats(Increment_Stats::draw);
			enemy.increment_one_stats(Increment_Stats::draw);
		}
		fout.close();
		return false;
	}
	return true;
}

void tic_tac_toe_game::print_playing_field()//метод вывода поля. Проходится по внутреннему двумерному массиву
{											//и выводит его в более презентабельном виде
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