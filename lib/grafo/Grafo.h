//
// Created by mikae on 22/11/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef ARVORE_GERADORA_MINIMA_GRAFO_H
#define ARVORE_GERADORA_MINIMA_GRAFO_H

int * newGrafo(int n);

float ** newAGM(int n);

float ** newMatrizFloat(int n);

void mostraMatriz(float ** f, int n);

#endif //ARVORE_GERADORA_MINIMA_GRAFO_H
