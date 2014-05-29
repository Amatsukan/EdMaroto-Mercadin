#include "Tempo.h"

Tempo::Tempo(){
	segundos = 0;
	minutos = 0;
	horas = 0;
}

Tempo::Tempo(int h, int m, int s){
	segundos = s;
	minutos = m;
	horas = h;
}

void Tempo::tick(){
	addS(1);
	// segundos++;
	// if(segundos > 60){
	// 	minutos++;
	// 	segundos = segundos % 60;
	// }
	// if(minutos > 60){
	// 	horas++;
	// 	minutos = minutos % 60;
	// }
}

void Tempo::add(Tempo* tempo){
	addH(tempo->getHoras());
	addM(tempo->getMinutos());
	addS(tempo->getSegundos());
}

void Tempo::sub(Tempo* tempo){
	subH(tempo->getHoras());
	subM(tempo->getMinutos());
	subS(tempo->getSegundos());
}

void Tempo::addH(int H){
	horas += H;
	if(horas >= 24){
		horas = horas%24;
	}
}
void Tempo::addM(int M){
	minutos += M;
	if(minutos >= 60){
		minutos = minutos%60;
		addH(1);
	}
}
void Tempo::addS(int S){
	segundos += S;
	if(segundos >= 60){
		segundos = segundos%60;
		addM(1);
	}
}

void Tempo::subH(int H){
	if(horas > 0){
		horas -= H;
	}
}

void Tempo::subM(int M){
	minutos -= M;
	if(minutos < 0){
		// minutos = minutos%60;
		minutos = 60+minutos;
		subH(1);
	}
}

void Tempo::subS(int S){
	segundos -= S;
	if(segundos < 0){
		// segundos = segundos%60;
		segundos = 60+segundos;
		subM(1);
	}
}

int Tempo::getSegundos(){
	return segundos;
}

int Tempo::getMinutos(){
	return minutos;
}

int Tempo::getHoras(){
	return horas;
}

int Tempo::toInt(){
	return segundos + 60*minutos + 60*60*horas;
}