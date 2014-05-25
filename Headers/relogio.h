#pragma once
#include "Tempo.h"

class relogio
{
private:
	Tempo* tempo;
public:
	void tick();
	relogio();
	~relogio();
};

