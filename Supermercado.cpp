#include "Supermercado.h"
#include "ClienteMenorFila.h"
#include "ClienteMenosProdutos.h"
#include <stdlib.h>

Supermercado::Supermercado(){
	// relogio = new Tempo();
	relogio = 0;
	// relogioInt = 0;
	desistencias = 0;
	faturamentoPerdido = 0;
	leConfig();
}

void Supermercado::recolheCarrinho(Cliente* cliente){
	faturamentoPerdido += cliente->getValorTotalDeCompras()*3;
	desistencias++;
	delete cliente;
}

void Supermercado::incrementaRelogio(){
	// relogio->tick();
	// relogioInt++;
	relogio++;
}

void Supermercado::leConfig(){
	caixas = new Lista<Caixa*>();
	// tempoDeOperacao = new Tempo(5,0,0);
	tempoDeOperacao = 5*60*60;
	// chegadaDeClientes = new Tempo(0,0,7);
	chegadaDeClientes = 7;
	caixas->add(new Caixa("Caixa1", 1, 800, 10));
	caixas->add(new Caixa("Caixa2", 3, 400, 10));
	nome = "Mercadin";
}

Lista<Caixa*>* Supermercado::getCaixas(){
	return caixas;
}

int Supermercado::getRelogio(){
	return relogio;
}

// int Supermercado::getRelogioInt(){
// 	return relogioInt;
// }

int Supermercado::getDesistencias(){
	return desistencias;
}

double Supermercado::getFaturamentoPerdido(){
	return faturamentoPerdido;
}

int Supermercado::getChegadaDeClientes(){
	return chegadaDeClientes;
}

int Supermercado::getTempoDeOperacao(){
	return tempoDeOperacao;
}

std::string Supermercado::getNome(){
	return nome;
}

bool Supermercado::aberto(){
	// return relogio->toInt() < tempoDeOperacao->toInt();
	return relogio < tempoDeOperacao;
}

int Supermercado::getClientesRecebidos(){
	return clientesRecebidos;
}

int Supermercado::getLucroTotal(){
	return lucroTotal;
}

void Supermercado::calculaLucro(){
	caixas->resetaIterador();
	lucroTotal = 0;
	for(int i = 0; i < caixas->getSize(); i++){
		Caixa* caixa = caixas->get();
		lucroTotal += caixa->getFaturamentoTotal();
	}
}

void Supermercado::setRelogio(int _relogio){
	relogio = _relogio;
}

Cliente* Supermercado::recebeCliente(){
	Cliente* cliente;
	clientesRecebidos++;
	if((rand()%100) < 50){
		cliente = new ClienteMenorFila(relogio);
	}
	else{ 
		cliente = new ClienteMenosProdutos(relogio);
	}
	return cliente;
}