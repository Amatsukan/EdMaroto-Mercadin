#ifndef CAIXA_H
#define CAIXA_H

#include <string>
#include "Fila.hpp"
#include "Cliente.h"

class Caixa{
public:
	Caixa(std::string _id, double _salario, int _desempenho);
	void recebeNovoCliente(Cliente* cliente);
	void atendeCliente(int relogio);
	std::string getId();
	double getSalario();
	int getDesempenho();
	Fila<Cliente*>* getFila();
	int getClientesNaFila();
	int getProdutosNaFila();
	int getClientesAtendidos();
	int getEsperaTotal();
	double getFaturamentoTotal();
private:
	std::string id;
	double salario;
	int desempenho;
	int tempoCheque;
	int tempoItem;
	Fila<Cliente*>* fila;
	Cliente* clienteAtual;
	int produtosNaFila;
	int tempoDaFila;
	int esperaTotal;
	int tempoAtual;
	int clientesAtendidos;
	double faturamentoTotal;
	double faturamentoMedio;
};

#endif