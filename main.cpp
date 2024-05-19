#include <iostream>
#include <windows.h>
//#include "main.hpp"
using namespace std;

void Board (char* map)
{
    // 4 - красный 2 - зеленый 15 - белый 
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); 
    short i, j;
    //system("cls");
    cout << "\n";

    cout << "   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10| 11| 12| 13| 14| 15\n";
    cout << "---------------------------------------------------------------\n";
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
        if (i != 14) cout << "-------------------------------------------------------------\n";
    }
}

short score_attak(char* field, char Us_letter, char Com_letter, short y, short x)
{
    short score = 0;
    if (*(field + (y+1)*15 + (x+1)) == Com_letter || *(field + (y-1)*15 + (x-1)) == Com_letter || *(field + (y+1)*15 + (x)) == Com_letter || *(field + (y)*15 + (x+1)) == Com_letter
    || *(field + (y+1)*15 + (x-1)) == Com_letter || *(field + (y-1)*15 + (x+1)) == Com_letter || *(field + (y-1)*15 + (x)) == Com_letter || *(field + (y)*15 + (x-1)) == Com_letter)
    {
        score++;
        for (short i = 1; i <= 4; i++) // диагональ 1 
        {
            if (*(field + (y+i)*15 + (x+i)) != Com_letter) break; // выходит если не символ компьютера
            if (i == 1) score += 2;
            if (i == 2) score += 17;
            if (i == 2 && *(field + (y+i-3)*15 + (x+i-3)) == Com_letter) score+=180;
            if (i == 2 && *(field + (y+i+1)*15 + (x+i+1)) == '+') score+=180;
            if (i == 3) score +=200;
            if (i == 3 && *(field + (y+i-4)*15 + (x+i-4)) == Com_letter) score+=10000;
            if (i == 3 && *(field + (y+i-4)*15 + (x+i-4)) == Us_letter) score-=40;
            if (i == 3 && *(field + (y+i+1)*15 + (x+i+1)) == '+' && (*(field + (y+i+2)*15 + (x+i+2)) == '+' || *(field + (y-1)*15 + (x-1)) == '+')) score+=7000;
            if (i == 4) score+=20000;
        }
        for (short i = 1; i <= 4; i++) // диагональ -1
        {
            if (*(field + (y-i)*15 + (x-i)) != Com_letter) break;
            if (i == 1) score += 2;
            if (i == 2) score += 17;
            if (i == 2 && *(field + (y-i+3)*15 + (x-i+3)) == Com_letter) score+=180;
            if (i == 2 && *(field + (y-i-1)*15 + (x-i-1)) == '+') score+=180;
            if (i == 3) score +=200;
            if (i == 3 && *(field + (y-i+4)*15 + (x-i+4)) == Com_letter) score+=10000;
            if (i == 3 && *(field + (y-i+4)*15 + (x-i+4)) == Us_letter) score-=40;
            if (i == 3 && *(field + (y-i-1)*15 + (x-i-1)) == '+' && (*(field + (y-i-2)*15 + (x-i-2)) == '+' || *(field + (y+1)*15 + (x+1)) == '+')) score+=7000;
            if (i == 4) score+=20000;
        }
        for (short i = 1; i <= 4; i++) // диагональ 2
        {
            if (*(field + (y+i)*15 + (x-i)) != Com_letter) break;
            if (i == 1) score += 2;
            if (i == 2) score += 17;
            if (i == 2 && *(field + (y+i-3)*15 + (x-i+3)) == Com_letter) score+=180;
            if (i == 2 && *(field + (y+i+1)*15 + (x-i-1)) == '+') score+=180;
            if (i == 3) score +=200;
            if (i == 3 && *(field + (y+i-4)*15 + (x-i+4)) == Com_letter) score+=10000;
            if (i == 3 && *(field + (y+i-4)*15 + (x-i+4)) == Us_letter) score-=40;
            if (i == 3 && *(field + (y+i+1)*15 + (x-i-1)) == '+' && (*(field + (y+i+2)*15 + (x-i-2)) == '+' || *(field + (y-1)*15 + (x+1)) == '+')) score+=7000;
            if (i == 4) score+=20000;
        }
        for (short i = 1; i <= 4; i++) // диагональ -2
        {
            if (*(field + (y-i)*15 + (x+i)) != Com_letter) break;
            if (i == 1) score += 2;
            if (i == 2) score += 17;
            if (i == 2 && *(field + (y-i+3)*15 + (x+i-3)) == Com_letter) score+=180;
            if (i == 2 && *(field + (y-i-1)*15 + (x+i+1)) == '+') score+=180;
            if (i == 3) score +=200;
            if (i == 3 && *(field + (y-i+4)*15 + (x+i-4)) == Com_letter) score+=10000;
            if (i == 3 && *(field + (y-i+4)*15 + (x+i-4)) == Us_letter) score-=40;
            if (i == 3 && *(field + (y-i-1)*15 + (x+i+1)) == '+' && (*(field + (y-i-2)*15 + (x+i+2)) == '+' || *(field + (y+1)*15 + (x-1)) == '+')) score+=7000;
            if (i == 4) score+=20000;
        }
        for (short i = 1; i <= 4; i++) // горизонталь
        {
            if (*(field + (y)*15 + (x+i)) != Com_letter) break;
            if (i == 1) score += 2;
            if (i == 2) score += 17;
            if (i == 2 && *(field + (y)*15 + (x+i-3)) == Com_letter) score+=180;
            if (i == 2 && *(field + (y)*15 + (x+i+1)) == '+') score+=180;
            if (i == 3) score +=200;
            if (i == 3 && *(field + (y)*15 + (x+i-4)) == Com_letter) score+=10000;
            if (i == 3 && *(field + (y)*15 + (x+i-4)) == Us_letter) score-=40;
            if (i == 3 && *(field + (y)*15 + (x+i+1)) == '+' && (*(field + (y)*15 + (x+i+2)) == '+' || *(field + (y)*15 + (x-1)) == '+')) score+=7000;
            if (i == 4) score+=20000;
        }
        for (short i = 1; i <= 4; i++) // -горизонталь
        {
            if (*(field + (y)*15 + (x-i)) != Com_letter) break;
            if (i == 1) score += 2;
            if (i == 2) score += 17;
            if (i == 2 && *(field + (y)*15 + (x-i+3)) == Com_letter) score+=180;
            if (i == 2 && *(field + (y)*15 + (x-i-1)) == '+') score+=180;
            if (i == 3) score +=200;
            if (i == 3 && *(field + (y)*15 + (x-i+4)) == Com_letter) score+=10000;
            if (i == 3 && *(field + (y)*15 + (x-i+4)) == Us_letter) score-=40;
            if (i == 3 && *(field + (y)*15 + (x-i-1)) == '+' && (*(field + (y)*15 + (x-i-2)) == '+' || *(field + (y)*15 + (x+1)) == '+')) score+=7000;
            if (i == 4) score+=20000;
        }
        for (short i = 1; i <= 4; i++) // вертикаль 
        {
            if (*(field + (y+i)*15 + (x)) != Com_letter) break;
            if (i == 1) score += 2;
            if (i == 2) score += 17;
            if (i == 2 && *(field + (y+i-3)*15 + x) == Com_letter) score+=180;
            if (i == 2 && *(field + (y+i+1)*15 + x) == '+') score+=180;
            if (i == 3) score +=200;
            if (i == 3 && *(field + (y+i-4)*15 + x) == Com_letter) score+=10000;
            if (i == 3 && *(field + (y+i-4)*15 + x) == Us_letter) score-=40;
            if (i == 3 && *(field + (y+i+1)*15 + x) == '+' && (*(field + (y+i+2)*15 + x) == '+' || *(field + (y-1)*15 + (x)) == '+')) score+=7000;
            if (i == 4) score+=20000;
        }
        for (short i = 1; i <= 4; i++) // -вертикаль
        {
            if (*(field + (y-i)*15 + (x)) != Com_letter) break;
            if (i == 1) score += 2;
            if (i == 2) score += 17;
            if (i == 2 && *(field + (y-i+3)*15 + x) == Com_letter) score+=180;
            if (i == 2 && *(field + (y-i-1)*15 + x) == '+') score+=180;
            if (i == 3) score +=200;
            if (i == 3 && *(field + (y-i+4)*15 + x) == Com_letter) score+=10000;
            if (i == 3 && *(field + (y-i+4)*15 + x) == Us_letter) score-=40;
            if (i == 3 && *(field + (y-i-1)*15 + x) == '+' && (*(field + (y-i-2)*15 + x) == '+' || *(field + (y+1)*15 + (x)) == '+')) score+=7000;
            if (i == 4) score+=20000;
        }
        return score;
    }
    else return score;
}

