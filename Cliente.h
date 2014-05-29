#ifndef CLIENTE_H
#define CLIENTE_H

#include "Carrinho.h"
#include "Lista.hpp"

class Caixa;
class Cliente{
public:
	Cliente(int tempo);
	~Cliente();
	virtual void escolheCaixa(Lista<Caixa*>* caixas);
	int getQtdProdutos();
	double getValorTotalDeCompras();
	Carrinho* getCarrinho();
	bool pagaComCheque();
	int getHorarioDeChegada();
	int getPrevisaoDeSaida();
	int getTempoIndividual();
	void setPrevisaoDeSaida(int tempo);
	int getId();
private:
	Carrinho* carrinho;
	bool cheque;
	int horarioDeChegada;
	int previsaoDeSaida;
protected:
	int tempoIndividual;
};

#endif