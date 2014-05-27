#ifndef CLIENTE_H
#define CLIENTE_H

#include "Carrinho.h"
#include "Lista.hpp"
// #include "Caixa.h"
#include "Tempo.h"

class Caixa;
class Cliente{
public:
	Cliente(Tempo* tempo);
	~Cliente();
	virtual void escolheCaixa(Lista<Caixa*>* caixas);
	int getQtdProdutos();
	double getValorTotalDeCompras();
	Carrinho* getCarrinho();
	bool pagaComCheque();
	Tempo* getHorarioDeChegada();
	Tempo* getPrevisaoDeSaida();
private:
	Carrinho* carrinho;
	bool cheque;
	Tempo* horarioDeChegada;
	Tempo* previsaoDeSaida;
};

// class ClienteMenorFila : public Cliente{
// };

// class ClienteMenosProdutos : public Cliente{
// };

#endif