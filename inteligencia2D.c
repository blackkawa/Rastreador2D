#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CIMA        0
#define BAIXO       1
#define ESQUERDA    2
#define DIREITA     3

#define X 0
#define Y 1

#define MOVIMENTO_VALIDO 0
#define MOVIMENTO_INVALIDO 1

#define MOVIMENTO_BAIXO (*matriz)[posicao_elemento[Y]][posicao_elemento[X]] = '*';posicao_elemento[Y] = posicao_elemento[Y]+1;(*matriz)[posicao_elemento[Y]][posicao_elemento[X]] = elemento;
#define MOVIMENTO_CIMA (*matriz)[posicao_elemento[Y]][posicao_elemento[X]] = '*';posicao_elemento[Y] = posicao_elemento[Y]-1;(*matriz)[posicao_elemento[Y]][posicao_elemento[X]] = elemento;
#define MOVIMENTO_DIREITA (*matriz)[posicao_elemento[Y]][posicao_elemento[X]] = '*';posicao_elemento[X] = posicao_elemento[X]+1;(*matriz)[posicao_elemento[Y]][posicao_elemento[X]] = elemento;
#define MOVIMENTO_ESQUERDA (*matriz)[posicao_elemento[Y]][posicao_elemento[X]] = '*';posicao_elemento[X] = posicao_elemento[X]-1;(*matriz)[posicao_elemento[Y]][posicao_elemento[X]] = elemento;

int checar_proximo_movimento();

typedef char(Target)[9][25];

#define CHECAR_VALIDADE_MOVIMENTO validade_movimento = checar_proximo_movimento(*matriz,posicao_elemento,direcao);

/*a definição de qual direção o elemento vai tomar é de acordo com o ponto, sempre aproximanto uma posição da matriz uma vez que a função
e chamada. Isso e definido verificando qual a diferença matematica entre as coordenadas, e então se é tomada a decisão de qual operação
tomar para diminuir esta diferença


Esta função deve conferir se existe um espaço vazio para poder avançar, senão ela tenta outras possibilidades.
*/

/*Definir um peso para decidir para qual direcao ir em caso de obstaculos
 O peso sera a diferenca entre as distancias, quanto maior a diferença entre distancias, maior o seu peso

 E ao encontrar um obstaculo, o peso decidira para qual lado o elemento se dirigirá
*/

//APARENTEMENTE TERMINADA!!!!


