#include "Cliente.h"
#include <stdlib.h>

Cliente::Cliente(int _horarioEntrada){
	horarioEntrada = _horarioEntrada;
	produtos = new Pilha<Produto*>();
	pegaProdutos();
	cheque = (rand()%100 < 20);
	qtdCompras = 0;
}

void Cliente::addProduto(Produto* produto){
	produtos->add(produto);
}

void Cliente::setTempoDeEspera(int tempo){
	tempoDeEspera = tempo + horarioEntrada;
}

int Cliente::getTipoCliente(){
	return tipoCliente;
}

int Cliente::getTempoDeEspera(){
	return tempoDeEspera;
}

int Cliente::getHorarioEntrada(){
	return horarioEntrada;
}

Pilha<Produto*>* Cliente::getProdutos(){
	return produtos;
}

bool Cliente::pagarComCheque(){
	return cheque;
}

int Cliente::getQtdCompras(){
	return qtdCompras;
}

void Cliente::pegaProdutos(){
	int numProdutos = rand()%100+2;
	for(int i = 0; i < numProdutos; i++){
		produtos->add(new Produto());
	}
}