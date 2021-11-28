//
// Created by mikae on 27/11/2021.
//

#include "Controler.h"

grafo * services(int * tamEntrada){
    grafo * g = NULL;
    int res;
    printf("\n\n\t\tOLA! NESTE PROGRAMA VOCE TEM OPCOES!\n\t\tVOCE PODE:\n\n");
    printf("1 - LER ARQUIVOS DE ENTRADA(PARA SEGUIR A ORIENTACAO DO TRABALHO DE"
           "'TPA' POR FAVOR SIGA ESTA OPCAO)\n");
    printf("2 - INSERIR MANUALMENTE AS CIDADES E AS DISTANCIAS\n");
    printf("3 - INSERIR MANUALMENTE AS CIDADES E DEIXAR AS DISTANCIAS SEREM ALEATORIAS\n");
    printf("0 - SAIR\n\n");
    printf("DIGITE UMA OPCAO: ");
    scanf("%d", &res);
    switch (res) {
        case 0:
            break;
        case 1:
            g = readGrafoFromFile(tamEntrada);
            g->visitados[0] = 1; //Começarei a percorrer os vértices pelo vértice 0;
            // Para isso eu atribuo 1 para ele como um visitado
            prim(g, *tamEntrada);
            break;

        case 2:
            printf("DIGITE QUANTAS CIDADES HA NO TOTAL: ");
            scanf("%d", tamEntrada);

            g = newGrafo(*tamEntrada);

            menu(g->cidades, *tamEntrada);

            preenCheMatriz(g->matrizAdj, *tamEntrada, 1);//Atribui valores à matriz;

            g->visitados[0] = 1; //Começarei a percorrer os vértices pelo vértice 0;
            // Para isso eu atribuo 1 para ele como um visitado

            prim(g, *tamEntrada); // Usa o algoritmo de prim baseado na matriz adjacente;
            break;

        case 3:
            printf("DIGITE QUANTAS CIDADES HA NO TOTAL: ");

            scanf("%d", tamEntrada);

            g = newGrafo(*tamEntrada);

            menu(g->cidades, *tamEntrada);

            preenCheMatriz(g->matrizAdj, *tamEntrada, 2);//Atribui valores à matriz;

            g->visitados[0] = 1; //Começarei a percorrer os vértices pelo vértice 0;
            // Para isso eu atribuo 1 para ele como um visitado

            prim(g, *tamEntrada); // Usa o algoritmo de prim baseado na matriz adjacente;
            break;
    }
    return g;
}
