#include "Printer.h"
#include <iostream>

using namespace std;

Printer::Printer(Supermercado* _super){
	super = _super;
}

void Printer::print(){
	
	
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
}