#include "player.h"

void Player::get_the_coordinates_of_the_move(int &i, int &j)
{
	do
	{
		std::cout << "������� ����������, ���� ��������� �������";
		std::cin >> i >> j;
	} while (i >= 3 || j >= 3);
}
