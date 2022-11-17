#pragma once
#include "Lista.h"
#include "Entidade.h"

using namespace Entidades;

namespace Listas
{
	class ListaEntidades
	{
	private:
		Lista<Entidade> LEs;
	public:
		ListaEntidades();
		~ListaEntidades();
		void addEntidade(Entidade* entidade);
		void removerEntidade(Entidade* entidade);
		void removerEntidade(int pos);
		int getTam();
		Entidade* operator[](int pos);
		void limpaLista();
		void executarTodos();
	};
}