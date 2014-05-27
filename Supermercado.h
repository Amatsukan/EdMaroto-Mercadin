#ifndef SUPERMERCADO_H
#define SUPERMERCADO_H

class Supermercado{
public:
	Supermercado();
	void recolheCarrinho();
	void incrementaRelogio();
private:
	Lista<Caixa*>* caixas;
	Tempo* relogio;
	Tempo* chegadaDeClientes;
	Tempo* tempoDeOperacao;
	double faturamentoPerdido;
};

#endif