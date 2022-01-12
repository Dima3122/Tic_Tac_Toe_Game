#pragma once
#include <iostream>

class Life_Game
{
private:
	int** playing_field;
	int** old_playing_field;
	int count_life = 0;
	const int size_game_field = 10;
	bool check_this_point(int i, int j);
public:
	Life_Game();
	~Life_Game();

	void print_Universe();
	void init_new_generation();
	void generation_new_game();
	void copy_field();
};

