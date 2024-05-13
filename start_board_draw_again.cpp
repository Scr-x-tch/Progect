#include <iostream>
using namespace std;

void StartBoard(char* map)
{
     for (short i=0; i<15; i++)
         {
            for (short j=0; j<15; j++)
            {
            *(map+i*15+j) = '+';
            }
        }
}

bool Draw (char* map)
{
    for (short i=0; i<226; i++)
    {
        if (*(map+i) == '+')
        {
            return false;
        }
    }
    return true;
}

bool Again()
{
    short again;
    cout << "Press 1 to play again\n";
    cin >> again;

    if (again == 1) return true;
    else return false;
}