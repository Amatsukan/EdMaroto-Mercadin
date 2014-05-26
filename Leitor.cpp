#ifndef LEITOR_CPP
#define LEITOR_CPP

#include "configParameters.cpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define ARQUIVO "conf.fnoc"

class Leitor{
public:
    config* lerConf() {

    FILE * pArquivoConfig = fopen(ARQUIVO, "r");
        if (pArquivoConfig == NULL) {
            cout << "Erro ao ler arquivo de configurações." << endl;
            cout << "Encerrando programa" << endl;
            throw(0);
        }
        
        char linha[100];
        int linhas = 0;
        int caixas = 0;
        config* c = new config();
        
        for(;true != false;) {
            if(fgets(linha, 100, pArquivoConfig) == NULL) {
                break;
            }
            if (linha[0] == '#' || linha[0] == ' ' || linha[0] == '\n') {
                continue;
            }
            switch (linhas) {
            case 0:
                c->nome = string(linha);
                break;
            case 1:
                c->jornada = new Tempo(atoi(linha));
                break;
            case 2:
                c->clientAcada= new Tempo(0);
                c->clientAcada->adds(atoi(linha));
                break;
            case 3:
                c->numeroCaixas = atoi(linha);
                break;
            default:
                if(c->caixas == NULL){
                    c->caixas = new Lista<Caixa*>();
                }
                char nomeCaixa[50];
                int eficiencia;
                double salario;
                sscanf(linha, "%s %d %lf", nomeCaixa, &eficiencia, &salario);
                Caixa *cx = new Caixa(string(nomeCaixa), salario, eficiencia);
                c->caixas->add(cx);
                caixas += 1;
                if (caixas == c->numeroCaixas) {
                    break;
                }
            }
            linhas += 1;
        }
        
        return c;
    }
};

#endif