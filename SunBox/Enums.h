#pragma once
struct Stats
{
	int wins_zero;
	int wins_cross;
	int lose_zero;
	int lose_cross;
	int draw;
};
enum Increment_Stats
{
	wins_zero = 0,
	wins_cross = 1,
	lose_zero = 2,
	lose_cross = 3,
	draw = 4
};
enum Game//упрощение для чтение кода, гораздо лучше чем "магические числа"
{
	Cross = 0,
	Zero = 1,
	Empty_cage = 2
};
enum Players
{
	player = 0,
	enemy = 1,
	random_player = 2
};