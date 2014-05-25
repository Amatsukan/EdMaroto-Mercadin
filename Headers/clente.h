#pragma once
#include "carteira.h"
#include "Carrinho.h"
#include "produto.h"
class Cliente
{
private:
	Carrinho* carrinho;
	carteira* carteira;
	bool pagaComCheque;
	double valordacompra;
public:
	Cliente();
	~Cliente();
};

