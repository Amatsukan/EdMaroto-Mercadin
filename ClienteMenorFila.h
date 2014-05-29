#ifndef CLIENTEMENORFILA_H
#define CLIENTEMENORFILA_H

#include "Cliente.h"
// #include "Tempo.h"
// class Cliente;
class ClienteMenorFila : public Cliente{
public:
	// ClienteMenorFila(Tempo* tempo);
	ClienteMenorFila(int tempo);
	void escolheCaixa(Lista<Caixa*>* caixas);
};

#endif