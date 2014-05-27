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
	segundos++;
	if(segundos > 60){
		minutos++;
		segundos = segundos % 60;
	}
	if(minutos > 60){
		horas++;
		minutos = minutos % 60;
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