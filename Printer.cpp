#include "Printer.h"
#include <iostream>

using namespace std;

Printer::Printer(Supermercado* _super){
	super = _super;
}

void Printer::print(){
	cout << "Simulação de Supermercado" << endl;
	cout << "Parâmetros de simulação:" << endl;
	cout << "\tNumero de caixas: " << super->getCaixas()->getSize() << endl;
	cout << "\tTempo de simulação: " << super->getTempoDeOperacao()/360 << endl;
	cout << "\tTempo de chegada de clientes: " << super->getChegadaDeClientes() << "\n" << endl;
	cout << "*** Supermercado " << super->getNome() << " ***" << endl;

	super->getCaixas()->resetaIterador();
	for(int i = 0; i < super->getCaixas()->getSize(); i++){
		Caixa* caixa = super->getCaixas()->get();
		cout << "Caixa " << caixa->getId() << ": " << endl;
		cout << "\tSalario: " << caixa->getSalario() << endl;
		cout << "\tDesempenho: " << caixa->getDesempenho() << endl;
		cout << "\tClientes atendidos: " << caixa->getClientesAtendidos() << endl;
		cout << "\tLucro do dia: " << caixa->getFaturamentoTotal() << endl;
		cout << "" << endl;
	}

	cout << "\nResumo:" << endl;
	cout << "Clientes recebidos: " << super->getClientesRecebidos() << endl;
	cout << "Desistencias: " << super->getDesistencias() << endl;
	cout << "Prejuizo relacionado a desistencias: " << super->getFaturamentoPerdido() << endl;
	cout << "Lucro total: " << super->getLucroTotal() << endl;
}