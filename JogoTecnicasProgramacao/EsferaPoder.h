#pragma once
#include "Entidade.h"

using namespace Entidades;

class EsferaPoder :
    public Entidade
{
private:
    bool coletada;
public:
    EsferaPoder();
    EsferaPoder(const sf::Vector2f pos);
    ~EsferaPoder();
    void setColetada(bool c);
    bool getColetada();
    void executar();
    void danar(Entidade* ent);


    //TESTE VIRTUAL PURA
    void salvar();
};