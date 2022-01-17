#pragma once
#pragma once
#include <iostream>
#include "Player.h"

class Gamer : public Player
{
public: 
	Gamer() = default;
	~Gamer() = default;
	//переопредел€ем метод "ƒай координаты куда поставить точку" метод есть в каждом классе потомке
	void get_the_coordinates_of_the_move(int& param1, int& param2, int** cage) override;
};																							

