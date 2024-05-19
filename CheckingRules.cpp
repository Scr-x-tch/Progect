#include <iostream>
using namespace std;

bool CheckingRules (char* map, short x, short y)
{
    short count1, count2, count3, count4;

    for (short i=1; i<=4; i++) // диагональ 1
    {
        if (*(map + (y + i) * 15 + (x + i)) == 'X') count1++; 
        else break;
    }
    for (short i=1; i<=4; i++) // диагональ -1
    {
        if (*(map + (y - i) * 15 + (x - i)) == 'X') count1++; 
        else break;
    }
    for (short i=1; i<=4; i++) // диагональ 2
    {
        if (*(map + (y - i) * 15 + (x + i)) == 'X') count2++; 
        else break;
    }
    for (short i=1; i<=4; i++) // диагональ -2
    {
        if (*(map + (y + i) * 15 + (x - i)) == 'X') count2++; 
        else break;
    }
    for (short i=1; i<=4; i++) // горизонталь
    {
        if (*(map + (y) * 15 + (x + i)) == 'X') count3++; 
        else break;
    }
    for (short i=1; i<=4; i++) // -горизонталь
    {
        if (*(map + (y + i) * 15 + (x - i)) == 'X') count3++; 
        else break;
    }
    for (short i=1; i<=4; i++) // вертикаль
    {
        if (*(map + (y + i) * 15 + (x)) == 'X') count4++; 
        else break;
    }
    for (short i=1; i<=4; i++) // -вертикаль
    {
        if (*(map + (y - i) * 15 + (x)) == 'X') count4++; 
        else break;
    }


//условия нарушения правил
    if (count1 >= 6 || count2 >= 6 || count3 >= 6 || count4 >= 6) 
    {
        return false; // Длинный ряд
    }
    else if (count1 >= 2) 
    {
        if (count2 >= 2 || count3 >= 2 || count4 >= 2) 
        {
            if (count1 == 2 && (count2 == 3 || count3 == 3 || count4 == 3)) return true; // Вилка 3 на 4
            return false; // Вилка 3 на 3 или 4 на 4 и тд
        }
    }
    else if (count2 >= 2)
    {
        if (count1 >= 2 || count3 >= 2 || count4 >= 2) 
        {
            if (count2 == 2 && (count1 == 3 || count3 == 3 || count4 == 3)) return true; // Вилка 3 на 4
            return false; // Вилка 3 на 3 или 4 на 4 и тд
        }
    }
    else if (count3 >= 2)
    {
        if (count2 >= 2 || count1 >= 2 || count4 >= 2) 
        {
            if (count3 == 2 && (count2 == 3 || count1 == 3 || count4 == 3)) return true; // Вилка 3 на 4
            return false; // Вилка 3 на 3 или 4 на 4 и тд
        }
    }
    else if (count4 >= 2)
    {
        if (count2 >= 2 || count3 >= 2 || count1 >= 2) 
        {
            if (count4 == 2 && (count2 == 3 || count3 == 3 || count1 == 3)) return true; // Вилка 3 на 4
            return false; // Вилка 3 на 3 или 4 на 4 и тд
        }
    }
    else return true;
}