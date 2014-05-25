#include "Produto.h"
#include <stdlib.h>

Produto::Produto(){
	preco = ((rand() % 9000+100)/(double)100);
}

double Produto::getPreco(){
	return preco;
}