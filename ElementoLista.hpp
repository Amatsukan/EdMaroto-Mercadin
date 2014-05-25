#ifndef ELEMENTOLISTA_HPP
#define ELEMENTOLISTA_HPP

template <typename T> class ElementoLista{
public:
	ElementoLista(T _dado);
	T getDado();

	ElementoLista<T>* prox;
private:
	T dado;
};

template <typename T>
ElementoLista<T>::ElementoLista(T _dado){
	dado = _dado;
	prox = 0;
}

template <typename T>
T ElementoLista<T>::getDado(){
	return dado;
}

#endif