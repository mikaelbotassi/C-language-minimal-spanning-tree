#include "lib/cidade/Cidade.h"

int main() {

    int n = 3;
    cidade ** city = newCidade(n);

    menu(city, n);

    int * visitas = newGrafo(n);

    float ** matriz = newMatrizFloat(n);

    float ** AGM = newAGM(n);
    mostraMatriz(matriz, n);

    return 0;
}