int rastrear_posicao(int linhas, int colunas,Target *matriz, char elemento, int *posicao_elemento, int *posicao_ponto)
{
    int direcao = 0;
    int validade_movimento = 0;
    int peso_X,peso_Y = 0;

    printf("Analisando o peso dos movimentos\n");
    //Verificando se o elemento esta mais a direita
    if(posicao_elemento[X]>posicao_ponto[X])
    {
        peso_X = ESQUERDA;
    //Caso o elemento esteja mais a esquerda
    }else
        {
            peso_X = DIREITA;
        }

    //Caso o elemento esteja abaixo do ponto, o peso sera para cima
    if(posicao_elemento[Y]>posicao_ponto[Y])
    {
        peso_Y = CIMA;

    //Caso o elemento esteja acima do ponto, o peso sera para baixo
    }else
        {
            peso_Y = BAIXO;
        }

    printf("O peso dos movimentos e X: %i, e Y: %i\n", peso_X, peso_Y);

    printf("A posicao dos elementos [X]%i e [Y]%i\n", posicao_elemento[Y],posicao_elemento[X]);

    printf("Verificando para qual posicao o movimento sera\n");


    if(posicao_elemento[Y]<posicao_ponto[Y])
    {
        printf("Checar se o elemento esta acima do ponto\n");
        direcao = BAIXO;

        CHECAR_VALIDADE_MOVIMENTO

        if(validade_movimento==MOVIMENTO_VALIDO)
        {
            MOVIMENTO_BAIXO
            return *posicao_elemento;
        }else
            {
                printf("Analisando qual direcao tem mais peso.\n");
                    //Caso o elemento esteja a esquerda
                    printf("Checando para ver se e possivel ir na coordenada X\n");
                    if(peso_X==ESQUERDA)
                    {
                        direcao = ESQUERDA;
                        CHECAR_VALIDADE_MOVIMENTO
                        if(validade_movimento==MOVIMENTO_VALIDO)
                        {
                            MOVIMENTO_ESQUERDA
                            return *posicao_elemento;
                        }
                    }else
                        {
                            //Caso o peso esteja a direita
                            direcao = DIREITA;
                            CHECAR_VALIDADE_MOVIMENTO

                            if(validade_movimento==MOVIMENTO_VALIDO)
                            {
                                MOVIMENTO_DIREITA
                                return *posicao_elemento;
                            }
                        }

                    direcao = CIMA;
                    CHECAR_VALIDADE_MOVIMENTO

                    if(validade_movimento==MOVIMENTO_VALIDO)
                    {
                        MOVIMENTO_CIMA
                        return *posicao_elemento;
                    }else
                        {
                            printf("Nao houve movimento valido!\n");
                            return *posicao_elemento;
                        }
            }

    }else if(posicao_elemento[Y]>posicao_ponto[Y])
            {
                printf("Checar se o elemento esta abaixo do ponto\n");
                direcao = CIMA;

                CHECAR_VALIDADE_MOVIMENTO

                if(validade_movimento==MOVIMENTO_VALIDO)
                {
                    MOVIMENTO_CIMA
                    return *posicao_elemento;
                }else
                    {
                        printf("Analisando qual direcao tem mais peso.\n");
                            //Caso o elemento esteja a direita
                            if(peso_X==DIREITA)
                            {
                                direcao = DIREITA;
                                CHECAR_VALIDADE_MOVIMENTO

                                if(validade_movimento==MOVIMENTO_VALIDO)
                                {
                                MOVIMENTO_DIREITA
                                return *posicao_elemento;
                                }

                            }else
                                {
                                    direcao = ESQUERDA;
                                    CHECAR_VALIDADE_MOVIMENTO

                                    if(validade_movimento==MOVIMENTO_VALIDO)
                                    {
                                        MOVIMENTO_ESQUERDA
                                        return *posicao_elemento;
                                    }
                                }
                                direcao = BAIXO;
                                CHECAR_VALIDADE_MOVIMENTO

                                if(validade_movimento==MOVIMENTO_VALIDO)
                                {
                                    MOVIMENTO_BAIXO
                                    return *posicao_elemento;
                                }else
                                    {
                                        printf("Nao houve movimento valido!\n");
                                        return *posicao_elemento;
                                    }

                            }
            }else if(posicao_elemento[X]<posicao_ponto[X])
                    {
                        printf("Checar se o elemento esta a direita do ponto\n");
                        direcao = DIREITA;

                        CHECAR_VALIDADE_MOVIMENTO

                        if(validade_movimento==MOVIMENTO_VALIDO)
                        {
                            MOVIMENTO_DIREITA
                            return *posicao_elemento;
                        }else
                            {
                                printf("Analisando qual direcao tem mais peso.\n");
                                    //Caso o elemento esteja abaixo do ponto
                                    if(peso_Y==CIMA)
                                    {
                                        direcao = CIMA;
                                        CHECAR_VALIDADE_MOVIMENTO

                                        if(validade_movimento==MOVIMENTO_VALIDO)
                                        {
                                            MOVIMENTO_CIMA
                                            return *posicao_elemento;
                                        }

                                    }else
                                        {
                                            direcao = BAIXO;
                                            CHECAR_VALIDADE_MOVIMENTO

                                            if(validade_movimento==MOVIMENTO_VALIDO)
                                            {
                                                MOVIMENTO_BAIXO
                                                return *posicao_elemento;
                                            }
                                        }
                                        direcao = ESQUERDA;
                                        CHECAR_VALIDADE_MOVIMENTO

                                        if(validade_movimento==MOVIMENTO_VALIDO)
                                        {
                                            MOVIMENTO_ESQUERDA
                                            return *posicao_elemento;
                                        }else
                                            {
                                                printf("Nao houve movimento valido!\n");
                                                return *posicao_elemento;
                                            }

                                    }
                    }else if(posicao_elemento[X]>posicao_ponto[X])
                        {
                            printf("Checar se o elemento esta a esquerda do ponto\n");
                            direcao = ESQUERDA;

                            CHECAR_VALIDADE_MOVIMENTO

                            if(validade_movimento==MOVIMENTO_VALIDO)
                            {
                                MOVIMENTO_ESQUERDA
                                return *posicao_elemento;
                            }else
                                {
                                    //Caso o elemento esteja acima do ponto
                                    if(peso_Y==BAIXO)
                                    {
                                        direcao = BAIXO;
                                        CHECAR_VALIDADE_MOVIMENTO

                                        if(validade_movimento==MOVIMENTO_VALIDO)
                                        {
                                            MOVIMENTO_BAIXO
                                            return *posicao_elemento;
                                        }else
                                            {
                                                direcao = CIMA;
                                                CHECAR_VALIDADE_MOVIMENTO

                                                if(validade_movimento==MOVIMENTO_VALIDO)
                                                    {
                                                        MOVIMENTO_CIMA
                                                        return *posicao_elemento;
                                                    }
                                            }
                                        }else
                                            {
                                                direcao = CIMA;
                                                CHECAR_VALIDADE_MOVIMENTO

                                                if(validade_movimento==MOVIMENTO_VALIDO)
                                                    {
                                                        MOVIMENTO_CIMA
                                                        return *posicao_elemento;
                                                    }
                                            }
                                    }
                            }
    printf("Nao foi possivel determinar a posicao do elemento em relacao ao ponto\n");
    return *posicao_elemento;
}

