#pragma once
#include <iostream>
#include "Player.h"

class Random_Player : public Player 
{
public:
	Random_Player() = default;
	~Random_Player() = default;
	//переопредел€ем метод "ƒай координаты куда поставить точку" метод есть в каждом классе потомке
	void get_the_coordinates_of_the_move(int& param1, int& param2, int** cage) override;
};

