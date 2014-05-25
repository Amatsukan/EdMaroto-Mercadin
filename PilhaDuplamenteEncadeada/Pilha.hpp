#include <stdlib.h>

#include "ElementoPilha.hpp"
#include "OutOfMemoryException.h"
#include "EstruturaVaziaException.h"

template <typename T>
class Pilha{
	public:
		Pilha();
		virtual ~Pilha();
		void add(T dado);
		T remove();
		int size();
		bool pilhaVazia();
	private:
		ElementoPilha<T>* topo;
		int numElementos;
};

template <typename T>
Pilha<T>::Pilha(){
	numElementos = 0;
	topo = NULL;
}

template <typename T>
Pilha<T>::~Pilha(){

}

template <typename T>
void Pilha<T>::add(T dado){
	ElementoPilha<T>* elemento = new ElementoPilha<T>(dado);
	if(elemento == NULL) throw new OutOfMemoryException;
	if(!pilhaVazia()){
		elemento->setAnt(topo);
		topo->setProx(elemento);
	}
	numElementos++;
	topo = elemento;
}

template <typename T>
T Pilha<T>::remove(){
	if(pilhaVazia()) throw new EstruturaVaziaException;
	numElementos--;
	ElementoPilha<T>* elemento = topo->getAnt();
	T dado = topo->getDado();
	delete topo;
	topo = elemento;
	return dado;
}

template <typename T>
int Pilha<T>::size(){
	return numElementos;
}

template <typename T>
bool Pilha<T>::pilhaVazia(){
	return numElementos == 0;
}