//
// Created by mikae on 22/11/2021.
//
#include "../../lib/cidade/Cidade.h"


#ifndef ARVORE_GERADORA_MINIMA_GRAFO_H
#define ARVORE_GERADORA_MINIMA_GRAFO_H

typedef struct Grafo{
    cidade ** cidades;
    int * visitados;
    float ** matrizAdj;
    float ** AGM;
}grafo;

grafo * newGrafo(int tamEntrada);

int * newVetor(int n);

float ** newMatriz(int n);

void preenCheMatriz(float **matriz, int n, int type);

int existeVerticeNaoVisitado(int * v, int n);

void mostraMatriz(float ** f, int n, char nome[]);

void prim(grafo * g, int n);

#endif //ARVORE_GERADORA_MINIMA_GRAFO_H
