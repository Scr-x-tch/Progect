#include <iostream>
#include "main.hpp"
using namespace std;

int main ()
{
    do
    {
        char *map = new char[225];
        bool human = Mode(), first = true;

        StartBoard(map); // Заполнение диномической памяти символами "+"

        if (human) //   ---------------------   Режим игры с человеком
        {
            Board(map); // Вывод поля в консоль
            while(!Draw(map))
            {
                Move(map, 'X', first); // Ход игрока Х
                first = false; 
                Board(map); // Вывод поля в консоль 
                if (IsWin(map, 'X')) // Проверка на победу одного из игроков 
                {
                    cout << "\n\nPLAYER 'X' WIN\n\n";
                    break;
                }
                Move(map, 'O', first); // Ход игрока О
                Board(map);
                if (IsWin(map, 'O')) // Проверка на победу одного из игроков
                {
                    cout << "\n\nPLAYER 'O' WIN\n\n";
                    break;
                }
            }
        }
        else // -----------------------------   Режим игры с ботом 
        {
            bool side = Side();
            Board(map);
            if (side) // Человек за X
            {
                while(!Draw(map))
                {
                    Move(map, 'X', first);
                    first = false;
                    Board(map);
                    if (IsWin(map, 'X'))
                    {
                        cout << "\n\nPLAYER 'X' WIN\n\n";
                        break;
                    }
                    Bot(map, 'O', 'X');
                    Board(map);
                    if (IsWin(map, 'O'))
                    {
                        cout << "\n\nPLAYER 'O' WIN\n\n";
                        break;
                    }
                }
            }   
            else // Человек за O
            {
                first = false;
                *(map+112)='X';
                Board(map);
                while(!Draw(map))
                {
                    Move(map, 'O', first);
                    Board(map);
                    if (IsWin(map, 'O'))
                    {
                        cout << "\n\nPLAYER 'O' WIN\n\n";
                        break;
                    }
                    Bot(map, 'X', 'O');
                    Board(map);
                    if (IsWin(map, 'X'))
                    {
                        cout << "\n\nPLAYER 'X' WIN\n\n";
                        break;
                    }
                }
            }
        }

        delete map;
    } while (Again());

    return 0;
}