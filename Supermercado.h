#ifndef SUPERMERCADO_H
#define SUPERMERCADO_H

#include "Cliente.h"
#include "Caixa.h"
#include "Lista.hpp"

class Supermercado{
public:
	Supermercado();
	bool temClientes();
	bool aberto();
	int getRelogio();
	void incrementaRelogio();
	void colocaNaFila(Cliente* cliente);
	void recolheCarrinho(Cliente* cliente);
	Lista<Caixa*>* getCaixas();
	int computaLucro();
	int getDesistencias();
	int getTempoMedioClientes();
	int getDinheirosCaixas();
	void leConf();
	std::string getNome();
private:
	std::string nome;
	Lista<Caixa*>* caixas;
	int desistencias;
	int prejuizo;
	int dinheirosCaixas;
	int lucroTotal;
	int relogio;
	int horasDeOperacao;
	int tempoMedioClientes;
};

#endif