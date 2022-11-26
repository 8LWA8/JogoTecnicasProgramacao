#pragma once
#include "Estado.h"
#include <map>
#include <cstring>
#include <fstream>
#include <iostream>

using namespace Estados;
using namespace std;

class TelaRanking :
    public Estado
{
    map<int, string> mapaRanking;

public:
    TelaRanking();
    ~TelaRanking();
    void recuperarRank();
    void executar();
    void imprimir();
};

