#include "FilaDeCaixa.h"
#include "Cliente.h"

FilaDeCaixa::FilaDeCaixa(int max){
	fila = new Fila<Cliente*>();
	// tempoDeEspera = new Tempo();
	tempoDeEspera = 0;
	maxClientes = max;
	numeroDeClientes = 0;
	numeroDeProdutos = 0;
}

void FilaDeCaixa::add(Cliente* cliente){
	fila->add(cliente);
	numeroDeProdutos += cliente->getCarrinho()->getQtdProdutos();
	numeroDeClientes++;
	if(cliente->pagaComCheque()) nClientesCaloteros++;
}

Cliente* FilaDeCaixa::remove(){
	Cliente* cliente = fila->remove();
	numeroDeProdutos -= cliente->getCarrinho()->getQtdProdutos();
	if(cliente->pagaComCheque()) nClientesCaloteros--;
	numeroDeClientes--;
	// tempoDeEspera -= cliente->getTempoIndividual();
	// tempoDeEspera->sub(cliente->getTempoIndividual());
	return cliente;
}

int FilaDeCaixa::incrementaTempoDeEspera(int tempo){
	// tempoDeEspera->add(tempo);
	tempoDeEspera += tempo;
	return tempoDeEspera;
}

Fila<Cliente*>* FilaDeCaixa::getFila(){
	return fila;
}

void FilaDeCaixa::setTempoDeEspera(int tempo){
	tempoDeEspera = tempo;
}

int FilaDeCaixa::getNClientesCaloteros(){
	return nClientesCaloteros;
}

int FilaDeCaixa::getMaxClientes(){
	return maxClientes;
}

int FilaDeCaixa::getNumeroDeProdutos(){
	return numeroDeProdutos;
}

int FilaDeCaixa::getNumeroDeClientes(){
	return numeroDeClientes;
}

int FilaDeCaixa::getTempoDeEspera(){
	return tempoDeEspera;
}

Cliente* FilaDeCaixa::getPrimeiroCliente(){
	return fila->getInicio();
}