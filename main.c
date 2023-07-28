#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

#define DADOS_TABELA_LINHA0 {{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}}
#define DADOS_TABELA_LINHA1 {{'#','\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '#'}}
#define DADOS_TABELA_LINHA2 {{'#','\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '#'}}
#define DADOS_TABELA_LINHA3 {{'#','\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '#'}}
#define DADOS_TABELA_LINHA4 {{'#','\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '#'}}
#define DADOS_TABELA_LINHA5 {{'#','\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '#'}}
#define DADOS_TABELA_LINHA6 {{'#','\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '#'}}
#define DADOS_TABELA_LINHA7 {{'#','\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '#'}}
#define DADOS_TABELA_LINHA8 {{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}}

#define DADOS_TABELA_COMPLETA {{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},{'#','\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '#'},{'#','\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '#'},{'#','\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '#'},{'#','\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '#'},{'#','\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '#'},{'#','\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '#'},{'#','\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '#'},{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}}

#define DADOS_TABELA_COMPLETA_OBSTACULOS {{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},{'#','\0', '\0', '#', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '#'},{'#','\0', '\0', '#', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '#', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '#'},{'#','\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '#', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '#'},{'#','\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '#'},{'#','\0', '\0', '\0', '\0', '\0', '#', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '#', '\0', '\0', '#'},{'#','\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '#', '\0', '\0', '\0', '\0', '\0', '#', '\0', '\0', '#'},{'#','\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '#'},{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}}

#define LINHA_TABELA 25
#define COLUNA_TABELA 9

#define X 0
#define Y 1

/*
Este projeto tem como finalidade criar uma inteligencia artificial capaz de navegar elementos em um mapa 2D de um ponto a outro, fixo ou nao

A meta e que o elemento tome o caminho mais direto possivel, e caso encontre um obstaculo, tente circular em volta deste

O mapa de navegação será dado por uma matriz, representando o mapa 2D

A inteligencia funcionara por meio da chamada da funcao, que sera responsavel por caminhar o elemento um ponto por vez, em direção ao seu
objetivo, desta forma o elemento caminhara uma vez por frame, ou na velocidade desejada

As posicoes devem ser definidas em coordenadas X e Y, dadas por variaveis separadas

Mapa da matriz:
######################
#                    #
#                    #
#                    #
#                    #
#                    #
#                    #
######################
*/

void printar_matriz();



int main()
{
    int *posicao_elemento;

    posicao_elemento = malloc(6*sizeof(posicao_elemento));

    posicao_elemento[X] = 0;
    posicao_elemento[Y] = 0;


    char elemento = 'X';

    int *posicao_ponto;

    posicao_ponto = malloc(6*sizeof(posicao_ponto));

    posicao_ponto[X] = 0;
    posicao_ponto[Y] = 0;

    char ponto = 'O';

    //Target linha_completa = DADOS_TABELA_COMPLETA;

    Target linha_completa = DADOS_TABELA_COMPLETA_OBSTACULOS;

    printf("Alocando a matriz...\n");
    Target *matriz2D = (Target*)malloc(3*sizeof(Target));

    printf("Copiando as linhas para a matriz...\n");
    memcpy(matriz2D, linha_completa, sizeof(Target));

    if(matriz2D==NULL) return 1;

    printf("Printando matriz...\n");

    printar_matriz(COLUNA_TABELA,LINHA_TABELA,matriz2D);

    printf("\nO elemento a ser inserido e: %c\n", elemento);

    printf("\nDefina a posicao Y do elemento, de acordo com a matriz\n");
    scanf("%i", &posicao_elemento[Y]);
    fflush(stdin);

    printf("Defina a posicao X do elemento, de acordo com a matriz\n");
    scanf("%i", &posicao_elemento[X]);
    fflush(stdin);

    printf("A posicao inserida e: %i,%i\n", posicao_elemento[Y], posicao_elemento[X]);

    printf("Inserindo o elemento na matriz...\n");
    (*matriz2D)[posicao_elemento[Y]][posicao_elemento[X]] = elemento;

    printf("\n O elemento inserido foi: %c\n", (*matriz2D)[posicao_elemento[Y]][posicao_elemento[X]]);

    printf("\nDefina a posicao Y do ponto, de acordo com a matriz\n");
    scanf("%i", &posicao_ponto[Y]);
    fflush(stdin);
    printf("Defina a posicao X do ponto, de acordo com a matriz\n");
    scanf("%i", &posicao_ponto[X]);
    fflush(stdin);

    printf("A posicao inserida e: %i,%i\n", posicao_ponto[Y], posicao_ponto[X]);

    printf("Inserindo o elemento na matriz...\n");
    (*matriz2D)[posicao_ponto[Y]][posicao_ponto[X]] = ponto;

    printar_matriz(COLUNA_TABELA,LINHA_TABELA,matriz2D);

    while(1)
    {
        *posicao_elemento = rastrear_posicao(COLUNA_TABELA,LINHA_TABELA,(*matriz2D), elemento, posicao_elemento, posicao_ponto);

        printar_matriz(COLUNA_TABELA,LINHA_TABELA,matriz2D);

        if((posicao_elemento[X]==posicao_ponto[X])&&(posicao_elemento[Y]==posicao_ponto[Y]))
        {
            break;
        }
    }

    printf("\nFinal do Programa!\n");

    free(matriz2D);

    free(posicao_elemento);

    free(posicao_ponto);

    return 0;
}

void printar_matriz(size_t linha, size_t coluna,Target *matriz)
{
    if (matriz == NULL)
    {
        printf("Erro! Erro nº %i, do tipo: %s", errno, strerror(errno));
        return;
    }

    size_t leitor1 = 0;
    size_t leitor2 = 0;

    for(leitor1=0;leitor1<linha;leitor1++)
    {
        printf("\n");
        for(leitor2=0;leitor2<coluna;leitor2++)
        {
            printf("%c", (*matriz)[leitor1][leitor2]);
        }
    }

    printf("\n Final da Leitura! \n");

    return;
}
