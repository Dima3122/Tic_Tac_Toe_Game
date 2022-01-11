#pragma once
#include "Enums.h"
class Enemy
{
public:
	Enemy() = default;
	~Enemy() = default;

	void get_random_coordinate(int& param1, int& param2, int **cage);
	void get_the_coordinates_of_the_move(int& param1, int& param2, int **cage);
};

