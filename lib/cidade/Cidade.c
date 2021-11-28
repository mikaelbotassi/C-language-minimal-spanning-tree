//
// Created by mikae on 23/11/2021.
//

#include "Cidade.h"

void menu(cidade **c, int n){
    int res;
    int cont = 0;
    do{
        printf("\n1 - INSERIR NOVA CIDADE\n");
        printf("\n2 - MOSTRAR CIDADES INSERIDAS\n");
        printf("\nOPCAO: ");
        scanf("%d", &res);

        switch (res) {
            case 1:
                insereCidade(c, cidadeInfo(), n);
                break;
            case 2:
                cont--;
                mostrarCidade(c, n);
                break;
            default:
                cont--; // Para pessoa digitar a quantidade de cidades passadas
                printf("\nVALOR INVALIDO\n");
                break;
        }
        cont++;

    }while(cont < n);
}

cidade ** newVetorCidade(int n){
    cidade ** c = malloc(n * sizeof(cidade *));
    for(int i = 0; i < n; i++){
        c[i] = NULL;
    }
    return c;
}

cidade * newCidade(){
    cidade * c = malloc(sizeof (cidade));
    c->nome = malloc(TAM_NOME * sizeof (char));
    return c;
}

cidade * cidadeInfo(){
    cidade * c = newCidade();
    printf("Digite o nome da cidade: ");
    scanf("%s", c->nome);
    return c;
}

void insereCidade(cidade ** c, cidade * new, int n){
    int i = 0;
    while(c[i] != NULL && i < n){
        i++;
    }
    if(c[i] == NULL){
        c[i] = new;
    }
}

void mostrarCidade(cidade ** c, int n){
    for (int i = 0; i < n; ++i) {
        if(c[i] != NULL){
            printf("CODIGO: %d\nNOME: %s\n\n", i, c[i]->nome);
        }
    }
}