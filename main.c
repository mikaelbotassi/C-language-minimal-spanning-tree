#include "lib/cidade/Cidade.h"

int main() {

    int n = 9;
    cidade ** city = newCidade(n);

    //menu(city, n);

    int * visitas = newGrafo(n);

    visitas[0] = 1;

    float ** grafo = newMatriz(n);

    preenCheMatriz(grafo, n);

    float ** AGM = newMatriz(n);

    mostraMatriz(grafo, n);

    prim(visitas, grafo, AGM, n);

    mostraMatriz(AGM, n);

    return 0;
}
