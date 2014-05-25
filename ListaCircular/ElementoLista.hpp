#include <stdlib.h>

template <typename T> class ElementoLista{
	public:
		ElementoLista(T _dado);
		virtual ~ElementoLista();
		T getDado();
		void setProx(ElementoLista* prox);
		ElementoLista* getProx();
	private:
		ElementoLista* proxElementoLista;
		T dado;
};

template <typename T>
ElementoLista<T>::ElementoLista(T _dado){
	dado = _dado;
	proxElementoLista = NULL;
}

template <typename T>
T ElementoLista<T>::getDado(){
	return dado;
}

template <typename T>
void ElementoLista<T>::setProx(ElementoLista* prox){
	proxElementoLista = prox;
}

template <typename T>
ElementoLista<T>* ElementoLista<T>::getProx(){
	return proxElementoLista;
}

template <typename T>
ElementoLista<T>::~ElementoLista(){

}