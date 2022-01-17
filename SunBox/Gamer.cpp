#include "Gamer.h"

void Gamer::get_the_coordinates_of_the_move(int& param1, int& param2, int** cage)
{
	if (enemy_is_zero == true)
	{
		do
		{
			std::cout << "¬ведите координаты, куда поставить крестик";
			std::cin >> param1 >> param2;
		} while (check_coordinate(param1, param2, cage));
	}
	else
	{
		do
		{
			std::cout << "¬ведите координаты, куда поставить нолик";
			std::cin >> param1 >> param2;
		} while (check_coordinate(param1, param2, cage));
	}
}