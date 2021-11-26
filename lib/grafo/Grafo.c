//
// Created by mikae on 22/11/2021.
//

#include "Grafo.h"

#define maior 99999

float pegaFloat();
char pegaLetra(int i);

int * newVetor(int n){
    int * new = malloc(n*sizeof (int));
    for(int i = 0; i < n; i++){
        new[i] = 0;
    }
    return new;
}

float ** newMatriz(int n){
    float ** new = malloc(n * sizeof(float*));
    for (int i = 0; i < n; ++i) {
        new[i] = malloc(n * sizeof (float));
        for(int j = 0; j < n; j++){
            new[i][j] = -1; // -1 significa que a esta posição não foi atribuído nenhum valor
        }
    }
    return new;
}

float pegaFloat(){
    return ((float)rand()/(float)(RAND_MAX) * 10);
}

void preenCheMatriz(float **matriz, int n){
    for (int i = 0; i < n; ++i) {
        for(int j = 0; j < n; j++){
            if(i == j){
                printf("0.0 ");
                matriz[i][j] = 0;
            }
            else{
                if(matriz[j][i] != -1){
                    printf("%.1f ", matriz[j][i]);
                    matriz[i][j] = matriz[j][i];
                }
                else{
                    //matriz[i][j] = pegaFloat();
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

void mostraMatriz(float ** f, int n, char nome[]){
    int caractere = 65; // Para pegar a letra que condiz com a coluna
    printf("\n\n\t%s\n\n", nome);
    for(int j = 0; j < n; j++){
        printf("\t  %c ", caractere + j);
    }
    for (int i = 0; i < n; ++i) {
        printf("\n%c ", caractere + i);
        for(int j = 0; j < n; j++){
            printf("\t%.1f ", f[i][j]);
        }
    }
}

void prim(int * visitado, float ** matrizAdj, float ** agm, int n){
    int origem, destino;
    while(existeVerticeNaoVisitado(visitado, n)){
        float dist = maior;
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
        }
        agm[origem][destino] = agm[destino][origem] = dist;
        visitado[destino] = 1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if((agm[i][j] == -1)  || (agm[i][j] == maior)){
                agm[i][j] = 0;
            }
        }
    }
}
