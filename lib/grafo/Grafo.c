//
// Created by mikae on 22/11/2021.
//

#include "Grafo.h"

int * newGrafo(int n){
    int * new = malloc(n*sizeof (int));
    for(int i = 0; i < n; i++){
        new[i] = 0;
    }
    return new;
}

float ** newAGM(int n){
    float ** new = malloc(n * sizeof(float));
    for (int i = 0; i < n; ++i) {
        new[i] = malloc(n * sizeof (float));
        for(int j = 0; j < n; j++){
            new[i][j] = 0;
        }
    }
    return new;
}

float ** newMatrizFloat(int n){
    float ** new = malloc(n * sizeof(float));
    for (int i = 0; i < n; ++i) {
        new[i] = malloc(n * sizeof (float));
        for(int j = 0; j < n; j++){
            new[i][j] = ((float)rand()/(float)(RAND_MAX) * 1000);
        }
    }
    return new;
}

void mostraMatriz(float ** f, int n){
    for (int i = 0; i < n; ++i) {
        for(int j = 0; j < n; j++){
            printf("\n%f", f[i][j]);
        }
    }
}
