#ifndef FILADECAIXA_H
#define FILADECAIXA_H

#include "Fila.hpp"
// #include "Tempo.h"
// #include "Cliente.h"

class Cliente;
class FilaDeCaixa{
public:
	FilaDeCaixa(int max);
	void add(Cliente* cliente);
	Cliente* remove();
	int getMaxClientes();
	int getNumeroDeProdutos();
	int getNumeroDeClientes();
	int getNClientesCaloteros();
	Fila<Cliente*>* getFila();
	// Tempo* getTempoDeEspera();
	int getTempoDeEspera();
	void setTempoDeEspera(int tempo);
	// void incrementaTempoDeEspera(Tempo* tempo);
	int incrementaTempoDeEspera(int tempo);
	Cliente* getPrimeiroCliente();
private:
	Fila<Cliente*>* fila;
	// Tempo* tempoDeEspera;
	int tempoDeEspera;
	int maxClientes;
	int numeroDeProdutos;
	int numeroDeClientes;
	int nClientesCaloteros;
};

#endif