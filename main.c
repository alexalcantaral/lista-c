#include <stdio.h>
#include <stdlib.h>
#include "funcionario.h"

#define LISTA_DINAMICA 1
#define LISTA_ESTATICA 2

int main() {
    int escolha, tipoLista, matricula;
    Funcionario *ListaDinamica = NULL;
    ListaEstatico listaEstatica;
    inicializarListaEstatico(&listaEstatica);

    printf("Escolha o tipo de lista:\n");
    printf("1- Lista Dinâmica\n");
    printf("2- Lista Estática\n");
    printf("Informe sua escolha: ");
    scanf("%d", &tipoLista);
    system("clear");

    if (tipoLista != LISTA_DINAMICA && tipoLista != LISTA_ESTATICA) {
        printf("Tipo de lista inválido! Encerrando programa.\n");
        return 1;
    }

    do {
        printf("---------------MENU---------------\n");
        printf("0- Encerrar operacao\n1- Adicionar funcionario\n2- Remover funcionario\n3- Imprimir funcionarios\n4- Buscar funcionario\n\nInforme o que voce deseja:");
        scanf("%d", &escolha);
        system("clear");

        switch (escolha) {
            case 1:
                if (tipoLista == LISTA_DINAMICA)
                    ListaDinamica = inserirNoFinal(ListaDinamica);
                else
                    adicionarFuncionarioEstatico(&listaEstatica);
                break;
            case 2:
                printf("Informe a matricula do funcionario a ser removido: ");
                scanf("%d", &matricula);
                if (tipoLista == LISTA_DINAMICA)
                    ListaDinamica = removerFuncionario(ListaDinamica, matricula);
                else
                    removerFuncionarioEstatico(&listaEstatica, matricula);
                break;
            case 3:
                if (tipoLista == LISTA_DINAMICA)
                    imprimirLista(ListaDinamica);
                else
                    imprimirListaEstatico(&listaEstatica);
                break;
            case 4:
                printf("Informe a matricula do funcionario a ser buscado: ");
                scanf("%d", &matricula);
                if (tipoLista == LISTA_DINAMICA)
                    buscarFuncionario(ListaDinamica, matricula);
                else
                    buscarFuncionarioEstatico(&listaEstatica, matricula);
                break;
            case 0:
                printf("Operacao encerrada!\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (escolha != 0);

    return 0;
}
