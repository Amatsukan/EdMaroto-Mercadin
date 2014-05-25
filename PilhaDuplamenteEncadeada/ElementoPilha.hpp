template <typename T>
class ElementoPilha{
	public:
		ElementoPilha(T _dado);
		virtual ~ElementoPilha();
		T getDado();
		ElementoPilha<T>* getProx();
		ElementoPilha<T>* getAnt();
		void setProx(ElementoPilha<T>* _prox);
		void setAnt(ElementoPilha<T>* _ant);
	private:
		ElementoPilha<T>* prox;
		ElementoPilha<T>* ant;
		T dado;
};

template <typename T>
ElementoPilha<T>::ElementoPilha(T _dado){
	dado = _dado;
}

template <typename T>
ElementoPilha<T>::~ElementoPilha(){

}

template <typename T>
T ElementoPilha<T>::getDado(){
	return dado;
}

template <typename T>
ElementoPilha<T>* ElementoPilha<T>::getProx(){
	return prox;
}

template <typename T>
ElementoPilha<T>* ElementoPilha<T>::getAnt(){
	return ant;
}

template <typename T>
void ElementoPilha<T>::setProx(ElementoPilha<T>* _prox){
	prox = _prox;
}

template <typename T>
void ElementoPilha<T>::setAnt(ElementoPilha<T>* _ant){
	ant = _ant;
}