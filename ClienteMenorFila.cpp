#include "ClienteMenorFila.h"
#include "Lista.hpp"
#include "Caixa.h"
#include "FilaDeCaixa.h"
#include "FilasCheias.h"

ClienteMenorFila::ClienteMenorFila(int tempo) : Cliente(tempo){
}

void ClienteMenorFila::escolheCaixa(Lista<Caixa*>* caixas){
	caixas->resetaIterador();
	Caixa* caixaIdeal = caixas->get();
	for(int i = 1; i < caixas->getSize(); i++){
		Caixa* caixa = caixas->get();
		if(caixa->getQtdClientesNaFila() < caixaIdeal->getQtdClientesNaFila()){
			caixaIdeal = caixa;
		}
	}
	if(caixaIdeal->clientesNaFila >= 10) throw new FilasCheias;
	
	int previsao = 0;
	previsao += caixaIdeal->getTempoParaCheque();
	previsao += caixaIdeal->getTempoParaItens() * getQtdProdutos();
	int tempoDeFila = caixaIdeal->getFila()->incrementaTempoDeEspera(previsao);	
	setPrevisaoDeSaida(getHorarioDeChegada() + tempoDeFila);

	caixaIdeal->getFila()->add(this);
	caixaIdeal->clientesNaFila++;
}