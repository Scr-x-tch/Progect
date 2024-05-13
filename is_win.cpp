#include <iostream>
using namespace std;

bool IsWin(char* map, char letter)
{
    for (short i=0; i<15; i++)
    {
        for (short j=0; j<15; j++)
        {
            if ((i <= 1 || i >= 13) && (j > 1 && j < 13)) // Две левые и правые строчки
            {
                if (*(map+i*15+j) == letter)
                {
                    if(*(map+i*15+(j-1)) == letter && *(map+i*15+(j-2)) == letter && *(map+i*15+(j+1)) == letter && *(map+i*15+(j+2)) == letter)
                    {
                        return true;
                    }
                }
            }
            else if ((j <= 1 || j >= 13) && (i > 1 && i < 13)) // Две верхние и нижние строчки 
            {
                if (*(map+i*15+j) == letter)
                {
                    if(*(map+(i-1)*15+j) == letter && *(map+(i-2)*15+j) == letter && *(map+(i+1)*15+j) == letter && *(map+(i+2)*15+j) == letter)
                    {
                        return true;
                    }
                }
            }
            else if ((j > 1 || j < 13) && (i > 1 || i < 13)) // Центральная часть поля
            {
                if (*(map+i*15+j) == letter)
                {
                    if((*(map+(i-1)*15+(j-1)) == letter && *(map+(i-2)*15+(j-2)) == letter && *(map+(i+1)*15+(j+1)) == letter && *(map+(i+2)*15+(j+2)) == letter) ||
                    (*(map+(i-1)*15+(j+1)) == letter && *(map+(i-2)*15+(j+2)) == letter && *(map+(i+1)*15+(j-1)) == letter && *(map+(i+2)*15+(j-2)) == letter) ||
                    (*(map+i*15+(j-1)) == letter && *(map+i*15+(j-2)) == letter && *(map+i*15+(j+1)) == letter && *(map+i*15+(j+2)) == letter) ||
                    (*(map+(i-1)*15+j) == letter && *(map+(i-2)*15+j) == letter && *(map+(i+1)*15+j) == letter && *(map+(i+2)*15+j) == letter))
                    {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}