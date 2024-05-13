#include <iostream>
using namespace std;

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