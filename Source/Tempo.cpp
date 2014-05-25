#include "Tempo.h"
#define MAX = 60
#define MMS = 1000 

Tempo::Tempo()
{
	ms = 0;
	s = 0;
	h = 0;
	m = 0;
}

void Tempo::addUTempo(unit u){
	switch (u)
	{
	case H:
		h++;
		break;
	case M:
		if (m == 60)
			this->addUTempo(H);
		m++;
		break;
	case S:
		if (s = 60)
			this->addUTempo(M);
		s++;
		break;
	case MS:
		if (ms == 1000)
			this->addUTempo(S);
		ms++;
		break;
	}
}



Tempo::~Tempo()
{
}