short score_defence(char* field, char Com_letter, char Us_letter, short y, short x)
{
    short score = 0;
    if (*(field + (y+1)*15 + (x+1)) == Us_letter || *(field + (y-1)*15 + (x-1)) == Us_letter || *(field + (y+1)*15 + (x)) == Us_letter || *(field + (y)*15 + (x+1)) == Us_letter
    || *(field + (y+1)*15 + (x-1)) == Us_letter || *(field + (y-1)*15 + (x+1)) == Us_letter || *(field + (y-1)*15 + (x)) == Us_letter || *(field + (y)*15 + (x-1)) == Us_letter)
    {
        score++;
        for (short i = 1; i <= 4; i++) // диагональ 1
        { 
            if (*(field + (y+i)*15 + (x+i)) != Us_letter) break;
            if (i == 1) score+=1;
            if (i == 1 && *(field + (y-1)*15 + (x-1)) == Us_letter) score +=2;
            if (i == 2) score+=9;
            if (i == 2 && *(field + (y+i+1)*15 + (x+i+1)) == Com_letter) score-=9;
            if (i == 2 && *(field + (y-1)*15 + (x-1)) == Us_letter) score += 5000;
            if (i == 3) score+=200;
            if (i == 3 && *(field + (y+i+1)*15 + (x+i+1)) == Com_letter) score-=95;
            if (i == 3 && *(field + (y+i-4)*15 + (x+i-4)) == Us_letter) score+=9000;
            if (i == 4 && *(field + (y+i+1)*15 + (x+i+1)) == Com_letter) score+=9000; 
        }
        for (short i = 1; i <= 4; i++) // диагональ -1
        {
            if (*(field + (y-i)*15 + (x-i)) != Us_letter) break;
            if (i == 1) score+=1;
            if (i == 1 && *(field + (y+1)*15 + (x+1)) == Us_letter) score +=2;
            if (i == 2) score+=9;
            if (i == 2 && *(field + (y-i-1)*15 + (x-i-1)) == Com_letter) score-=9;
            if (i == 2 && *(field + (y+1)*15 + (x+1)) == Us_letter) score +=5000;
            if (i == 3) score+=200;
            if (i == 3 && *(field + (y-i-1)*15 + (x-i-1)) == Com_letter) score-=95;
            if (i == 3 && *(field + (y-i+4)*15 + (x-i+4)) == Us_letter) score+=9000;
            if (i == 4 && *(field + (y-i-1)*15 + (x-i-1)) == Com_letter) score+=9000;
        }
        for (short i = 1; i <= 4; i++) // диагональ 2
        {
            if (*(field + (y+i)*15 + (x-i)) != Us_letter) break;
            if (i == 1) score+=1;
            if (i == 1 && *(field + (y-1)*15 + (x+1)) == Us_letter) score +=2;
            if (i == 2) score+=9;
            if (i == 2 && *(field + (y+i+1)*15 + (x-i-1)) == Com_letter) score-=9;
            if (i == 2 && *(field + (y-1)*15 + (x+1)) == Us_letter) score +=5000;
            if (i == 3) score+=200;
            if (i == 3 && *(field + (y+i+1)*15 + (x-i-1)) == Com_letter) score-=95;
            if (i == 3 && *(field + (y+i-4)*15 + (x-i+4)) == Us_letter) score+=9000;
            if (i == 4 && *(field + (y+i+1)*15 + (x-i-1)) == Com_letter) score+=9000;
        }
        for (short i = 1; i <= 4; i++) // диагональ -2
        {
            if (*(field + (y-i)*15 + (x+i)) != Us_letter) break;
            if (i == 1) score+=1;
            if (i == 1 && *(field + (y+1)*15 + (x-1)) == Us_letter) score +=2;
            if (i == 2) score+=9;
            if (i == 2 && *(field + (y-i-1)*15 + (x+i+1)) == Com_letter) score -=9;
            if (i == 2 && *(field + (y+1)*15 + (x-1)) == Us_letter) score +=5000;
            if (i == 3) score+=200;
            if (i == 3 && *(field + (y-i-1)*15 + (x+i+1)) == Com_letter) score -=95;
            if (i == 3 && *(field + (y-i+4)*15 + (x+i-4)) == Us_letter) score+=9000;
            if (i == 4 && *(field + (y-i-1)*15 + (x+i+1)) == Com_letter) score+=9000;
        }
        for (short i = 1; i <= 4; i++) // горизонталь
        {
            if (*(field + (y)*15 + (x+i)) != Us_letter) break;
            if (i == 1) score+=1;
            if (i == 1 && *(field + (y)*15 + (x-1)) == Us_letter) score +=2;
            if (i == 2) score+=9;
            if (i == 2 && *(field + (y)*15 + (x+i+1)) == Com_letter) score-=9;
            if (i == 2 && *(field + (y)*15 + (x-1)) == Us_letter) score +=5000;
            if (i == 3) score+=200;
            if (i == 3 && *(field + (y)*15 + (x+i+1)) == Com_letter) score-=95;
            if (i == 3 && *(field + (y)*15 + (x+i-4)) == Us_letter) score+=9000;
            if (i == 4 && *(field + (y)*15 + (x+i+1)) == Com_letter) score+=9000;
        }
        for (short i = 1; i <= 4; i++) // -горизонталь
        {
            if (*(field + (y)*15 + (x-i)) != Us_letter) break;
            if (i == 1) score+=1;
            if (i == 1 && *(field + (y)*15 + (x+1)) == Us_letter) score +=2;
            if (i == 2) score+=9;
            if (i == 2 && *(field + (y)*15 + (x-i-1)) == Com_letter) score-=9;
            if (i == 2 && *(field + (y)*15 + (x+1)) == Us_letter) score +=5000;
            if (i == 3) score+=200;
            if (i == 3 && *(field + (y)*15 + (x-i-1)) == Com_letter) score-=95;
            if (i == 3 && *(field + (y)*15 + (x-i+4)) == Us_letter) score+=9000;
            if (i == 4 && *(field + (y)*15 + (x-i-1)) == Com_letter) score+=9000;
        }
        for (short i = 1; i <= 4; i++) // вертикаль 
        {
            if (*(field + (y+i)*15 + (x)) != Us_letter) break;
            if (i == 1) score+=1;
            if (i == 1 && *(field + (y-1)*15 + (x)) == Us_letter) score +=2;
            if (i == 2) score+=9;
            if (i == 2 && *(field + (y+i+1)*15 + x) == Com_letter) score-=9;
            if (i == 2 && *(field + (y-1)*15 + (x)) == Us_letter) score +=5000;
            if (i == 3) score+=200;
            if (i == 3 && *(field + (y+i+1)*15 + x) == Com_letter) score-=95;
            if (i == 3 && *(field + (y+i-4)*15 + x) == Us_letter) score+=9000;
            if (i == 4 && *(field + (y+i+1)*15 + x) == Com_letter) score+=9000;
        }
        for (short i = 1; i <= 4; i++) // -вертикаль
        {
            if (*(field + (y-i)*15 + (x)) != Us_letter) break;
            if (i == 1) score+=1;
            if (i == 1 && *(field + (y+1)*15 + (x)) == Us_letter) score +=2;
            if (i == 2) score+=9;
            if (i == 2 && *(field + (y-i-1)*15 + x) == Com_letter) score-=9;
            if (i == 2 && *(field + (y+1)*15 + (x)) == Us_letter) score +=5000;
            if (i == 3) score+=200;
            if (i == 3 && *(field + (y-i-1)*15 + x) == Com_letter) score-=95;
            if (i == 3 && *(field + (y-i+4)*15 + x) == Us_letter) score+=9000;
            if (i == 4 && *(field + (y-i-1)*15 + x) == Com_letter) score+=9000;
        }
        return score;
    }
    else return score;
}

