#pragma once
class Player //абстрактный класс... содержит общие методы и переменные у всех классов типа игрок
{
protected:
	bool enemy_is_zero;
public:
	~Player() = default;
	virtual bool check_coordinate(int &param1, int &param2, int **cage);
	virtual void set_enemy_is_zero(bool enemy_is_zero);
	virtual bool get_enemy_is_zero();
	virtual void get_the_coordinates_of_the_move(int& param1, int& param2, int** cage) = 0;

};