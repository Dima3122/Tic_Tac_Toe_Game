#pragma once
#include <iostream>
#include <fstream>
#include "Gamer.h"
#include "Enemy.h"
#include "Enums.h"
#include "Random_Player.h"

class tic_tac_toe_game
{
private:
	Gamer gamer;//всевозможные игроки
	Enemy enemy;
	Random_Player random_player;

	int **cage;//игровое поле
	int count_free_field;//количество свободных клеток

	bool enemy_is_zero;//Противник - нолик?
	bool play_random_player;//играем ли мы с рандомным человеком?
	bool Is_Field_empty();
public:
	tic_tac_toe_game();
	~tic_tac_toe_game();
	
	void start();
	void make_a_move(Players player);
	void print_playing_field();
	
	bool stoping();

	void set_player(Gamer gamer);
	void set_enemy(Enemy enemy);
	void set_cage(int **cage);
	void set_enemy_is_zero(bool enemy_is_zero);
	void set_play_random_player(bool play_random_player);
	void print_winner(Game winner);
	void print_final_score();

	Gamer get_player();
	Enemy get_enemy();
	int** get_cage();
	bool get_enemy_is_zero();
	bool get_play_random_player();
};