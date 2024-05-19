#include <iostream>
#include "Check.hpp"
using namespace std;

void Move(char* map, char letter, bool First)
{
    short i, j; 
    bool free = true, rules;
    
    cout << "\n\nEnter the coordinates of the course " << letter << '\n';
    
    do
    {
        do
        {
            cout << "Enter x: "; // Вводим Х
            cin >> j;
            if (j>15 || j<=0)
            {
                cout << "Enter the correct value\n"; 
                cin.clear();
                cin.ignore(1000, '\n');
            }
        } while (j>15 || j<=0);

        do 
        {
            cout << "Enter y: "; // Вводим У
            cin >> i;
            if (i>=15 || i<=0)
            {
                cout << "Enter the correct value\n"; 
                cin.clear();
                cin.ignore(1000, '\n');
            }
        } while (i>15 || i<=0);
    
        if (*(map+(i-1)*15+(j-1)) != '+') // Поле занято
        {
            cout << "The field is occupied by another player\n";
            free = false;
        }
        else if (letter == 'X' && *(map+(i-1)*15+(j-1)) == '+' )
        {
            rules = CheckingRules (map, j, i);
            if (!rules)
            {
                cout <<"The move violates the rules of the game"<< endl;
                free = false;
            }
        }

        if (First)
        {
            if ((i!=8) || (j!=8))
            {
                cout << "First move 'X' x=8 y=8\n";
                free = false;
            }
        }

    } while (!free);

    *(map+(i-1)*15+(j-1)) = letter;
}