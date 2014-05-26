#include <string>
#include <stdio.h>
#include "Lista.hpp"
#include "Tempo.h"
#include "Caixa.h"

using namespace std;

class config{
public:
    string nome;
    int numeroCaixas;
    Lista<Caixa*>* caixas;
    Tempo* jornada;
    Tempo* clientAcada;
};


