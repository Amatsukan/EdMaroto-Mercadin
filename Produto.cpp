#include "Produto.h"
#include <stdlib.h>

Produto::Produto(){
	valor = ((rand() % 9000+100)/(double)100);
}

double Produto::getValor(){
	return valor;
}