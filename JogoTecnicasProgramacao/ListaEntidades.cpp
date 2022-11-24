#include "ListaEntidades.h"
//#include "Lista.h"
//using namespace Listas;

//Esse código foi inspirado em "ListaEntidade.cpp" do JogoPlataforma2D-Jungle do monitor Giovanenero no GitHub. 

Listas::ListaEntidades::ListaEntidades():LEs()
{
}

Listas::ListaEntidades::~ListaEntidades()
{
}

void Listas::ListaEntidades::addEntidade(Entidade* entidade)
{
	LEs.incluaElemento(entidade);
}

void Listas::ListaEntidades::removerEntidade(Entidade* entidade)
{
	LEs.removerElemento(entidade);
}

void Listas::ListaEntidades::removerEntidade(int pos)
{
	LEs.removerElemento(pos);
}

int Listas::ListaEntidades::getTam()
{
	return LEs.getTam();
}

Entidade* Listas::ListaEntidades::operator[](int pos)
{
	return LEs.operator[](pos);
}

void Listas::ListaEntidades::limpaLista()
{
	LEs.limpaLista();
}

void Listas::ListaEntidades::executarTodos()
{
	int tam = LEs.getTam();
	Entidade* aux = nullptr;
	for (int i = 0; i < tam; i++)
	{
		//cout << "loop exetds" << endl;
		aux = LEs.operator[](i);
		aux->executar();
	}
}

void Listas::ListaEntidades::salvarTodos()
{
	int tam = LEs.getTam();
	Entidade* aux = nullptr;
	for (int i = 0; i < tam; i++)
	{
		aux = LEs.operator[](i);
		aux->salvar();
	}
}
