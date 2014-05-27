#ifndef CLIENTEMENORFILA_H
#define CLIENTEMENORFILA_H

#include "Cliente.h"
// class Cliente;
class ClienteMenorFila : public Cliente{
public:
	void escolheCaixa(Lista<Caixa*>* caixas);
};

#endif