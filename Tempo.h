#ifndef TEMPO_H
#define TEMPO_H

#include <string>

class Tempo{
public:
	Tempo();
	Tempo(int h, int m, int s);
	void tick();
	void add(Tempo* tempo);
	void sub(Tempo* tempo);
	void addS(int S);
	void addM(int M);
	void addH(int H);
	void subS(int S);
	void subM(int M);
	void subH(int H);
	int getSegundos();
	int getMinutos();
	int getHoras();
	int toInt();
private:
	int segundos;
	int minutos;
	int horas;
};

#endif