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

float ** newMatriz(int n){
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

void preenCheMatriz(float **matriz, int n){
    for (int i = 0; i < n; ++i) {
        for(int j = 0; j < n; j++){
            if(i == j){
                printf("0 ");
            }
            else{
                if(matriz[j][i] != 0){
                    printf("%.1f ", matriz[j][i]);
                    matriz[i][j] = matriz[j][i];
                }
                else{
                    //new[i][j] = pegaFloat();
                    printf("\nDigite um float: ");
                    scanf("%f", &matriz[i][j]);
                }
            }
        }
    }
}

int existeVerticeNaoVisitado(int * v, int n){
    for (int i = 0; i < n; ++i) {
        if(v[i] == 0){
            return 1;
        }
    }
    return 0;
}

void mostraMatriz(float ** f, int n){
    printf("\n\n\tMATRIZ:\n");
    for (int i = 0; i < n; ++i) {
        printf("\nLINHA %d", i);
        for(int j = 0; j < n; j++){
            printf("\nCOLUNA %d:", j);
            printf("%.1f", f[i][j]);
        }
    }
}

void prim(int * visitado, float ** matrizAdj, float ** agm, int n){
    int origem, destino;

    while(existeVerticeNaoVisitado(visitado, n)){
        float dist = 99999;
        for (int orig = 0; orig < n; orig++) {
            if(visitado[orig]){
                for (int dest = 0; dest < n; dest++) {
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
            agm[origem][destino] = dist;
            agm[destino][origem] = dist;
            visitado[destino] = 1;
        }
    }
}
