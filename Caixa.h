#ifndef CAIXA_H
#define CAIXA_H

#include <string>
#include "Cliente.h"

class FilaDeCaixa;
class Caixa{
public:
	Caixa(std::string _id, int _desempenho, double _salario, int maxFila);
	Cliente* atendeCliente();
	int getQtdClientesNaFila();
	std::string getId();
	int getDesempenho();
	double getSalario();
	FilaDeCaixa* getFila();
	int getClientesAtendidos();
	int getMediaEspera();
	double getFaturamentoTotal();
	double getFaturamentoMedio();
	int calculaTempoParaCliente(Cliente* cliente);
	int getTempoParaCheque();
	int getTempoParaItens();

	int clientesNaFila;
private:
	std::string id;
	int desempenho;
	double salario;
	int tempoParaCheque;
	int tempoParaItens;
	FilaDeCaixa* fila;
	int clientesAtendidos;
	int mediaEspera;
	double faturamentoTotal;
	double faturamentoMedio;
};

#endif