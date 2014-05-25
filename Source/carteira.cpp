#include "carteira.h"


carteira::carteira(double dinheiros)
{
	this->dinheiros = dinheiros;
}


double carteira::getDinheiros(){
	return dinheiros;
}

carteira::~carteira()
{
}


double carteira::setDinheiros(double dinheiros)
{
	this->dinheiros = dinheiros;
	return dinheiros;
}
