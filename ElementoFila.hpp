#ifndef ELEMENTOFILA_HPP
#define ELEMENTOFILA_HPP

template <typename T> class ElementoFila{
public:
	ElementoFila(T _dado);
	T getDado();

	ElementoFila<T>* prox;
private:
	T dado;
};

template <typename T>
ElementoFila<T>::ElementoFila(T _dado){
	dado = _dado;
	prox = 0;
}

template <typename T>
T ElementoFila<T>::getDado(){
	return dado;
}

#endif