#include "Random_Player.h"

void Random_Player::get_the_coordinates_of_the_move(int& param1, int& param2, int** cage)
{
	bool is_so_good = false;
	do
	{
		param1 = rand() % 3;
		param2 = rand() % 3;
	} while (check_coordinate(param1, param2, cage));
}
