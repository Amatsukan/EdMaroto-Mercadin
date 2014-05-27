#include "Cliente.h"
#include "Caixa.h"
#include <stdlib.h>

Cliente::Cliente(Tempo* entrada){
	carrinho = new Carrinho();
	cheque = (rand()%100) < 20;
	horarioDeChegada = entrada;
}

Cliente::~Cliente(){
	delete carrinho;
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

Tempo* Cliente::getHorarioDeChegada(){
	return horarioDeChegada;
}

Tempo* Cliente::getPrevisaoDeSaida(){
	return previsaoDeSaida;
}




// void ClienteMenorFila::escolheCaixa(Lista<Caixa*>* caixas){
// 	caixas->resetaIterador();
// 	Caixa* caixaIdeal = caixas->get();
// 	for(int i = 0; i < caixas->getSize(); i++){
// 		Caixa* caixa = caixas->get();
// 		if(caixa->getQtdClientesNaFila() < caixaIdeal->getQtdClientesNaFila()){
// 			caixaIdeal = caixa;
// 		}
// 	}
// 	caixaIdeal->getFila()->add(this);
// }


// void ClienteMenosProdutos::escolheCaixa(Lista<Caixa*>* caixas){
// 	caixas->resetaIterador();
// 	Caixa* caixaIdeal = caixas->get();
// 	for(int i = 0; i < caixas->getSize(); i++){
// 		Caixa* caixa = caixas->get();
// 		if(caixa->getFila()->getNumeroDeProdutos() < caixaIdeal->getFila()->getNumeroDeProdutos()){
// 			caixaIdeal = caixa;
// 		}
// 	}
// 	caixaIdeal->getFila()->add(this);
// }