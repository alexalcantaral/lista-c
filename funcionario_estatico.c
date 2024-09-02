#include "funcionario.h"
#include <stdio.h>
#include <string.h>

void inicializarListaEstatico(ListaEstatico* lista) {
    lista->tamanho = 0;
}

void adicionarFuncionarioEstatico(ListaEstatico* lista) {
    if (lista->tamanho < 100) {
        printf("Informe o nome: ");
        scanf(" %49s", lista->funcionarios[lista->tamanho].nome);
        printf("Informe o cargo: ");
        scanf(" %19s", lista->funcionarios[lista->tamanho].cargo);
        printf("Informe o sexo (M/F): ");
        scanf(" %c", &lista->funcionarios[lista->tamanho].sexo);
        printf("Informe a idade: ");
        scanf(" %d", &lista->funcionarios[lista->tamanho].idade);
        printf("Informe a matricula: ");
        scanf(" %d", &lista->funcionarios[lista->tamanho].nMatricula);
        lista->tamanho++;
    } else {
        printf("Lista cheia!\n");
    }
}

void imprimirListaEstatico(ListaEstatico* lista) {
    for (int i = 0; i < lista->tamanho; i++) {
        printf("\nNome: %s\n", lista->funcionarios[i].nome);
        printf("Cargo: %s\n", lista->funcionarios[i].cargo);
        printf("Sexo: %c\n", lista->funcionarios[i].sexo);
        printf("Idade: %d\n", lista->funcionarios[i].idade);
        printf("Matricula: %d\n", lista->funcionarios[i].nMatricula);
    }
}

void removerFuncionarioEstatico(ListaEstatico* lista, int matricula) {
    int index = -1;
    for (int i = 0; i < lista->tamanho; i++) {
        if (lista->funcionarios[i].nMatricula == matricula) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        for (int i = index; i < lista->tamanho - 1; i++) {
            lista->funcionarios[i] = lista->funcionarios[i + 1];
        }
        lista->tamanho--;
        printf("Funcionario removido com sucesso!\n");
    } else {
        printf("Funcionario com matricula %d nao encontrado!\n", matricula);
    }
}

void buscarFuncionarioEstatico(ListaEstatico* lista, int matricula) {
    for (int i = 0; i < lista->tamanho; i++) {
        if (lista->funcionarios[i].nMatricula == matricula) {
            printf("\nNome: %s\n", lista->funcionarios[i].nome);
            printf("Cargo: %s\n", lista->funcionarios[i].cargo);
            printf("Sexo: %c\n", lista->funcionarios[i].sexo);
            printf("Idade: %d\n", lista->funcionarios[i].idade);
            printf("Matricula: %d\n", lista->funcionarios[i].nMatricula);
            return;
        }
    }
    printf("Funcionario com matricula %d nao encontrado!\n", matricula);
}
