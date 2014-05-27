#ifndef ELEMENTOPILHA_HPP
#define ELEMENTOPILHA_HPP

template <typename T>
class ElementoPilha{
public:
	ElementoPilha(T _dado);
	~ElementoPilha();
	T getDado();

	ElementoPilha<T>* prox;
	ElementoPilha<T>* ant;
private:
	T dado;
};

template <typename T>
ElementoPilha<T>::ElementoPilha(T _dado){
	dado = _dado;
	prox = 0;
	ant = 0;
}

template <typename T>
ElementoPilha<T>::~ElementoPilha(){
	delete dado;
	// delete prox;
}

template <typename T>
T ElementoPilha<T>::getDado(){
	return dado;
}

#endif