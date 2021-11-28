#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../lib/grafo/Grafo.h"

#ifndef _CONTROLEARQUIVOALUNO_H
#define _CONTROLEARQUIVOALUNO_H

grafo * readGrafoFromFile(int * tamEntrada);

void writeGrafoOnFile(grafo * fork, int quantCidades);


#endif //_CONTROLEARQUIVOALUNO_H
