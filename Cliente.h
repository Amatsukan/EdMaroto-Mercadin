#ifndef CLIENTE_H
#define CLIENTE_H

#include "Pilha.hpp"
#include "Produto.h"

class Cliente{
public:
	Cliente(int _horarioEntrada);
	void addProduto(Produto* produto);
	int getHorarioEntrada();
	void setTempoDeEspera(int tempo);
	int getTempoDeEspera();
	Pilha<Produto*>* getProdutos();
	bool pagarComCheque();
	int getQtdCompras();
	int getTipoCliente();
	void pegaProdutos();
private:
	int horarioEntrada;
	int tempoDeEspera;
	Pilha<Produto*>* produtos;
	bool cheque;
	int qtdCompras;
	int tipoCliente;// 0 = fila com menos clientes, 1 = fila com menos produtos
};

#endif