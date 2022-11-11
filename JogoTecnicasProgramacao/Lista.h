#pragma once
#include <SFML/Graphics.hpp>

#include <iostream>
using namespace std;

namespace Listas
{/*
	class Lista
	{

	public:
		template<class TipoE>
		class Elemento
		{
		private: //lista duplamente encadeada
			Elemento* next;
			Elemento* prev;
			TipoE elemento; //conteudo
			bool liberar;

		public:
			Elemento(TipoE elemento, bool liberar = true) :
				elemento(elemento),
				next(nullptr),
				prev(nullptr),
				liberar(true) {
				if (liberar && elemento != nullptr)
					delete elemento;
				next = prev = nullptr;
				elemento = nullptr;
			}
			~Elemento()
			{
				if (liberar && elemento != nullptr)
					delete elemento;
				next = nullptr;
				prev = nullptr;
				elemento = nullptr;

			}


		};*/
		//Fim de elemento
	/*	void setNext(Elemento* next) { this->next = next; };
		Elemento* getNext() const { return this->next; };
		void setPrev(Elemento* prev) { this->prev = prev; };
		Elemento* getPrev() const { return this->prev; };
		void set(TipoE* elemento) { this->elemento = elemento; };
		TipoE* getElem() { return this->element; };

		//OPERADORES
		Elemento* operator++() const { this = this->getNext(); };
		Elemento* operator--() const { this = this->getPrev(); };
		void operator=(TipoE& elemento) { this->set(elemento); };
		bool operator==(TipoE& elemento) { return this->elemento == elemento; };

	};

protected:

	Elemento<Tipo>* pPrimeiro;
	Elemento<Tipo>* pUltimo;
	int tam;

public:
	Lista() : pPrimeiro(nullptr), pUltimo(nullptr), tam(0) {}
	~Lista() { clearAll(); };
	//Getters and Setters

	const int getTam() const { return this->tam; }

	void incluirPri(Tipo* elemento, bool liberar = true) { this->add(elemento, liberar, true); }

	void incluirUlt(Tipo* elemento, bool liberar = true) { this->add(elemento, liberar, false); }

	void incluirElement(Tipo* elemento, bool liberar, bool front)
	{
		tam++;
		Elemento<Tipo>* novo = new Elemento<Tipo>(elemento, liberar);

		if (this->pPrimeiro == nullptr)
		{
			this->pPrimeiro = this->pUltimo = novo;
			return;
		}

		if (front)
		{
			novo->setNext(this->pPrimeiro);
			this->pPrimeiro->setPrev(novo);
			this->pPrimeiro = novo;
		}
		else
		{
			novo->setPrev(this->pUltimo);
			this->pUltimo->setNext(novo);
			this->pUltimo = novo;
		}
	}

	void remover(Tipo* elemento)
	{
		auto itr = this->pPrimeiro; //"auto" pega a clase do elemento

		while (itr != nullptr)
		{
			if (itr->getElem() == elemento)
			{
				if (itr == this->pPrimeiro || itr == this->pLast)
				{
					if (itr == this->pPrimeiro)
					{
						this->pPrimeiro = this->pPrimeiro->getNext();
					}
					else
					{
						this->pUltimo = this->pUltimo->getPrev();
						if (this->pUltimo != nullptr)
							this->pUltimo->setNext(nullptr);
					}
				}
				else
				{
					if (itr->getNext() != nullptr)
						itr->getNext()->setPrev(itr->getPrev());
					if (itr->getPrev() != nullptr)
						itr->getPrev()->setNext(itr->getNext());
				}
				delete itr; //finalmente elimina elemento
				tam--;
				break;
			}
			itr = itr->getNext();
		}
	}

	Tipo* getPri() const
	{
		return this->pPrimeiro->get();
	}

	Tipo* getElem(int i_elemento) const
	{
		if (i_elemento >= tam) //verifica indice valido
			throw runtime_error("ERROR getElem(): index out of range");

		int i;
		Elemento<Tipo>* itr = this->pPrimeiro;
		for (i = 0; i <= i_elemento; i++)
			itr++;		//passa para o proximo elemento

		return itr->get()//returna o elemento
	}

	Elemento<Tipo>* begin() const { return this->pPrimeiro; };

	void clearAll()
	{
		this->tam = 0;

		Elemento<Tipo>* aux;

		while (this->pPrimeiro != nullptr && this->tam > 0)
		{
			aux = this->pPrimeiro++;
			delete this->pPrimeiro;
			this->pPrimeiro = aux;
		}

		this->pPrimeiro = nullptr;
		this->pUltimo = nullptr;
	};

	virtual void operator +=(Tipo& elemento) { this->incluiPri(&elemento); };
	virtual void operator -=(Tipo& elemento) { this->remover(&elemento); };
	virtual Tipo* operator[](int index) { return this->get(index); };

	*/
	//};

//Esse código foi inspirado em "Elemento.h" e "Lista.h" do Grupo de Slides 10 - Parte A/B do sistema acadêmico
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

	public:

	Lista();
	~Lista();

	void limpaLista();
	void incluaElemento(TL* pElemento);
	void executarTodos();
	void grave();
	void recupere();
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

	template<class TL>
	Lista<TL>::Lista()
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
		Elemento<TL>* paux1;
		Elemento<TL>* paux2;

		paux1 = pPrimeiro;
		paux2 = paux1;

		while (paux1 != nullptr)
		{
			paux2 = paux1->getProx();
			delete (paux1);
			paux1 = paux2;
		}

		pPrimeiro = nullptr;
		pUltimo = nullptr;
	}

	template<class TL>
	void Lista<TL>::incluaElemento(TL* pI)
	{
		Elemento<TL>* pElemento = new Elemento<TL>();
		pElemento->setInfo(pI);
		
		if (pElemento != nullptr)
		{
			if (pPrimeiro == nullptr)
			{
				pPrimeiro = pElemento;
				pPrimeiro->setProx(nullptr);
				pUltimo = pPrimeiro;
			}
			else
			{
				pElemento->setProx(nullptr);
				pUltimo->setProx(pElemento);
				pUltimo = pUltimo->getProx();
			}

			cout << "Elemento incluido." << endl;
		}
		else
		{
			cout << "Erro. Elemento nulo na lista, nao foi posssivel incluir." << endl;
		}
	}

	template<class TL>
	void Lista<TL>::executarTodos()
	{
		Elemento<TL>* paux;
		paux = pPrimeiro;
		
		if (pPrimeiro != nullptr)
		{
			while (paux != nullptr)
			{	
				paux->getInfo()->executar();
				paux = paux->getProx();
			}
		}
	}

}