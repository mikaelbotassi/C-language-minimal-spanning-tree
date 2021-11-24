//
// Created by mikae on 22/11/2021.
//

#include "Grafo.h"

float pegaFloat();

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

float pegaFloat(){
    return ((float)rand()/(float)(RAND_MAX) * 1000);
}

float ** newMatrizFloat(int n){
    float ** new = malloc(n * sizeof(float));
    for (int i = 0; i < n; ++i) {
        new[i] = malloc(n * sizeof (float));
        for(int j = 0; j < n; j++){
            if(i == j){
                printf(" 0 ");
                new[i][j] = 0;
            }
            else{
                printf("Linha %d", i);
                //printf("\nDigite um float: ");
                scanf("%f", &new[i][j]);
            }
        }
    }
    return new;
}

int existeVerticeNaoVisitado(int * vertice, int n){
    for (int i = 0; i < n; ++i) {
        if(vertice[i] == 0){
            return 1;
        }
    }
    return 0;
}

void mostraMatriz(float ** f, int n){
    for (int i = 0; i < n; ++i) {
        for(int j = 0; j < n; j++){
            printf("\n%.2f", f[i][j]);
        }
    }
}

void prim(int * visitado, float ** matrizAdj, float ** agm, int n){
    float dist = 99999.99;
    int origem, destino;

    for (int orig = 0; orig < n; ++orig) {
        if(visitado[orig]){
            for (int dest = 0; dest < n; ++dest) {
                if(!visitado[dest]){
                    float current = matrizAdj[orig][dest];
                    if(current != 0){
                        if(current < dist){
                            dist = current;
                            origem = orig;
                            destino = dest;
                        }
                    }
                }
            }
        }
    }
    agm[origem][destino] = agm[destino][origem] = dist;
    visitado[destino] = 1;
}
