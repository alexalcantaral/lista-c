#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int colunas = 0;

int *dimensionaMatriz(int l, int c)
{
    int tamanho = l * c;
    int *vet = (int *)malloc(tamanho * sizeof(int));
    if (vet == NULL)
    {
        printf("erro ao alocar vetor matriz!");
        exit(1);
    }
    return vet;
}
void zeraMatriz(int vet[], int tamanho)
{
    int k;

    for (k = 0; k < tamanho; k++)
    {
        vet[k] = 0;
    }
}
void imprimeMatriz(int vet[], int l, int c)
{
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            int calculo = (i * c) + j;
            printf(" %d ", vet[calculo]);
        }
        printf("\n");
    }
    printf("\n\n");
}

void adicionaElementos(int vet[], int numero, int linhas, int colunas)
{
    int k;
    k = (linhas - 1) * colunas + (colunas - 1);
    vet[k] = numero;
}
int buscarElemento(int vet[], int l, int c, int tamanho)
{
    int k = ((l - 1) * tamanho) + (c - 1);
    return vet[k];
}
void somaMatriz(int vet1[], int vet2[], int vet3[], int tamanho)
{
    for (int k = 0; k < tamanho; k++)
    {
        vet3[k] = vet1[k] + vet2[k];
    }
}