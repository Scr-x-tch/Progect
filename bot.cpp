#include <iostream>
#include "score.hpp"
using namespace std;

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
    *(map+move[1]*15+move[0]) = com_letter;
}