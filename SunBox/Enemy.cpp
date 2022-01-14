#include "Enemy.h"

void Enemy::get_random_coordinate(int& param1, int& param2, int **cage)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (cage[i][j] == Game::Empty_cage)
			{
				param1 = i;
				param2 = j;
				if (check_coordinate(param1, param2, cage))
				{
					get_random_coordinate(param1, param2, cage);
				}
				return;
			}
		}
	}
}

void Enemy::get_the_coordinates_of_the_move(int& param1, int& param2, int **cage)
{
	Game enemy_is;
	Game player_is;
	if (enemy_is_zero == true)
	{
		enemy_is = Game::Zero;
		player_is = Game::Cross;
	}
	else
	{
		enemy_is = Game::Cross;
		player_is = Game::Zero;
	}
	if (cage[1][1] == Game::Empty_cage)//���� ���� ����� ����������� �������� �����
	{
		param1 = 1;
		param2 = 1;
		return;
	}
	bool It_free_there[2] = { true, true };
	int count_in_a_row[4] = { 0 };
	for (int i = 0; i < 3; i++)//���� ����� ����� �� ������� ��������� �� ������� ���������
	{
		if (cage[i][i] == enemy_is)//�� �������, ��� ��� ����� �� "�����"
		{
			count_in_a_row[2]++;
		}
		else if(cage[i][i] == player_is)//� ������� ����� �� �����
		{
			It_free_there[0] = false;		//���� �����, �� ���������� ���
		}
	}
	if (It_free_there[0] == true && count_in_a_row[2] >= 1)//����� �������, ���� ��� �������� � ���� 
	{													//"����" �� ���� ���� ������� ��� �����
		for (int i = 0; i < 3; i++)						//���������� �� ������� ��������� � 
		{												//���� ��������� ��������, �������, ������.
			if (!check_coordinate(i, i, cage))
			{
				param1 = i;
				param2 = i;
				return;
			}
		}
	}
	for (int i = 0; i < 3; i++)    //���� ������� ��������� �� ���������, �������� �������� �� ������� � ������
	{							  
		count_in_a_row[0] = 0; count_in_a_row[1] = 0;	   
		It_free_there[0] = true; It_free_there[1] = true;
		for (int j = 0; j < 3; j++) //���������� �� ���� � �������� �������� ���������� ������ �� ���������� �������
		{							//������ �� �������� � �������
			if (cage[i][j] == player_is)//������������ ������
			{
				It_free_there[0] = false;
			}
			if (cage[i][j] == enemy_is)
			{
				count_in_a_row[0]++;
			}
			if (cage[j][i] == player_is)//������������ �������
			{
				It_free_there[1] = false;
			}
			if (cage[j][i] == enemy_is)
			{
				count_in_a_row[1]++;
			}
			//������� ��� ����������, �������� ��������, ��� �� �����
		}
		if (It_free_there[0] == true && count_in_a_row[0] >= 1)//������� ��� ������ ������
		{
			for (int j = 0; j < 3; j++)						//���������� �� ������� ��������� � 
			{												//���� ��������� ��������, �������, ������.
				if (!check_coordinate(i, j, cage))
				{
					param1 = i;
					param2 = j;
					return;
				}
			}
		}
		if (It_free_there[1] == true && count_in_a_row[1] >= 1)//������� ��� ������ ������
		{
			for (int j = 0; j < 3; j++)						//���������� �� ������� ��������� � 
			{												//���� ��������� ��������, �������, ������.
				if (!check_coordinate(i, j, cage))
				{
					param1 = i;
					param2 = j;
					return;
				}
			}
		}
	}
	//�� � ��������� �������� ���������. ���� �� ���
	int number1 = 0, number2 = 2;
	It_free_there[0] = true;
	for (int i = 0; i < 3; i++)
	{
		if (cage[number1 + i][number2 - i] == enemy_is)
		{
			count_in_a_row[3]++;
		}
		if (cage[number1 + i][number2 - i] == player_is)
		{
			It_free_there[0] = false;
		}
	}
	if (It_free_there[1] == true && count_in_a_row[3] >= 1)
	{
		for (int j = 0; j < 3; j++)						//���������� �� ������� ��������� � 
		{												//���� ��������� ��������, �������, ������.
			int parametr1 = number1 + j;				//������� �������
			int parametr2 = number2 - j;				//��������� ������� � ���� ��� ������� �� �����������
			if (!check_coordinate(parametr1, parametr2, cage))
			{
				param1 = parametr1;
				param2 = parametr2;
				return;
			}
		}
	}
	get_random_coordinate(param1, param2, cage);//���� ��������� ���, �� ������ ��� � ������
	return;			
}