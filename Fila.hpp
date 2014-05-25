#ifndef FILA_HPP
#define FILA_HPP

#include "ElementoFila.hpp"

template <typename T> class Fila{
public:
	Fila();
	void add(T dado);
	T remove();
	T getInicio();
	int getSize();
	bool empty();
private:
	ElementoFila<T>* inicio;
	ElementoFila<T>* fim;
	int size;
};

template <typename T>
Fila<T>::Fila(){
	size = 0;
}

template <typename T>
void Fila<T>::add(T dado){
	ElementoFila<T>* elemento = new ElementoFila<T>(dado);
	if(!empty()){
		fim->prox = elemento;
	}else{
		inicio = elemento;
		fim = inicio;
	}
	size++;
	fim = elemento;
}

template <typename T>
T Fila<T>::remove(){
	if(empty()) throw(-1);
	size--;
	ElementoFila<T>* elemento = inicio;
	inicio = inicio->prox;
	T dado = elemento->getDado();
	delete elemento;
	return dado;
}

template <typename T>
T Fila<T>::getInicio(){
	return inicio->getDado();
}

template <typename T>
int Fila<T>::getSize(){
	return size;
}

template <typename T>
bool Fila<T>::empty(){
	return size == 0;
}

#endif