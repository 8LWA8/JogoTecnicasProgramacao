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
    void anularGravidade();

    //TESTE VIRTUAL PURA
    std::string salvar();
};