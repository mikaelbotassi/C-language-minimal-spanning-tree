//
// Created by mikae on 26/11/2021.
//

#include "GeradorArquivo.h"
#define QTD_CID 100
#define DIRETORIO_ARQUIVO "../entradas/entrada.txt"

//============= FUNÇÕES PRIVADOS =========================
float geraDistancia(int linha, int coluna);

char * geraPalavra();

char geraLetraMaiuscula();

char geraLetraMinuscula();

char geraVogal();

double geraNumeroEntreZeroEUm();

int ehVogal(char letra);
//========================================================

//============= VARIÁVEIS GLOBAIS ========================
char vogais[5]={'a','e','i','o','u'};
//========================================================

void criaArquivo(){

    cidade cid;
    int i;

    FILE *arq_entrada;
    arq_entrada = fopen(DIRETORIO_ARQUIVO, "w");

    fprintf(arq_entrada,"%d\n",QTD_CID);

    //Nesse laço imprimo as cidades. Os codigos das cidades seraoo inteiros sequenciais de zero a qtd-1
    for (i=0;i<QTD_CID;i++){
        cid.nome = geraPalavra();
        fprintf(arq_entrada,"%d;%s\n",i,cid.nome);
    }
    //Vou gerar as distancias.
    //Como o grafo nao será direcional e não tenho arestas ligando um vertice a ele mesmo
    // teria uma matriz de adjacencia na qual a diagonal principal é toda de zeros
    // e os elementos acima da diagonal são iguais aos abaixo, isso é, o elemento A(l,c) = A(c,l)
    //Assim vou gerar apenas os elementos que ficam acima da diagonal principal e armazenar num vetor
    //Esse vetor terá seu tamanho dados por (qtd*qtd-qtd)/2 (resultado de uma somatoria
    // onde a primeira lina tem qtd-1 elementos e vai diminuindo de um em um até que a última tem zero.
    int tamVetDist = (QTD_CID*QTD_CID-QTD_CID)/2;
    float *distancias = (float *) malloc (tamVetDist*sizeof(float));

    int l,c;
    i=0;
    for(l=0;l<QTD_CID;l++){
        for(c=l+1;c<QTD_CID;c++){
            distancias[i]=geraDistancia(l,c);
            i++;
        }
    }

    //Nos laços abaixo imprimo a matriz de adjacencias completa, inclusive diagonal principal e elementos abaixo dela
    //Para achar no vetor a distancia entre elementos usei a formula que desenvolvi observando que a primeira linha
    // tem qtd-1 elementos no vetor,
    //a segunda linha qtd-2 e assim sucessivamente até que a última linha tem zero.
    // Assim, vi que para obter o indice do primeiro elemento da linha no vetor bastava resolver uma soma
    // de PA e que a partir dele
    //bastava somar a coluna menos linha -1. Vou tirar uma foto da dedução e
    // colocar nesse diretório para referencia futura se necessário
    for(l=0;l<QTD_CID;l++){
        for(c=0;c<QTD_CID-1;c++){
            if(l==c)
                fprintf(arq_entrada,"%.2f;",0.0);
            else if (l<c)
                fprintf(arq_entrada,"%.2f;",distancias[l*QTD_CID-(l*l+l)/2+c-l-1]);
            else
                fprintf(arq_entrada,"%.2f;",distancias[c*QTD_CID-(c*c+c)/2+l-c-1]);
        }
        if(l==(QTD_CID-1))
            fprintf(arq_entrada,"%.2f\n",0.0);
        else
            fprintf(arq_entrada,"%.2f\n",distancias[l*QTD_CID-(l*l+l)/2+c-l-1]);
    }

    fclose(arq_entrada);
}


int ehVogal(char letra){
    if (letra=='a' ||letra=='e' ||letra=='i' ||letra=='o' ||letra=='u' ||letra=='A' ||letra=='E' ||letra=='I' ||letra=='O' ||letra=='U')
        return 1;
    else
        return 0;
}

char geraLetraMaiuscula(){
    return rand()%26+65;
}

char geraLetraMinuscula(){
    return rand()%26+97;
}

char geraVogal(){
    return vogais[rand()%5];
}

char * geraPalavra(){
    int i;
    char *palavra = (char *) malloc (TAM_NOME * sizeof(char));
    palavra[0]= geraLetraMaiuscula();
    for(i=1;i<TAM_NOME;i++){
        if (ehVogal(palavra[i-1]))
            palavra[i]=geraLetraMinuscula();
        else
            palavra[i]=geraVogal();
    }
    palavra[i]='\0';
    return palavra;
}

double geraNumeroEntreZeroEUm(){
    int r1 = rand();
    int r2 = rand();
    if (r1<r2)
        return  ((double)r1)/((double)r2);
    else
        return  ((double)r2)/((double)r1);

}

//Esse método sempre será chamado com coluna > linha pois a ideia é só gerar os elementos acima da diagonal principal
float geraDistancia(int linha, int coluna) {
    double r;
    //Para garantir que o grafo será conexo garantirei que sempre haverá arestas entre vertices que o codigo diferem de 1
    //A distancia dessas arestas será um numero aleatório entre 10 e 110
    if (coluna - linha == 1) {
        return (geraNumeroEntreZeroEUm() + 0.1) * 100;
    }
        //Para os demais gero um aleatório entre 0 e 1. Se for menor que 0.5 não haverá aresta entre eles
        //caso contrário haverá aresta e a distancia da aresta será dada
        // pelo numero gerado * 200 - 90, ou seja, será algo entre 10 e 110.
    else {
        r = geraNumeroEntreZeroEUm();
        if (r < 0.5)
            return 0.0;
        else
            return r * 200 - 90;
    }
}