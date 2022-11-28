#include "MaquinaEstados.h"
#include "Estado.h"
#include <iostream>

//Código inspirado nos vídeos do monitor Giovane (Gege++ no youtube) e no seu Github (https://github.com/Giovanenero/JogoPlataforma2D-Jungle)

using namespace Estados;

MaquinaEstados* MaquinaEstados::pMaquinaEstados = nullptr;

MaquinaEstados::MaquinaEstados() : 
    pilhaEstados()
{

}

MaquinaEstados* MaquinaEstados::getMaquinaEstados() {
    if (pMaquinaEstados == nullptr) {
        pMaquinaEstados = new MaquinaEstados();
    }
    return pMaquinaEstados;
}

void Estados::MaquinaEstados::deleteInstance()
{
    if (MaquinaEstados::pMaquinaEstados != NULL)
    {
        MaquinaEstados* pAux = MaquinaEstados::getMaquinaEstados();
        delete pAux;
        pAux = NULL;
    }
}

MaquinaEstados::~MaquinaEstados() {
    //Deleta todos os estados da pilha
    while (!pilhaEstados.empty()) {
        delete(pilhaEstados.top());
        pilhaEstados.top() = nullptr;
        pilhaEstados.pop();
    }

    if (pMaquinaEstados) {
        delete(pMaquinaEstados);
        pMaquinaEstados = nullptr;
    }
}

void MaquinaEstados::addEstado(const IDs::IDs ID) {
    Estado* estado = nullptr;

    std::ifstream arqFase;

    switch (ID)
    {
    case IDs::IDs::jogar_fase1:
        estado = (Estado*) new Fases::Fase_Primeira();
        break;
    case IDs::IDs::jogar_fase2:
        estado = (Estado*) new Fases::Fase_Segunda();
        break;
    case IDs::IDs::carregar_fase1:
        estado = (Estado*) new Fases::Fase_Primeira();
        break;
    case IDs::IDs::carregar_fase2:
        estado = (Estado*) new Fases::Fase_Segunda();
        break;
    case IDs::IDs::menu:
        estado = (Estado*) new Menu();
        break;
    case IDs::IDs::tela_final:
        estado = (Estado*) new TelaFinal();
        break; 
    case IDs::IDs::tela_ranking:
        estado = (Estado*) new TelaRanking();
        break;
    case IDs::IDs::tela_pause:
        estado = (Estado*) new TelaPause();
        break;
    }

    if (estado == nullptr) {
        std::cout << "estado eh nullptr" << std::endl;
        exit(1);
    }
    pilhaEstados.push(estado);
}

void MaquinaEstados::removerEstado() {
    if (pilhaEstados.top() != nullptr) {
        delete(pilhaEstados.top());
        pilhaEstados.top() = nullptr;
        pilhaEstados.pop();
    }

    if (pilhaEstados.empty()) {
        Gerenciadores::GerenteGrafico* pGrafico = pGrafico->getInstance();
        pGrafico->closeWindow();
    }
}

Estado* MaquinaEstados::getEstadoAtual() {
    return pilhaEstados.top();
}


void MaquinaEstados::executar() {
    //executa o estado que está no topo da minha pilha
    if (!pilhaEstados.empty()) {
        pilhaEstados.top()->executar();
    }
}
