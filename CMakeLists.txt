cmake_minimum_required(VERSION 3.20)
project(Arvore_Geradora_Minima C)

set(CMAKE_C_STANDARD 99)

add_executable(Arvore_Geradora_Minima main.c lib/grafo/Grafo.c lib/cidade/Cidade.c
        services/geradorArquivo/GeradorArquivo.c services/controleEntradaSaida/ControleArquivo.c
        services/Controler.c services/Controler.h)
