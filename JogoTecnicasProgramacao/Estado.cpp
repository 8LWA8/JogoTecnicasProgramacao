#include "Estado.h"
#include "MaquinaEstados.h"

using namespace Estados;

//C�digo inspirado nos v�deos do monitor Matheus Augusto Burda (Burda Canal no youtube)
Estados::Estado::Estado(MaquinaEstados* pME, IDestado id): pME(pME), id(id)
{
}

Estados::Estado::~Estado()
{
	pME = nullptr;
}

void Estados::Estado::setMaquinaEstados(MaquinaEstados* pME)
{
	this->pME = pME;
}

void Estados::Estado::mudarEstado(IDestado id)
{
	pME->mudaEstadoAtual(id);
}

IDestado Estados::Estado::getID() const
{
	return id;
}
