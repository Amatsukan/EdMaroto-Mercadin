#ifndef LISTA_HPP
#define LISTA_HPP

#include "ElementoLista.hpp"

template <typename T> class Lista{
public:
	Lista();
	void add(T dado);
	// T remove(); // nao precisa mais, os caixas nao podem ser removidos :)
	T get();
	int getSize();
	bool empty();
	void resetaIterador();
private:
	int size;
	ElementoLista<T>* primeiro;
	ElementoLista<T>* ultimo;
	ElementoLista<T>* iterado;
};

template <typename T>
Lista<T>::Lista(){
	size = 0;
}

template <typename T>
void Lista<T>::add(T dado){
	ElementoLista<T>* elemento = new ElementoLista<T>(dado);
	if(empty()){
		primeiro = elemento;
	}else{
		ultimo->prox = elemento;
	}
	size++;
	ultimo = elemento;
	ultimo->prox = primeiro;
}

template <typename T>
void Lista<T>::resetaIterador(){
	iterado = ultimo;
}

template <typename T>
T Lista<T>::get(){
	if(iterado == 0){
		iterado = primeiro;
	}else{
		iterado = iterado->prox;
	}
	return iterado->getDado();
}

template <typename T>
int Lista<T>::getSize(){
	return size;
}

template <typename T>
bool Lista<T>::empty(){
	return size == 0;
}

#endif