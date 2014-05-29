#ifndef SUPERMERCADO_H
#define SUPERMERCADO_H

#include <string>
#include "Lista.hpp"
#include "Caixa.h"
#include "Tempo.h"
#include "Cliente.h"

class Supermercado{
public:
	Supermercado();
	void recolheCarrinho(Cliente* cliente);
	void incrementaRelogio();
	Lista<Caixa*>* getCaixas();
	// Tempo* getRelogio();
	int getRelogio();
	int getDesistencias();
	double getFaturamentoPerdido();
	// Tempo* getChegadaDeClientes();
	// Tempo* getTempoDeOperacao();
	int getChegadaDeClientes();
	int getTempoDeOperacao();
	std::string getNome();
	bool aberto();
	Cliente* recebeCliente();
	void setRelogio(int _relogio);
	// int getRelogioInt();
	int getClientesRecebidos();
	int getLucroTotal();
	void calculaLucro();
private:
	void leConfig();
	int relogioInt;
	Lista<Caixa*>* caixas;
	// Tempo* relogio;
	int relogio;
	int desistencias;
	int clientesRecebidos;
	int lucroTotal;
	double faturamentoPerdido;
	int chegadaDeClientes;
	int tempoDeOperacao;
	// Tempo* chegadaDeClientes;
	// Tempo* tempoDeOperacao;
	std::string nome;
};

#endif