#include "Player.h"

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

void Player::increment_one_stats(Increment_Stats stats)
{
	if (stats == Increment_Stats::wins_zero)
	{
		this->stats.wins_zero++;
	}
	else if(stats == Increment_Stats::wins_cross)
	{
		this->stats.wins_cross++;
	}
	else if(stats == Increment_Stats::lose_zero)
	{
		this->stats.lose_zero++;
	}
	else if (stats == Increment_Stats::lose_cross)
	{
		this->stats.lose_cross++;
	}
	else
	{
		this->stats.draw++;
	}
}

Stats Player::get_stats()
{
	return stats;
}

void Player::set_stats(Stats stats)
{
	this->stats = stats;
}
