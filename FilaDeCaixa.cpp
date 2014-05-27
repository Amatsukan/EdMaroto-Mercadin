#include "FilaDeCaixa.h"
#include "Cliente.h"

FilaDeCaixa::FilaDeCaixa(int max){
	fila = new Fila<Cliente*>();
	maxClientes = max;
	numeroDeClientes = 0;
	numeroDeProdutos = 0;
}

void FilaDeCaixa::add(Cliente* cliente){
	fila->add(cliente);
	numeroDeProdutos += cliente->getCarrinho()->getQtdProdutos();
	numeroDeClientes++;
}

Cliente* FilaDeCaixa::remove(){
	Cliente* cliente = fila->remove();
	numeroDeProdutos -= cliente->getCarrinho()->getQtdProdutos();
	numeroDeClientes--;
	return cliente;
}

Fila<Cliente*>* FilaDeCaixa::getFila(){
	return fila;
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