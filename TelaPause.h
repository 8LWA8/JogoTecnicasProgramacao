#pragma once
#include "Estado.h"
#include "MaquinaEstados.h"

using namespace Estados;

class TelaPause :
    public Estado
{
public:
    TelaPause();
    ~TelaPause();
    void executar();
    void imprimir();
};

