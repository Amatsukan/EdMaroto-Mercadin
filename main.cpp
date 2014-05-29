#include <stdlib.h>
#include "Supermercado.h"
#include "Printer.h"
#include "Caixa.h"
#include "Cliente.h"
#include "Lista.hpp"
#include "FilasCheias.h"
#include "FilaDeCaixa.h"

using namespace std;

int main(){
	srand(time(0));

	Supermercado* super = new Supermercado();
	Printer* printer = new Printer(super);

	int numClientes = 0;
	int relogio = 0;
	while(relogio < 5*60*60 || numClientes > 0){
		Lista<Caixa*>* caixas = super->getCaixas();
		if(super->aberto() && super->getRelogio() % super->getChegadaDeClientes() == 0){
			Cliente* cliente = super->recebeCliente();
			try{
				cliente->escolheCaixa(caixas);
				numClientes++;
			}catch(FilasCheias* ex){
				super->recolheCarrinho(cliente);
			}
		}
		if(numClientes > 0){
			caixas->resetaIterador();
			for(int i = 0; i < caixas->getSize(); i++){
				Caixa* caixa = caixas->get();
				if(caixa->getQtdClientesNaFila() > 0 && (super->getRelogio() >= caixa->getFila()->getPrimeiroCliente()->getPrevisaoDeSaida())){
					Cliente* cliente = caixa->atendeCliente();
					numClientes--;
				}
			}
		}
		relogio++;
		super->setRelogio(relogio);
	}
	super->calculaLucro();

	printer->print();

	return 0;
}