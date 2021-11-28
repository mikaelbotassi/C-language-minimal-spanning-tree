//
// Created by mikae on 23/11/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#ifndef ARVORE_GERADORA_MINIMA_CIDADE_H
#define ARVORE_GERADORA_MINIMA_CIDADE_H

#define TAM_NOME 11 //Define o tamanho máximo de caracteres para guardar
// o nome da cidade e para escrever o arquivo

typedef struct Cidade{
    char * nome;
}cidade;

void menu(cidade **c, int n);

cidade * newCidade();

cidade ** newVetorCidade(int n);

cidade * cidadeInfo();

void insereCidade(cidade ** c, cidade * new, int n);

void mostrarCidade(cidade ** c, int n);

#endif //ARVORE_GERADORA_MINIMA_CIDADE_H
