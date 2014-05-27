#include "Printer.h"
#include <iostream>

using namespace std;

Printer::Printer(Supermercado* _super){
	super = _super;
}

void Printer::print(){
	super->getCaixas()->resetaIterador();
	for(int i = 0; i < super->getCaixas()->getSize(); i++){
		cout << super->getCaixas()->get()->getId() << endl;
	}

	cout << "Faturamento total: " << super->computaLucro() << endl;
	cout << "Faturamento médio por caixa: " << super->getDinheirosCaixas()/super->getCaixas()->getSize() << endl;

	super->getCaixas()->resetaIterador();
	for(int i = 0; i < super->getCaixas()->getSize(); i++){
		Caixa* caixa = super->getCaixas()->get();
		cout << "|| " << caixa->getId() << " ||" << endl;
		cout << "Faturamento total: " << caixa->getFaturamentoTotal() << endl;
		cout << "Lucro: " << caixa->getFaturamentoTotal()-caixa->getSalario() << endl;
		int n = 0;
		if(caixa->getClientesAtendidos() != 0){
			n = caixa->getEsperaTotal()/caixa->getClientesAtendidos();
		}
		cout << "Tempo media de permanencia por cliente: " << n << endl;
		cout << "" << endl;
	}

	cout << "Clientes perdidos: " << super->getDesistencias() << endl;
	cout << "Faturamento perdido: " << super->getPrejuizo() << endl;
	cout << "Nome do supermercado: " << super->getNome() << endl;
	
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