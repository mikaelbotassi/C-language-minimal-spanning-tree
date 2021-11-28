#define println printf("\n");
#include "services/Controler.h"

int main() {

    setvbuf(stdout, NULL, _IONBF, 0); //Uma função para nao dar problema no debugger, não é referente
    //ao trabalho

    int tamEntrada;

    criaArquivo(); //Cria o arquivo de entrada

//================Estruturas==============================
    grafo * g = services(&tamEntrada);
//========================================================
    if(g != NULL){
        /*mostrarCidade(g->cidades, tamEntrada);
        mostraMatriz(g->matrizAdj, tamEntrada, "MATRIZ ADJACENTE");
        println;
        mostraMatriz(g->AGM, tamEntrada, "ARVORE GERADORA MINIMA");*/
        writeGrafoOnFile(g, tamEntrada);
    }

    return 0;
}
