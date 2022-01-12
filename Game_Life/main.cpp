#include <iostream>
#include "Life_Game.h"
#include <Windows.h>

int main()
{
    Life_Game life;
    life.generation_new_game();
    life.print_Universe();
    for (int i = 0; i < 10; i++)
    {
        life.copy_field();
        life.init_new_generation();
        life.print_Universe();
        Sleep(2000);
        system("CLS");
    }
    return 0;
}