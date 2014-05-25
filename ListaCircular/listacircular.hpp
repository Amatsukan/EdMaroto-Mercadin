#include "ElementoLista.hpp"
#include "EstruturaVazia.h"
#include "EstruturaCheia.h"
#include "PosicaoInvalida.h"
#include "DadoNaoEncontradoException.h"
#include <iostream>

template <typename T> class ListaCircular{
    public:
        ListaCircular();
        virtual ~ListaCircular();
        void add(T dado);
        void addNoInicio(T dado);
        void addNaPosicao(T dado, int posicao);
        T remove();
        T removeDoInicio();
        T removeDaPosicao(int posicao);
        T removeEspecifico(T dado);
        T getDado(int posicao);
        ElementoLista<T>* get(int posicao);
        int size();

        bool listaVazia();
        int posicao(T dado);
        bool contem(T dado);
    private:
        int numElementos;
        ElementoLista<T>* primeiroElemento;
        ElementoLista<T>* ultimoElemento;
};

template <typename T> 
ListaCircular<T>::ListaCircular(){
    numElementos = 0;
    primeiroElemento = NULL;
    ultimoElemento = primeiroElemento;
}

template <typename T> 
ListaCircular<T>::~ListaCircular(){

}

template <typename T> 
void ListaCircular<T>::add(T dado){
    ElementoLista<T>* elemento = new ElementoLista<T>(dado);
    if(listaVazia()){
        primeiroElemento = elemento;
    }else{
        ultimoElemento->setProx(elemento);
    }
    ultimoElemento = elemento;
    ultimoElemento->setProx(primeiroElemento);
    numElementos++;
}

template <typename T> 
void ListaCircular<T>::addNoInicio(T dado){
    numElementos++;
    ElementoLista<T>* elemento = new ElementoLista<T>(dado);
    if(listaVazia()){
        ultimoElemento = elemento;
    }else{
        ElementoLista<T>* aux = primeiroElemento;
        primeiroElemento = elemento;
        primeiroElemento->setProx(aux);
    }
    ultimoElemento->setProx(primeiroElemento);
}

template <typename T>
void ListaCircular<T>::addNaPosicao(T dado, int posicao){
    numElementos++;
    ElementoLista<T>* elemento = new ElementoLista<T>(dado);
    ElementoLista<T>* aux = primeiroElemento;
    for(int i = 0; i < posicao-1; i++){
        if(aux->getProx() != NULL){
            aux = aux->getProx();
        }
    }
    ElementoLista<T>* aux2 = aux->getProx();
    aux->setProx(elemento);
    elemento->setProx(aux2);
}

template <typename T>
T ListaCircular<T>::removeDaPosicao(int posicao){
    if(listaVazia()) throw new EstruturaVazia;
    if(posicao > numElementos) throw new PosicaoInvalida;
    numElementos--;
    ElementoLista<T>* aux = primeiroElemento;
    for(int i = 1; i < posicao-1; i++){
        aux = aux->getProx();
    }
    ElementoLista<T>* aux2 = aux->getProx();
    ElementoLista<T>* elemento = aux->getProx();
    aux->setProx(aux2->getProx());
    T dado = elemento->getDado();
    delete elemento;
    return dado;
}

template <typename T>
T ListaCircular<T>::remove(){
    if(listaVazia()) throw new EstruturaVazia;
    if(numElementos == 1) return removeDoInicio();
    T dado = removeDaPosicao(numElementos);
    ultimoElemento->setProx(primeiroElemento);
    return dado;
}

template <typename T>
T ListaCircular<T>::removeDoInicio(){
    if(listaVazia()) throw new EstruturaVazia;
    numElementos--;
    ElementoLista<T>* elemento = primeiroElemento;
    primeiroElemento = primeiroElemento->getProx();
    ultimoElemento->setProx(primeiroElemento);
    T dado = elemento->getDado();
    delete elemento;
    return dado;
}

template <typename T>
T ListaCircular<T>::removeEspecifico(T dado){
    if(listaVazia()) throw new EstruturaVazia;
    ElementoLista<T>* aux = primeiroElemento;
    int cont = 0;
    while(aux->getProx()->getDado() != dado){
        if(cont >= numElementos) throw new DadoNaoEncontradoException;
        aux = aux->getProx();
    }
    numElementos--;
    ElementoLista<T>* aux2 = aux->getProx();
    ElementoLista<T>* elemento = aux->getProx();
    aux->setProx(aux2->getProx());
    T _dado = elemento->getDado();
    delete elemento;
    return _dado;
}

template <typename T>
T ListaCircular<T>::getDado(int posicao){
    if(listaVazia()) throw new EstruturaVazia;
    if(posicao > numElementos) throw new PosicaoInvalida;
    if(posicao == 0){
        return primeiroElemento->getDado();
    }else{
        ElementoLista<T>* elemento = primeiroElemento;
        for(int i = 1; i < posicao; i++){
            elemento = elemento->getProx();
        }
        return elemento->getProx()->getDado();
    }
}

template <typename T>
bool ListaCircular<T>::contem(T dado){
    if(listaVazia()) throw new EstruturaVazia;
    ElementoLista<T>* aux = primeiroElemento;
    for(int i = 1; i < posicao-1; i++){
        if(aux.getDado() == dado) return true;
        aux = aux->getProx();
    }
    return false;
}

template <typename T>
ElementoLista<T>* ListaCircular<T>::get(int posicao){
    if(listaVazia()) throw new EstruturaVazia;
    if(posicao > numElementos) throw new PosicaoInvalida;
    if(posicao == 0){
        return primeiroElemento;
    }else{
        ElementoLista<T>* elemento = primeiroElemento;
        for(int i = 1; i < posicao; i++){
            elemento = elemento->getProx();
        }
        return elemento->getProx();
    }
}

template <typename T> 
bool ListaCircular<T>::listaVazia(){
    return numElementos == 0;
}

template <typename T>
int ListaCircular<T>::size(){
    return numElementos;
}