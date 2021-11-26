//
// Created by mikae on 22/11/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#ifndef ARVORE_GERADORA_MINIMA_GRAFO_H
#define ARVORE_GERADORA_MINIMA_GRAFO_H

int * newVetor(int n);

float ** newMatriz(int n);

void preenCheMatriz(float **matriz, int n);

int existeVerticeNaoVisitado(int * v, int n);

void mostraMatriz(float ** f, int n, char nome[]);

void prim(int * visitado, float ** matrizAdj, float ** agm, int n);

#endif //ARVORE_GERADORA_MINIMA_GRAFO_H
