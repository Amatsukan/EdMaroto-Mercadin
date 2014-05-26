#include "Supermercado.h"

Supermercado::Supermercado(int _horasDeOperacao){
	caixas = new Lista<Caixa*>();
	adicionaCaixas();

	horasDeOperacao = _horasDeOperacao*60*60;
	desistencias = 0;
	prejuizo = 0;
	dinheirosCaixas = 0;
	lucroTotal = 0;
	relogio = 0;

	tempoMedioClientes = 7;
}

bool Supermercado::temClientes(){
	if(caixas->getSize() == 0){
		return false;
	}
	caixas->resetaIterador();
	for(int i = 0; i < caixas->getSize(); i++){
		if(caixas->get()->getClientesNaFila() > 0) return true;
	}
	return false;
}

bool Supermercado::aberto(){
	return relogio < horasDeOperacao;
}

int Supermercado::getRelogio(){
	return relogio;
}

void Supermercado::colocaNaFila(Cliente* cliente){
	Caixa* caixa = caixas->get();
	caixas->resetaIterador();
	if(cliente->getTipoCliente() == 0){
		for(int i = 1; i < caixas->getSize(); i++){
			Caixa* caixaAtual = caixas->get();
			if(caixaAtual->getClientesNaFila() < caixa->getClientesNaFila()){
				caixa = caixaAtual;
			}
		}
	}else{
		for(int i = 1; i < caixas->getSize(); i++){
			Caixa* caixaAtual = caixas->get();
			if(caixaAtual->getClientesNaFila() < caixa->getProdutosNaFila()){
				caixa = caixaAtual;
			}
		}
	}
	if(caixa->getClientesNaFila() >= 10) throw(-1);
	caixa->recebeNovoCliente(cliente);
}

void Supermercado::recolheCarrinho(Cliente* cliente){
	while(!cliente->getProdutos()->empty()){
		Produto* produto = cliente->getProdutos()->remove();
		prejuizo += produto->getPreco()*3;
		delete produto;
	}
	desistencias++;
	delete cliente;
}

Lista<Caixa*>* Supermercado::getCaixas(){
	return caixas;
}

void Supermercado::incrementaRelogio(){
	relogio++;
}

void Supermercado::adicionaCaixas(){
	caixas->add(new Caixa("Maria_Benta", 800, 1));
	caixas->add(new Caixa("Juliana_Digito", 800, 1));
	caixas->add(new Caixa("Zeca_Mole", 180, 3));
	caixas->add(new Caixa("Joao_DeMora", 180, 3));
}

int Supermercado::computaLucro(){
	int salarios = 0;
	dinheirosCaixas = 0;
	caixas->resetaIterador();
	for(int i = 0; i < caixas->getSize(); i++){
		Caixa* caixa = caixas->get();
		salarios += caixa->getSalario();
		dinheirosCaixas += caixa->getFaturamentoTotal();
	}
	return dinheirosCaixas - prejuizo - salarios;
}

int Supermercado::getDesistencias(){
	return desistencias;
}

int Supermercado::getTempoMedioClientes(){
	return tempoMedioClientes;
}

int Supermercado::getDinheirosCaixas(){
	if(dinheirosCaixas == 0){
		caixas->resetaIterador();
		for(int i = 0; i < caixas->getSize(); i++){
			dinheirosCaixas += caixas->get()->getFaturamentoTotal();
		}
	}
	return dinheirosCaixas;
}