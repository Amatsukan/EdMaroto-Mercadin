#ifndef CLIENTEMENOSPRODUTOS_H
#define CLIENTEMENOSPRODUTOS_H

#include "Cliente.h"
#include "Tempo.h"
// class Cliente;
class ClienteMenosProdutos : public Cliente{
public:
	// ClienteMenosProdutos(Tempo* tempo);
	ClienteMenosProdutos(int tempo);
	void escolheCaixa(Lista<Caixa*>* caixas);
};

#endif