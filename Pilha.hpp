#ifndef PILHA_HPP
#define PILHA_HPP

#include "ElementoPilha.hpp"

template <typename T> class Pilha{
public:
	Pilha();
	void add(T dado);
	T remove();
	int getSize();
	bool empty();
private:
	ElementoPilha<T>* topo;
	int size;
};

template <typename T>
Pilha<T>::Pilha(){
	size = 0;
}

template <typename T>
void Pilha<T>::add(T dado){
	ElementoPilha<T>* elemento = new ElementoPilha<T>(dado);
	if(!empty()){
		topo->prox = elemento;
		elemento->ant = topo;
	}
	size++;
	topo = elemento;
}

template <typename T>
T Pilha<T>::remove(){
	if(empty()) throw(-1);
	size--;
	ElementoPilha<T>* elemento = topo;
	topo = topo->ant;
	T dado = elemento->getDado();
	delete elemento;
	return dado;
}

template <typename T>
bool Pilha<T>::empty(){
	return size == 0;
}

template <typename T>
int Pilha<T>::getSize(){
	return size;
}

#endif