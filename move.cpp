#include <iostream>
using namespace std;

void Move(char* map, char letter, bool First)
{
    short i, j; 
    bool free = true;
    
    cout << "\n\nEnter the coordinates of the course " << letter << '\n';
    
    do
    {
        do
        {
            cout << "Enter x: ";
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
            cout << "Enter y: ";
            cin >> i;
            if (i>=15 || i<=0)
            {
                cout << "Enter the correct value\n"; 
                cin.clear();
                cin.ignore(1000, '\n');
            }
        } while (i>15 || i<=0);
    
        if (*(map+(i-1)*15+(j-1)) != '+')
        {
            cout << "The field is occupied by another player\n";
            free = false;
        }
        else free = true;

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