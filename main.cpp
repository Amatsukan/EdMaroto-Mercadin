#include "Supermercado.h"
#include "Printer.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(){
	srand(time(NULL));

	Supermercado* super = new Supermercado();
	Printer* printer = new Printer(super);

	while(super->temClientes() || super->aberto()){
		if(super->aberto() && super->getRelogio()%super->getTempoMedioClientes() == 0){
			Cliente* cliente = new Cliente(super->getRelogio());
			try{
				// cliente->procuraFila(super);
				super->colocaNaFila(cliente);
			}catch(int ex){
				super->recolheCarrinho(cliente);
			}
		}

		Lista<Caixa*>* caixas = super->getCaixas();
		caixas->resetaIterador();
		for(int i = 0; i < caixas->getSize(); i++){
		// for(int i = 0; i < super->getCaixas()->getSize(); i++){
			Caixa* caixa = caixas->get();
			if(caixa->getClientesNaFila() > 0){
				caixa->atendeCliente(super->getRelogio());
			}
		}
		caixas->resetaIterador();
		super->incrementaRelogio();
	}
	// cout << difftime(time(0), start) << endl;
	printer->print();

	// prints

	// double lucroTotal = super->computaLucro();
	// double faturamentoTotal = super->getDinheirosCaixas();
	// double faturamentoPorCaixa = faturamentoTotal/super->getCaixas()->getSize();


	// printf("Faturamento total: %f\n", faturamentoTotal);
	// printf("Faturamento médio por caixa: %f\n", faturamentoPorCaixa);
	// printf("\n");

	// super->getCaixas()->resetaIterador();
	// for(int i = 0; i < super->getCaixas()->getSize(); i++){
	// 	Caixa* caixa = super->getCaixas()->get();
	// 	cout << "|| " << caixa->getId() << " ||" << endl;
	// 	cout << "Faturamento total: " << caixa->getFaturamentoTotal() << endl;
	// 	cout << "Lucro: " << caixa->getFaturamentoTotal()-caixa->getSalario() << endl;
	// 	cout << "Tempo media de permanencia por cliente: " << super->getRelogio()/caixa->getClientesAtendidos() << endl;
	// 	printf("\n");
	// }

	return 0;
}