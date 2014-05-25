#include <stdio.h>
#include "Pilha.hpp"

int main(){
	Pilha<int> pilha;

	pilha.add(3);
	pilha.add(1);
	pilha.add(2);
	pilha.add(35);

	for(int i = 0; i < size; i++){
		printf("%d\n", pilha.remove());
	}

	return 0;
}