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
			break;
		case 2:
			tempoParaCheque = 25;
			break;
		default:
			tempoParaCheque = 60;
			break;
	}
	fila = new FilaDeCaixa(maxFila);
	clientesAtendidos = 0;
	mediaEspera = new Tempo();
	faturamentoTotal = 0;
	faturamentoMedio = 0;
}

void Caixa::atendeCliente(){
	Cliente* cliente = fila->remove();
	faturamentoTotal += cliente->getValorTotalDeCompras();
	clientesAtendidos++;
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

Tempo* Caixa::getMediaEspera(){
	return mediaEspera;
}

double Caixa::getFaturamentoTotal(){
	return faturamentoTotal;
}

double Caixa::getFaturamentoMedio(){
	return faturamentoMedio;
}