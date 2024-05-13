#include <iostream>
#include <windows.h>
using namespace std;

void Board (char* map)
{
    // 4 - красный 2 - зеленый 15 - белый 
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); 
    short i, j;
    system("cls");
    cout << "\n";

    cout << "   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10| 11| 12| 13| 14| 15" << endl;
    cout << "---------------------------------------------------------------" << endl;
    for (i=0; i<15; i++)
    {
        if (i<9)
        {
            cout << " " << i+1;
        }
        else
        {
            cout << i+1;
        }
        cout << " |";

        for (j=0; j<15; j++)
        {
            if (j<14)
            {
                if (*(map+i*15+j) == 'X') SetConsoleTextAttribute(hConsole, 2);
                if (*(map+i*15+j) == 'O') SetConsoleTextAttribute(hConsole, 4);
                cout << " " << *(map+i*15+j);
                SetConsoleTextAttribute(hConsole, 15);
                cout << " |";
            }
            else 
            {
                if (*(map+i*15+j) == 'X') SetConsoleTextAttribute(hConsole, 2);
                if (*(map+i*15+j) == 'O') SetConsoleTextAttribute(hConsole, 4);
                cout << " " << *(map+i*15+j);
                SetConsoleTextAttribute(hConsole, 15);
            }
        }
        cout << "\n";
        if (i != 14) cout << "-------------------------------------------------------------" << endl;
    }
}