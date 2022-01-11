#pragma once
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime> 
#include "Player.h"
#include "Enemy.h"
#include "Enums.h"

class tic_tac_toe_game
{
private:
	Player player;
	Enemy enemy;
	int **cage;
	
	bool checking_move(int i, int j);
	bool Is_Field_empty();
public:
	int count_free_field;
	tic_tac_toe_game();
	~tic_tac_toe_game();
	
	void start();
	void make_a_move(Players player);
	void print_playing_field();
	
	bool stoping();

	void set_player(Player player);
	void set_enemy(Enemy enemy);
	void set_cage(int **cage);

	Player get_player();
	Enemy get_enemy();
	int** get_cage();
};

