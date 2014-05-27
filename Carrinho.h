#ifndef CARRINHO_H
#define CARRINHO_H

#include "Produto.h"
#include "Pilha.hpp"

class Carrinho{
public:
	Carrinho();
	~Carrinho();
	Pilha<Produto*>* getProdutos();
	int getQtdProdutos();
	double getValorTotalDeCompras();
private:
	Pilha<Produto*>* produtos;
	double valorTotalDeCompras;
	int qtdProdutos;
};

#endif