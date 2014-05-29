#include "Cliente.h"
#include "Caixa.h"
#include <stdlib.h>


int id = 0;

// Cliente::Cliente(Tempo* entrada){
Cliente::Cliente(int entrada){
	carrinho = new Carrinho();
	cheque = (rand()%100) < 20;
	horarioDeChegada = entrada;
	id+=1;
}

Cliente::~Cliente(){
	delete carrinho;
}

void Cliente::escolheCaixa(Lista<Caixa*>* caixas){

}

int Cliente::getQtdProdutos(){
	return carrinho->getQtdProdutos();
}

double Cliente::getValorTotalDeCompras(){
	return carrinho->getValorTotalDeCompras();
}

Carrinho* Cliente::getCarrinho(){
	return carrinho;
}

bool Cliente::pagaComCheque(){
	return cheque;
}

int Cliente::getHorarioDeChegada(){
	return horarioDeChegada;
}

int Cliente::getPrevisaoDeSaida(){
	return previsaoDeSaida;
}


int Cliente::getTempoIndividual(){
	return tempoIndividual;
}

void Cliente::setPrevisaoDeSaida(int tempo){
	previsaoDeSaida = tempo;
}

int Cliente::getId(){
	return id;
}