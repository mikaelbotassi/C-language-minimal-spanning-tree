//
// Created by mikae on 23/11/2021.
//

#include "Cidade.h"

void menu(cidade **c, int n){
    int res;
    do{
        printf("\n1 - INSERIR NOVA CIDADE\n");
        printf("\n2 - MOSTRAR CIDADES CADASTRADAS\n");
        printf("\n0 - SAIR\n");
        printf("\nOPCAO: ");
        scanf("%d", &res);

        switch (res) {
            case 0:
                break;
            case 1:
                insereCidade(c, cidadeInfo(), n);
                break;
            case 2:
                mostrarCidade(c, n);
                break;
            default:
                printf("\nVALOR INVALIDO\n");
                break;
        }

    }while(res != 0);
}

cidade ** newCidade(int n){
    cidade ** c = malloc(n * sizeof(cidade *));
    for(int i = 0; i < n; i++){
        c[i] = NULL;
    }
    return c;
}

cidade * cidadeInfo(){
    cidade * c = malloc(sizeof (cidade));
    printf("Digite o codigo da cidade: ");
    scanf("%d", &c->cod);
    printf("Digite o nome da cidade: ");
    scanf("%s", c->nome);
    return c;
}

cidade ** insereCidade(cidade ** c, cidade * new, int n){
    int i = 0;
    while(c[i] != NULL && i < n){
        i++;
    }
    if(c[i] == NULL){
        c[i] = new;
        return c;
    }
    return NULL;
}

void mostrarCidade(cidade ** c, int n){
    for (int i = 0; i < n; ++i) {
        if(c[i] != NULL){
            printf("CODIGO: %d\nNOME: %s\n\n", c[i]->cod, c[i]->nome);
        }
    }
}