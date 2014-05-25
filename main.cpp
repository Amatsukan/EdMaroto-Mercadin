#include "Supermercado.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
	// srand(time(NULL));
	Supermercado* super = new Supermercado(8);//ler arquivo

	while(super->temClientes() || super->aberto()){
		if(super->aberto()){
			Cliente* cliente = new Cliente(super->getRelogio());
			try{
				super->colocaNaFila(cliente);
			}catch(int ex){
				super->recolheCarrinho(cliente);
			}
		}

		Lista<Caixa*>* caixas = super->getCaixas();
		caixas->resetaIterador();
		for(int i = 0; i < caixas->getSize(); i++){
			Caixa* caixa = caixas->get();
			if(caixa->getClientesNaFila() > 0){
				caixa->atendeCliente(super->getRelogio());
			}
		}
		caixas->resetaIterador();
		printf("Numero de clientes: %d\n", caixas->get()->getClientesNaFila());
		super->incrementaRelogio();
	}
	printf("Lucro: %d\n", super->computaLucro());
	return 0;
}