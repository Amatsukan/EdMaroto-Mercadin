#include "Caixa.h"
#include "Cliente.h"
#include "FilaDeCaixa.h"

Caixa::Caixa(std::string _id, int _desempenho, double _salario, int maxFila){
	id = _id;
	desempenho = _desempenho;
	salario = _salario;
	switch(desempenho){
		case 1:
			tempoParaCheque = 10;
			tempoParaItens = 1;
			break;
		case 2:
			tempoParaCheque = 25;
			tempoParaItens = 2;
			break;
		default:
			tempoParaCheque = 60;
			tempoParaItens = 4;
			break;
	}
	fila = new FilaDeCaixa(maxFila);
	clientesAtendidos = 0;
	mediaEspera = 0;
	faturamentoTotal = 0;
	faturamentoMedio = 0;
}

Cliente* Caixa::atendeCliente(){
	Cliente* cliente = fila->remove();
	faturamentoTotal += cliente->getValorTotalDeCompras();
	clientesAtendidos++;
	clientesNaFila--;
	fila->setTempoDeEspera(fila->getTempoDeEspera() - (cliente->getQtdProdutos()*tempoParaItens + tempoParaCheque));
	return cliente;
}

int Caixa::calculaTempoParaCliente(Cliente* cliente){
	int tempo = cliente->getQtdProdutos()*tempoParaItens;
	if(cliente->pagaComCheque()){
		tempo += tempoParaCheque;
	}
	return tempo;
}

int Caixa::getQtdClientesNaFila(){
	return fila->getFila()->getSize();
}

std::string Caixa::getId(){
	return id;
}

int Caixa::getDesempenho(){
	return desempenho;
}

double Caixa::getSalario(){
	return salario;
}

FilaDeCaixa* Caixa::getFila(){
	return fila;
}

int Caixa::getClientesAtendidos(){
	return clientesAtendidos;
}

int Caixa::getMediaEspera(){
	return mediaEspera;
}

double Caixa::getFaturamentoTotal(){
	return faturamentoTotal;
}

double Caixa::getFaturamentoMedio(){
	return faturamentoMedio;
}

int Caixa::getTempoParaCheque(){
	return tempoParaCheque;
}

int Caixa::getTempoParaItens(){
	return tempoParaItens;
}