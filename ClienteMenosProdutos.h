#ifndef CLIENTEMENOSPRODUTOS_H
#define CLIENTEMENOSPRODUTOS_H

#include "Cliente.h"
// class Cliente;
class ClienteMenosProdutos : public Cliente{
public:
	void escolheCaixa(Lista<Caixa*>* caixas);
};

#endif