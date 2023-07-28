#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef char(Target)[9][25];

int rastrear_posicao(int linhas, int colunas, char matriz[colunas][linhas], char elemento, int *posicao_elemento, int *posicao_ponto);

int checar_proximo_movimento(Target *matriz, int *posicao_elemento, int direcao);



#endif // HEADER_H_INCLUDED
