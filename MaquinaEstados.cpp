#include "MaquinaEstados.h"
#include "Estado.h"
#include <iostream>

using namespace Estados;

Estados::MaquinaEstados::MaquinaEstados()
{
	IDultimo = IDestado::desconhecido;
	IDatual = IDestado::desconhecido;
}

Estados::MaquinaEstados::~MaquinaEstados()
{
	std::map<IDestado, Estado*>::iterator it;

	for (it = mapaEstados.begin(); it != mapaEstados.end(); ++it) {
		delete (it->second);
	}
}

void Estados::MaquinaEstados::mudaEstadoAtual(IDestado id)
{
	IDultimo = IDatual;
	IDatual = id;
	mapaEstados[IDatual]->resetEstado();
}

void Estados::MaquinaEstados::updateEstadoAtual(const float dt)
{
	mapaEstados[IDatual]->update(dt);
}

void Estados::MaquinaEstados::renderEstadoAtual()
{
	mapaEstados[IDatual]->render();
}

IDestado Estados::MaquinaEstados::getIDatual() const
{
	return IDatual;
}

void Estados::MaquinaEstados::insereEstado(Estado* pEstado)
{
	if (pEstado == nullptr) {
		std::cout << "ERROR pointer to State NULL on StateMachine::insertState()" << std::endl;
		exit(1);
	}
	mapaEstados.insert(std::pair<IDestado, Estado*>(pEstado->getID(), pEstado));
}

IDestado Estados::MaquinaEstados::getIDultimo() const
{
	return IDultimo;
}
