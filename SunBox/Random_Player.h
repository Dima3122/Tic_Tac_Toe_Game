#pragma once
#include <iostream>
#include "Player.h"

class Random_Player : public Player 
{
public:
	Random_Player() = default;
	~Random_Player() = default;
	//�������������� ����� "��� ���������� ���� ��������� �����" ����� ���� � ������ ������ �������
	void get_the_coordinates_of_the_move(int& param1, int& param2, int** cage) override;
};

