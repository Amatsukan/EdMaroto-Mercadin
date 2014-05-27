#ifndef FILADECAIXA_H
#define FILADECAIXA_H

#include "Fila.hpp"
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
	Fila<Cliente*>* getFila();
private:
	Fila<Cliente*>* fila;
	int maxClientes;
	int numeroDeProdutos;
	int numeroDeClientes;
};

#endif