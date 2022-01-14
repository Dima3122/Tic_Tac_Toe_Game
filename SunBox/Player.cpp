#include "Player.h"
#include "Enums.h"

bool Player::check_coordinate(int& param1, int& param2, int** cage)
{
	if (param1 <= 3 && param2 <= 3 && param1 >= 0 && param2 >= 0)
	{
		if (cage[param1][param2] == Game::Empty_cage)
		{
			return false;
		}
	}
	return true;
}

void Player::set_enemy_is_zero(bool enemy_is_zero)
{
	this->enemy_is_zero = enemy_is_zero;
}

bool Player::get_enemy_is_zero()
{
	return enemy_is_zero;
}