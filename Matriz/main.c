#include <stdio.h>
#include "matriz.h"

const int tamanho = 3;
const int tamVetor = tamanho * tamanho;

int main(void)
{
    int *vet = dimensionaMatriz(3, 3);
    zeraMatriz(vet, tamVetor);
    imprimeMatriz(vet, 3, 3);
    adicionaElementos(vet, 7, 1, 1);

    imprimeMatriz(vet, 3, 3);
    printf("%d\n\n", buscarElemento(vet, 1, 1, tamanho));
    int vet2[tamVetor], vet3[tamVetor];
    zeraMatriz(vet2, tamVetor);
    imprimeMatriz(vet2, 3, 3);
    somaMatriz(vet, vet2, vet3, tamVetor);
    printf("\n");
    imprimeMatriz(vet3, 3, 3);
    return 0;
}