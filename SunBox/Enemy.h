#pragma once
#include "Enums.h"
#include "Player.h"
#include <iostream>
class Enemy : public Player 
{
private:
	void get_random_coordinate(int& param1, int& param2, int **cage);
public:
	Enemy() = default;
	~Enemy() = default;
	//переопредел€ем метод "ƒай координаты куда поставить точку" метод есть в каждом классе потомке
	void get_the_coordinates_of_the_move(int& param1, int& param2, int **cage) override;
};