#pragma once
#include "Enums.h"

class Player //абстрактный класс... содержит общие методы и переменные у всех классов типа игрок
{
protected:
	bool enemy_is_zero;
	Stats stats = { 0 };
public:
	~Player() = default;

	virtual void set_enemy_is_zero(bool enemy_is_zero);
	virtual bool get_enemy_is_zero();
	virtual void set_stats(Stats stats);
	virtual Stats get_stats();

	virtual void get_the_coordinates_of_the_move(int& param1, int& param2, int** cage) = 0;
	virtual bool check_coordinate(int &param1, int &param2, int **cage);
	virtual void increment_one_stats(Increment_Stats stats);
};