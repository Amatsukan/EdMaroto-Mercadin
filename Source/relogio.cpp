#include "relogio.h"


relogio::relogio()
{
	tempo = new Tempo();
}


relogio::~relogio()
{
	delete tempo;
}
