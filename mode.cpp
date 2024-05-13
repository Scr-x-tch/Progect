#include <iostream>
using namespace std;

bool Mode()
{
    system("cls");
    cout << "\n\nI am glad to welcome you to the Renju game.\n\n" << endl;
    cout << "Which mode do you want to choose?\n" << endl;
    cout << "1 - Against a human\n2 - Against a bot\n" << endl;
    char mode;

    cin >> mode;
    while (mode != '1' && mode != '2')
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Select the number that represents your game mode. (1 or 2)\n";
        cin >> mode;
    }

    if (mode == '1')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Side()
{
    char side;
    cout << "\nWhich side do you want to play for?\n";
    cout << "1 - X\n2 - O\n\n";

    cin >> side;

    while (side != '1' && side != '2')
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Select the number that represents your game mode. (1 or 2)\n\n";
        cin >> side;
    }

    if (side == '1')
    {
        return true;
    }
    else 
    {
        return false;
    }
}