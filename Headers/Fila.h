#include "ElementoFila.h"
#include "EstruturaVaziaException.h"
#include "PosicaoInvalidaException.h"
#include "OutOfMemoryException.h"

template <typename T>
class Fila{
public:
	Fila();
	virtual ~Fila();
	void add(T dado);
	T remove();
	T get(int pos);
	int size();
	bool filaVazia();
private:
	ElementoFila<T>* primeiroElemento;
	ElementoFila<T>* ultimoElemento;
	int numElementos;
};

template <typename T>
Fila<T>::Fila(){
	numElementos = 0;
}

template <typename T>
Fila<T>::~Fila(){

}

template <typename T>
void Fila<T>::add(T dado){
	ElementoFila<T>* elemento = new ElementoFila<T>(dado);
	if (elemento != NULL){
		if (filaVazia()){
			primeiroElemento = elemento;
		}
		else{
			ultimoElemento->setProx(elemento);
		}
		numElementos++;
		ultimoElemento = elemento;
	}
	else{
		throw new OutOfMemoryException;
	}
}

template <typename T>
T Fila<T>::remove(){
	if (filaVazia()){
		throw new EstruturaVaziaException;
	}
	numElementos--;
	ElementoFila<T>* elemento = primeiroElemento;
	primeiroElemento = primeiroElemento->getProx();
	T dado = elemento->getDado();
	delete elemento;
	return dado;
}

template <typename T>
T Fila<T>::get(int pos){
	if (filaVazia()){
		throw new EstruturaVaziaException;
	}
	else if (pos < 0 or pos > numElementos){
		throw new PosicaoInvalidaException;
	}
	ElementoFila<T>* elemento = primeiroElemento;
	for (int i = 0; i < pos; i++){
		elemento = elemento->getProx();
	}
	return elemento->getDado();
}

template <typename T>
int Fila<T>::size(){
	return numElementos;
}

template <typename T>
bool Fila<T>::filaVazia(){
	return numElementos == 0;
}