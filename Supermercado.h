#ifndef SUPERMERCADO_H
#define SUPERMERCADO_H

#include "Cliente.h"
#include "Caixa.h"
#include "Lista.hpp"

class Supermercado{
public:
	Supermercado(int horasDeOperacao);
	bool temClientes();
	bool aberto();
	int getRelogio();
	void incrementaRelogio();
	void colocaNaFila(Cliente* cliente);
	void recolheCarrinho(Cliente* cliente);//desistencias++
	Lista<Caixa*>* getCaixas();
	void adicionaCaixas();
	int computaLucro();
	int getDesistencias();
private:
	Lista<Caixa*>* caixas;
	int desistencias;
	int prejuizo;
	int dinheirosCaixas;
	int lucroTotal;
	int relogio;
	int horasDeOperacao;
};

#endif