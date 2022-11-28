#pragma once
#include <SFML/Graphics.hpp>

#include <iostream>
using namespace std;

namespace Listas
{
//Esse código foi inspirado em "Elemento.h" e "Lista.h" do Grupo de Slides 10 - Parte A/B do sistema acadêmico
//e também em "Lista.hpp" do JogoPlataforma2D-Jungle do monitor Giovanenero no GitHub. 
	template<class TL>
	class Lista
	{
			
		template<class TE> class Elemento
		{
		private:
			Elemento<TE>* pProx;
			TE* pInfo;
		public:
			Elemento();
			~Elemento();

			void setProx(Elemento<TE>* pP);
			Elemento<TE>* getProx();

			void setInfo(TE* pI);
			TE* getInfo();
		};

	Elemento<TL>* pPrimeiro;
	Elemento<TL>* pUltimo;
	unsigned int tam;

	public:

	Lista();
	~Lista();
	void limpaLista();
	void incluaElemento(TL* pElemento);
	void removerElemento(TL* elemento);
	void removerElemento(int pos);
	int getTam();
	TL* operator[](int pos);
	};

	template<class TL>
	template<class TE>
	Lista<TL>::Elemento<TE>::Elemento()
	{
		pProx = nullptr; pInfo = nullptr;
	}

	template<class TL>
	template<class TE>
	Lista<TL>::Elemento<TE>::~Elemento()
	{
		pProx = nullptr; pInfo = nullptr;
	}

	template<class TL>
	template<class TE>
	void Lista<TL>::Elemento<TE>::setProx(Elemento<TE>* pP)
	{
		pProx = pP;
	}

	template<class TL>
	template<class TE>
	Lista<TL>::Elemento<TE>* Lista<TL>::Elemento<TE>::getProx()
	{
		return pProx;
	}

	template<class TL>
	template<class TE>
	void Lista<TL>::Elemento<TE>::setInfo(TE* pI)
	{
		pInfo = pI;
	}

	template<class TL>
	template<class TE>
	TE* Lista<TL>::Elemento<TE>::getInfo()
	{
		return pInfo;
	}

	//FUNÇÕES LISTA
	template<class TL>
	Lista<TL>::Lista(): tam(0)
	{
		pPrimeiro = nullptr; pUltimo = nullptr;
	}

	template<class TL>
	Lista<TL>::~Lista()
	{
		limpaLista();
		pPrimeiro = nullptr; pUltimo = nullptr;
	}

	template<class TL>
	void Lista<TL>::limpaLista()
	{

		if (pPrimeiro) {

			Elemento<TL>* aux = pPrimeiro;
			Elemento<TL>* aux2 = nullptr;

			while (aux != nullptr) {
				aux2 = aux->getProx();
				delete(aux->getInfo());
				aux = nullptr;
				aux = aux2;
			}
		}
		pPrimeiro = nullptr;
		pUltimo = nullptr;
	}

	template<class TL>
	void Lista<TL>::incluaElemento(TL* pI)
	{
		if (pI == nullptr) {
			std::cout << "ERROR::Lista elemento eh nullptr" << std::endl;
			exit(1);
		}

		Elemento<TL>* pElemento = new Elemento<TL>();

		if (pElemento == nullptr) {
			std::cout << "ERROR::Lista aux eh nullptr" << std::endl;
			exit(1);
		}

		pElemento->setInfo(pI);
		
		if (pPrimeiro == nullptr)
		{
			pPrimeiro = pElemento;
			pPrimeiro->setProx(nullptr);
			pUltimo = pElemento;
		}
		else
		{
			//pElemento->setProx(nullptr);
			pUltimo->setProx(pElemento);
			pUltimo = pElemento;
		}
		tam++;
		//cout << "Elemento incluido." << endl;
		
	}

	template<class TL>
	void Lista<TL>::removerElemento(TL* elemento) {
		if (elemento == nullptr) {
			std::cout << "ERROR::Lista elemento eh nullptr" << std::endl;
			exit(1);
		}
		Elemento<TL>* aux = pPrimeiro;
		Elemento<TL>* aux2 = nullptr;
		while (aux != nullptr && aux->getInfo() != elemento) {
			aux2 = aux;
			aux = aux->getProx();
		}
		if (aux->getInfo() == elemento) {
			if (aux == pPrimeiro) {
				pPrimeiro = aux->getProx();
			}
			else if (aux == pUltimo) {
				pUltimo = aux2;
			}
			else {
				aux2->setProx(aux->getProx());
			}
			tam--;
			delete(aux);
			aux = nullptr;
			aux2 = nullptr;
		}

	}

	template<class TL>
	void Lista<TL>::removerElemento(int pos) {
		TL* elemento = operator[](pos);
		return removerElemento(elemento);
	}

	template<class TL>
	int Lista<TL>::getTam() {
		return (int)tam;
	}

	template<class TL>
	TL* Lista<TL>::operator[](int pos) {
		if (pos >= (int)tam || pos < 0) {
			std::cout << "ERROR::Lista pos eh maior que o tamanho da lista ou eh negativo" << std::endl;
			exit(1);
		}
		Elemento<TL>* aux = pPrimeiro;
		for (int i = 0; i < pos; i++) {
			aux = aux->getProx();
		}
		return aux->getInfo();
	}

}