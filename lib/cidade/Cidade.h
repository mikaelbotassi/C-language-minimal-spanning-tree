//
// Created by mikae on 23/11/2021.
//

#include "../grafo/Grafo.h"

#ifndef ARVORE_GERADORA_MINIMA_CIDADE_H
#define ARVORE_GERADORA_MINIMA_CIDADE_H

typedef struct Cidade{
    int cod;
    char nome[31];
}cidade;

void menu(cidade **c, int n);

cidade ** newCidade(int n);

cidade * cidadeInfo();

cidade ** insereCidade(cidade ** c, cidade * new, int n);

void mostrarCidade(cidade ** c, int n);

#endif //ARVORE_GERADORA_MINIMA_CIDADE_H
