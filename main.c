#include <stdio.h>
#include <stdlib.h>
#include "funcionario.h"

int main(){
    
    int escolha, matricula;
    Funcionario *Lista = NULL;

    printf("---------------MENU---------------\n");
    printf("0- Encerrar operacao\n1- Adicionar funcionario\n2- Remover funcionario\n3- Imprimir funcionarios\n4- Buscar funcionario\n\nInforme o que voce deseja:");
    scanf("%d", &escolha);
    system("clear");

    while(escolha != 0){
        switch(escolha){
            case 1: Lista = inserirNoFinal(Lista); break;
            case 2: printf("Informe a matricula do funcionario a ser removido: ");
                    scanf("%d", &matricula);
                    Lista = removerFuncionario(Lista, matricula); break;
            case 3: imprimirLista(Lista); break;
            case 4: printf("Informe a matricula do funcionario a ser buscado: ");
                    scanf("%d", &matricula);
                    buscarFuncionario(Lista, matricula); break;
            default: printf("Opcao invalida!\n"); break;
        }
        printf("---------------MENU---------------\n");
        printf("0- Encerrar operacao\n1- Adicionar funcionario\n2- Remover funcionario\n3- Imprimir funcionarios\n4- Buscar funcionario\n\nInforme o que voce deseja:");
        scanf("%d", &escolha);
        system("clear");
    }
    printf("Operacao encerrada!");

    return 0;
}