void Bot(char* map, char com_letter, char us_letter)
{
    short i=0, j=0;
    short score_at, score_def, best_score = 0;
    short move[2];
    
    for (i=0; i<15; i++)
    {
        for (j=0; j<15; j++)
        {
            if (*(map+i*15+j) == '+')
            {
                score_at = score_attak(map, us_letter, com_letter, i, j);
                score_def = score_defence(map, com_letter, us_letter, i, j);
                score_at += score_def;
                if (score_at > best_score)
                {
                    best_score = score_at; 
                    move[0] = j;
                    move[1] = i;
                }
            }
        }
    }
    cout << move[0] << move[1] << endl;
    *(map+move[1]*15+move[0]) = com_letter;
}

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
        if (*(map + (y) * 15 + (x - i)) == 'X') count3++; 
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
    else if (count1 >= 2) // Диагональ 1
    {
        if (count2 >= 2 || count3 >= 2 || count4 >= 2) 
        {
            if (count1 == 2 && (count2 == 3 || count3 == 3 || count4 == 3)) return true; // Вилка 3 на 4
            if (count1 == 3 && (count2 == 2 || count3 == 2 || count4 == 2)) return true;
            if ((count1+count2+count3+count4)%2==0)return false; // Вилка 3 на 3 или 4 на 4 и тд
        }
    }
    else if (count2 >= 2) // Диагональ 2
    {
        if (count1 >= 2 || count3 >= 2 || count4 >= 2) 
        {
            if (count2 == 2 && (count1 == 3 || count3 == 3 || count4 == 3)) return true; // Вилка 3 на 4
            if (count2 == 3 && (count1 == 2 || count3 == 2 || count4 == 2)) return true;
            if ((count1+count2+count3+count4)%2==0)return false; // Вилка 3 на 3 или 4 на 4 и тд
        }
    }
    else if (count3 >= 2) // Горизонталь 
    {
        if (count2 >= 2 || count1 >= 2 || count4 >= 2) 
        {
            if (count3 == 2 && (count2 == 3 || count1 == 3 || count4 == 3)) return true; // Вилка 3 на 4
            if (count3 == 3 && (count2 == 2 || count1 == 2 || count4 == 2)) return true;
            if ((count1+count2+count3+count4)%2==0) return false; // Вилка 3 на 3 или 4 на 4 и тд
        }
    }
    else if (count4 >= 2) // Вертикаль
    {
        if (count2 >= 2 || count3 >= 2 || count1 >= 2) 
        {
            if (count4 == 2 && (count2 == 3 || count3 == 3 || count1 == 3)) return true; // Вилка 3 на 4
            if (count4 == 3 && (count2 == 2 || count3 == 2 || count1 == 2)) return true;
            if ((count1+count2+count3+count4)%2==0)return false; // Вилка 3 на 3 или 4 на 4 и тд
        }
    }
    
    return true;
}

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

void Move(char* field, char letter, bool First)
{
    short i, j; 
    bool free, rules;
    
    cout << "\n\nEnter the coordinates of the course " << letter << '\n';
    
    do
    {
        free = true;
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
    
        if (*(field+(i-1)*15+(j-1)) != '+') // Поле занято
        {
            cout << "The field is occupied by another player\n";
            free = false;
        }
        else if (letter == 'X' && *(field+(i-1)*15+(j-1)) == '+' )
        {
            rules = CheckingRules (field, j-1, i-1);
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

    *(field+(i-1)*15+(j-1)) = letter;
}

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