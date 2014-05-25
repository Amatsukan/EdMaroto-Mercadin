#include <stdio.h>
#include "ListaCircular.hpp"

int main(){
	ListaCircular<int> lista;

	lista.add(1);
	lista.add(2);
	lista.add(3);
	lista.addNoInicio(4);
	lista.addNaPosicao(30, 2);

	int size = lista.size();
	for(int i = 0; i < size; i++){
		printf("%d\n", lista.getDado(i));
	}

	printf("\n");

	lista.removeEspecifico(2);

	size = lista.size();
	for(int i = 0; i < size; i++){
		printf("%d\n", lista.getDado(i));
	}

// METODO PARA ITERACAO NOS CAIXAS:
	// Elemento<int>* elemento = lista.get(0);
	// while(true){
	// 	printf("%d\n", elemento->getDado());
	// 	elemento = elemento->getProx();
	// }


	return 0;
}