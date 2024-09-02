#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionario.h"

struct funcionario {
    char nome[50], cargo[20], sexo;
    int idade, nMatricula;
    Funcionario *prox;
};

Funcionario* criarNo() {
    Funcionario *novo = (Funcionario*)malloc(sizeof(Funcionario));
    return novo;
}

void adicionarFuncionario(Funcionario *novoNode) {
    printf("Informe o nome: ");
    scanf(" %49[^\n]", novoNode->nome);  // Permite espaço no nome
    fflush(stdin);

    printf("Informe o cargo: ");
    scanf(" %19[^\n]", novoNode->cargo);  // Permite espaço no cargo
    fflush(stdin);

    printf("Informe o sexo (M/F): ");
    scanf(" %c", &novoNode->sexo);
    fflush(stdin);

    printf("Informe a idade: ");
    scanf(" %d", &novoNode->idade);

    printf("Informe a matricula: ");
    scanf(" %d", &novoNode->nMatricula);
    system("clear");
}

Funcionario* inserirNoFinal(Funcionario *Lista) {
    Funcionario *novoNode = criarNo();
    adicionarFuncionario(novoNode);

    if (Lista == NULL) {
        novoNode->prox = NULL;
        Lista = novoNode;
    } else {
        Funcionario* aux = Lista;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        novoNode->prox = NULL;
        aux->prox = novoNode;
    }
    return Lista;
}

void imprimirLista(Funcionario* Lista) {
    system("clear");
    Funcionario* aux = Lista;

    while (aux != NULL) {
        printf("\nNome: %s\n", aux->nome);
        printf("Cargo: %s\n", aux->cargo);
        printf("Sexo: %c\n", aux->sexo);
        printf("Idade: %d\n", aux->idade);
        printf("Matricula: %d\n", aux->nMatricula);
        aux = aux->prox;
    }
}

Funcionario* removerFuncionario(Funcionario* Lista, int matricula) {
    if (Lista == NULL) {
        printf("Lista vazia!\n");
        return NULL;
    }

    Funcionario *aux = Lista, *anterior = NULL;

    while (aux != NULL && aux->nMatricula != matricula) {
        anterior = aux;
        aux = aux->prox;
    }

    if (aux == NULL) {
        printf("Funcionario com matricula %d nao encontrado!\n", matricula);
        return Lista;
    }

    if (anterior == NULL) {
        Lista = aux->prox;
    } else {
        anterior->prox = aux->prox;
    }

    free(aux);
    printf("Funcionario removido com sucesso!\n");
    return Lista;
}

void buscarFuncionario(Funcionario* Lista, int matricula) {
    Funcionario *aux = Lista;
    while (aux != NULL && aux->nMatricula != matricula) {
        aux = aux->prox;
    }

    if (aux == NULL) {
        printf("Funcionario com matricula %d nao encontrado!\n", matricula);
    } else {
        printf("\nNome: %s\n", aux->nome);
        printf("Cargo: %s\n", aux->cargo);
        printf("Sexo: %c\n", aux->sexo);
        printf("Idade: %d\n", aux->idade);
        printf("Matricula: %d\n", aux->nMatricula);
    }
}
