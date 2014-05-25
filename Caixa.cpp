#include "Caixa.h"
#include <string>
#include <stdio.h>

Caixa::Caixa(std::string _id, double _salario, int _desempenho){
	id = _id;
	salario = _salario;
	desempenho = _desempenho;
	fila = new Fila<Cliente*>();
	clientesAtendidos = 0;
	faturamentoMedio = 0;
	faturamentoTotal = 0;
	if(desempenho == 1){
		tempoItem = 1;
		tempoCheque = 10;
	}else if(desempenho == 2){
		tempoItem = 2;
		tempoCheque = 25;
	}else{
		tempoItem = 4;
		tempoCheque = 60;
	}
}

void Caixa::recebeNovoCliente(Cliente* cliente){
	produtosNaFila += cliente->getProdutos()->getSize();
	if(cliente->pagarComCheque()){
		tempoDaFila += tempoCheque;
	}
	tempoDaFila += produtosNaFila*tempoItem;
	cliente->setTempoDeEspera(tempoDaFila);
	fila->add(cliente);
}

void Caixa::atendeCliente(int relogio){
	if(relogio >= fila->getInicio()->getTempoDeEspera()){
		clienteAtual = fila->remove();
		Cliente* cliente = clienteAtual;
		double valorTotal = 0;
		int numProdutos = cliente->getProdutos()->getSize();
		while(cliente->getProdutos()->getSize() > 0){
			valorTotal += cliente->getProdutos()->remove()->getPreco();
		}
		if(cliente->pagarComCheque()){
			tempoDaFila -= tempoCheque;
		}
		produtosNaFila -= numProdutos;
		tempoDaFila -= numProdutos*tempoItem;

		faturamentoTotal+=valorTotal;
		clientesAtendidos++;
	}
}

std::string Caixa::getId(){
	return id;
}

double Caixa::getSalario(){
	return salario;
}

int Caixa::getDesempenho (){
	return desempenho;
}

Fila<Cliente*>* Caixa::getFila(){
	return fila;
}

int Caixa::getClientesNaFila(){
	return fila->getSize();
}

int Caixa::getProdutosNaFila(){
	return produtosNaFila;
}

int Caixa::getClientesAtendidos(){
	return clientesAtendidos;
}

double Caixa::getFaturamentoTotal(){
	return faturamentoTotal;
}