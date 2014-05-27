#include "Carrinho.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
	srand(time(0));

	Carrinho* c = new Carrinho();
	for(int i = 0; i < c->getQtdProdutos(); i++){
		cout << c->getProdutos()->remove()->getValor() << endl;
	}
	cout << c->getQtdProdutos() << endl;
	
	return 0;
}