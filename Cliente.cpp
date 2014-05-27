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

// void Cliente::procuraFila(Lista<Caixa*>* caixas){
// 	caixas->resetaIterador();
// 	Caixa* caixa = caixas->get();
// 	if(getTipoCliente() == 0){
// 		for(int i = 1; i < caixas->getSize(); i++){
// 			Caixa* caixaAtual = caixas->get();
// 			if(caixaAtual->getClientesNaFila() < caixa->getClientesNaFila()){
// 				caixa = caixaAtual;
// 			}
// 		}
// 	}else{
// 		for(int i = 1; i < caixas->getSize(); i++){
// 			Caixa* caixaAtual = caixas->get();
// 			if(caixaAtual->getClientesNaFila() < caixa->getProdutosNaFila()){
// 				caixa = caixaAtual;
// 			}
// 		}
// 	}
// 	if(caixa->getClientesNaFila() >= 10) throw(-1);
// 	caixa->recebeNovoCliente(this);
// }