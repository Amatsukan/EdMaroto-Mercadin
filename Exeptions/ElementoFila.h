#include <stdlib.h>

template <typename T> class ElementoFila{
public:
	ElementoFila(T _dado);
	virtual ~ElementoFila();
	T getDado();
	void setProx(ElementoFila* ElementoFila);
	ElementoFila* getProx();
private:
	T dado;
	ElementoFila<T>* prox;
};

template <typename T>
ElementoFila<T>::ElementoFila(T _dado){
	dado = _dado;
	prox = NULL;
}

template <typename T>
ElementoFila<T>::~ElementoFila(){

}

template <typename T>
T ElementoFila<T>::getDado(){
	return dado;
}

template <typename T>
void ElementoFila<T>::setProx(ElementoFila* ElementoFila){
	prox = ElementoFila;
}

template <typename T>
ElementoFila<T>* ElementoFila<T>::getProx(){
	return prox;
}