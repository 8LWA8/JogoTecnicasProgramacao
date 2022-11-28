// JogoTecProg.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Jogo.h"
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    Jogo jogo; 

	jogo.exec();
    
    return 0;
}