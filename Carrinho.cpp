#include "Carrinho.h"
#include <stdlib.h>

Carrinho::Carrinho(){
	produtos = new Pilha<Produto*>();
	int qtd = (rand() % 100) + 2;
	for(int i = 0; i < qtd; i++){
		Produto* produto = new Produto();
		valorTotalDeCompras += produto->getValor();
		produtos->add(produto);
	}
}

Carrinho::~Carrinho(){
	delete produtos;
}

Pilha<Produto*>* Carrinho::getProdutos(){
	return produtos;
}

int Carrinho::getQtdProdutos(){
	return produtos->getSize();
}

double Carrinho::getValorTotalDeCompras(){
	return valorTotalDeCompras;
}