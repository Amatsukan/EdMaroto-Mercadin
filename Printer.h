#ifndef PRINTER_H
#define PRINTER_H

#include "Supermercado.h"

class Printer{
public:
	Printer(Supermercado* _super);
	void print();
private:
	Supermercado* super;
};

#endif