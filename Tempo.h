#ifndef TEMPO_H
#define TEMPO_H

class Tempo{
public:
	Tempo();
	Tempo(int h, int m, int s);
	void tick();
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