//Esta funcao checa se o movimento e valido, procurando por espaços vazios, caso o movimento seja valido, retorna 0, senao retorna 1.
int checar_proximo_movimento(Target *matriz, int *posicao_elemento, int direcao)
{
    int validade_movimento = 0;
    printf("Checando...\n");
    printf("A direcao inserida: %i\n", direcao);
    printf("A posicao dos elementos [X]%i e [Y]%i\n", posicao_elemento[Y],posicao_elemento[X]);

    if(direcao==CIMA)
    {
        //Checando se a direção de cima esta vazia
        printf("Checando se a direcao de cima esta vazia\n");
        printf("A proxima posicao e: %c", (*matriz)[posicao_elemento[Y]-1][posicao_elemento[X]]);
        if(((*matriz)[posicao_elemento[Y]-1][posicao_elemento[X]]=='\0')||((*matriz)[posicao_elemento[Y]-1][posicao_elemento[X]]=='O'))
        {
            printf("A posicao de cima esta vazia!\n");
            return MOVIMENTO_VALIDO;
        }else
            {
                printf("A posicao de cima esta ocupada! Tente outro caminho.\n");
                return MOVIMENTO_INVALIDO;
            }

    printf("Checando se a direção de baixo esta vazia\n");
    printf("A proxima posicao e: %c", (*matriz)[posicao_elemento[Y]+1][posicao_elemento[X]]);
    }else if(direcao==BAIXO)
        {
            //Checando se a direção de baixo esta vazia
            if(((*matriz)[posicao_elemento[Y]+1][posicao_elemento[X]]=='\0')||((*matriz)[posicao_elemento[Y]+1][posicao_elemento[X]]=='O'))
            {
                printf("A posicao de baixo esta vazia!\n");
                return MOVIMENTO_VALIDO;
            }else
                {
                    printf("A posicao de baixo esta ocupada! Tente outro caminho.\n");
                    return MOVIMENTO_INVALIDO;
                }

        printf("Checando se a direção da direita esta vazia\n");
        printf("A proxima posicao e: %c", (*matriz)[posicao_elemento[Y]][posicao_elemento[X]+1]);
        }else if(direcao==DIREITA)
        {
            //Checando se a direção da direita esta vazia
            if(((*matriz)[posicao_elemento[Y]][posicao_elemento[X]+1]=='\0')||((*matriz)[posicao_elemento[Y]][posicao_elemento[X]+1]=='O'))
            {
                printf("A posicao da direita esta vazia!\n");
                return MOVIMENTO_VALIDO;
            }else
                {
                    printf("A posicao da direita esta ocupada! Tente outro caminho.\n");
                    return MOVIMENTO_INVALIDO;
                }

        printf("Checando se a direção da esquerda esta vazia\n");
        printf("A proxima posicao e: %c", (*matriz)[posicao_elemento[Y]][posicao_elemento[X]-1]);
        }else if(direcao==ESQUERDA)
        {
            //Checando se a direção da esquerda esta vazia
            if(((*matriz)[posicao_elemento[Y]][posicao_elemento[X]-1]=='\0')||((*matriz)[posicao_elemento[Y]][posicao_elemento[X]-1]=='O'))
            {
                printf("A posicao da esquerda esta vazia!\n");
                return MOVIMENTO_VALIDO;
            }else
                {
                    printf("A posicao da esquerda esta ocupada! Tente outro caminho.\n");
                    return MOVIMENTO_INVALIDO;
                }
        }
    printf("Nao foi possivel checar a validade!\n");
    return MOVIMENTO_INVALIDO;
}
