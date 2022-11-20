#include "ConstrutorFase.h"

using namespace Construtor;

ConstrutorFase::ConstrutorFase() {

}

ConstrutorFase::~ConstrutorFase() {

}

Fase* ConstrutorFase::criarFase1() {
    Fase* fase = static_cast<Fase*>(new Fase_Primeira());
    if (fase == nullptr) {
        std::cout << "Nao foi possivel criar a primeira fase" << std::endl;
        exit(1);
    }
    return fase;
}

Fase* ConstrutorFase::criarFase2() {
    Fase* fase = static_cast<Fase*>(new Fase_Segunda());
    if (fase == nullptr) {
        std::cout << "Nao foi possivel criar a segunda fase" << std::endl;
        exit(1);
    }
    return fase;
}

Fase* ConstrutorFase::criarFase(const IDs::IDs ID) {
    Fase* fase = nullptr;
    switch (ID)
    {
    case (IDs::IDs::jogar_fase1):
    {
        fase = criarFase1();
    }
    break;
    case (IDs::IDs::jogar_fase2):
    {
        fase = criarFase2();
    }
    break;
    default:
    {
        std::cout << "ID da Fase invalido" << std::endl;
        exit(1);
    }
    break;
    }
    //fase->criarFundo();
    //fase->criarMapa();
    return fase;
}