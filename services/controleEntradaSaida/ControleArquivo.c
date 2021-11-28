#include "ControleArquivo.h"

// =-=-=-=-= CONSTANTES =-=-=-=-=

#define ERROR_FALHA_ALOCACAO "\n\tERRO: Erro durante alocação de memória!\n"
#define ERRO_ABRIR_ARQUIVO "\n\tERRO: Erro na abertura do arquivo!\n"
#define ERRO_CRIAR_ARQUIVO "\n\tERRO: Erro ao criar o arquivo!\n"

#define MENSSAGE_LENDO_ARQUIVO "\n\tAVISO: Lendo arquivo, por favor aguarde...\n"
#define DIRETORIO_ARQUIVO_ENTRADA "../entradas/entrada.txt"
#define DIRETORIO_ARQUIVO_SAIDA "../saida/"
#define LINE_MAX_LENGTH 255
#define FILE_NAME_MAX_LENGTH 31
#define DELIMITER ";"

// =-=-=-=-= METODOS PRIVADOS | DECLARAÇÃO =-=-=-=-=

cidade *readNextCity(FILE *fp);
void readDist(FILE * fp, int registros, float * vetorAdj);

// =-=-=-=-= METODOS PRIVADOS | IMPLEMENTAÇÃO =-=-=-=-=

void readDist(FILE * fp, int registros, float * vetorAdj){
    float f;
    char * line = malloc((registros * 7)*sizeof (char));
    char * ptr;
    int cont = 0;

    fscanf(fp, " %[^\n]*c", line);
    ptr = strtok(line, DELIMITER);
    while(ptr != NULL){
        vetorAdj[cont] = (float) atof(ptr);
        ptr = strtok(NULL, DELIMITER);
        cont++;
    }
    free(line);
}

cidade * readNextCity(FILE *fp) {
    cidade * c = newCidade();
    char *line = (char *) malloc((LINE_MAX_LENGTH + 1) * sizeof(char));
    char *ptr;

    fscanf(fp, " %[^\n]%*c", line);
    strtok(line, DELIMITER);

    ptr = strtok(NULL, DELIMITER);
    strcpy(c->nome, ptr);

    free(line);

    return c;
}
// =-=-=-=-= METODOS PUBLICOS =-=-=-=-=

grafo * readGrafoFromFile(int * tamEntrada)
{
    FILE *fp = fopen(DIRETORIO_ARQUIVO_ENTRADA, "r");
    int contador = 0;
    int registros;

    if (!fp)
    {
        printf(ERRO_ABRIR_ARQUIVO);
        return NULL;
    }

    printf(MENSSAGE_LENDO_ARQUIVO);
    fscanf(fp, "%d", &registros);
    grafo * fork = newGrafo(registros);
    while (!feof(fp) && contador < registros)
    {
        cidade * c = readNextCity(fp);
        insereCidade(fork->cidades, c, registros);
        contador++;
    }
    contador = 0;
    while (!feof(fp) && contador < registros)
    {
        readDist(fp, registros, fork->matrizAdj[contador]);
        contador++;
    }

    fclose(fp);
    *tamEntrada = registros;
    return fork;
}

void writeGrafoOnFile(grafo * fork, int quantCidades) {
    //Cada linha desse arquivo deve apresentar o código da cidade de origem, o nome
    //da cidade de origem, o código da cidade de destino, o nome da cidade de
    //destino e a distância da estrada, tudo separado por vírgulas.
    int nomeArquivoSaidaLength = strlen(DIRETORIO_ARQUIVO_SAIDA) + FILE_NAME_MAX_LENGTH + 1;
    char *nomeArquivoSaida = (char *) malloc(nomeArquivoSaidaLength * sizeof(char));
    FILE *fp;

    if (!fp) {
        printf(ERRO_CRIAR_ARQUIVO);
        return;
    }

    sprintf(nomeArquivoSaida, "%sviasAsfaltadas.txt", DIRETORIO_ARQUIVO_SAIDA);
    fp = fopen(nomeArquivoSaida, "w");
    float distTotal = 0; // Variavel para guardar a distância total asfaltada
    for (int i = 0; i < quantCidades; ++i) {
        for(int j = 0; j < quantCidades; j++){
            float distancia = fork->AGM[i][j];
            if(distancia != 0 && i < j){ //Se a estrada estiver asfaltada(ou seja Distancia != 0) e
                //a distância entre uma cidade e outra ainda nao estiver escrita(ou seja I < j)
                distTotal += distancia;
                fprintf(fp, "ORIGEM:[%d, %s], DESTINO:[%d, %s], DISTANCIA: %.2f\n",
                        i, fork->cidades[i]->nome, j, fork->cidades[j]->nome, distancia);
            }
        }
    }
    fprintf(fp, "DISTANCIA TOTAL ASFALTADA = %.2f", distTotal);

    fclose(fp);
}
