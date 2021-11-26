//#include "lib/cidade/Cidade.h"
#include "services/geradorArquivo/GeradorArquivo.h"
#define println printf("\n");
#define TAMANHO_ENTRADA 9

int main() {

    setvbuf(stdout, NULL, _IONBF, 0);

    criaArquivo();

//================Estruturas==============================
    cidade ** city = newVetorCidade(TAMANHO_ENTRADA);
    int * visitas = newVetor(TAMANHO_ENTRADA);
    float ** matrizAdj = newMatriz(TAMANHO_ENTRADA);
    float ** AGM = newMatriz(TAMANHO_ENTRADA);
    visitas[0] = 1;//Começarei a percorrer os vértices pelo vértice 0;
    // Para isso eu atribuo 1 para ele como um visitado
//========================================================

    //menu(city, TAMANHO_ENTRADA);

    preenCheMatriz(matrizAdj, TAMANHO_ENTRADA);//Atribui valores à matriz;

    prim(visitas, matrizAdj, AGM, TAMANHO_ENTRADA); // Usa o algoritmo de prim baseado na matriz adjacente;

    mostraMatriz(matrizAdj, TAMANHO_ENTRADA, "MATRIZ ADJACENTE");
    println;
    mostraMatriz(AGM, TAMANHO_ENTRADA, "ARVORE GERADORA MINIMA");

    return 0;
}
