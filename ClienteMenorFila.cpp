#include "ClienteMenorFila.h"
#include "Lista.hpp"
#include "Caixa.h"
#include "FilaDeCaixa.h"
// #include "Cliente.h"

void ClienteMenorFila::escolheCaixa(Lista<Caixa*>* caixas){
	caixas->resetaIterador();
	Caixa* caixaIdeal = caixas->get();
	for(int i = 0; i < caixas->getSize(); i++){
		Caixa* caixa = caixas->get();
		if(caixa->getQtdClientesNaFila() < caixaIdeal->getQtdClientesNaFila()){
			caixaIdeal = caixa;
		}
	}
	caixaIdeal->getFila()->add(this);
}