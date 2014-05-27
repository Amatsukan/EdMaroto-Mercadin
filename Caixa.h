#ifndef CAIXA_H
#define CAIXA_H

#include <string>
#include "Tempo.h"

class FilaDeCaixa;
class Caixa{
public:
	Caixa(std::string _id, int _desempenho, double _salario, int maxFila);
	void atendeCliente();
	int getQtdClientesNaFila();
	std::string getId();
	int getDesempenho();
	double getSalario();
	FilaDeCaixa* getFila();
	int getClientesAtendidos();
	Tempo* getMediaEspera();
	double getFaturamentoTotal();
	double getFaturamentoMedio();
private:
	std::string id;
	int desempenho;
	double salario;
	int tempoParaCheque;
	FilaDeCaixa* fila;
	int clientesAtendidos;
	Tempo* mediaEspera;
	double faturamentoTotal;
	double faturamentoMedio;
};

#endif