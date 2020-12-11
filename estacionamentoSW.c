#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionario.h"

void liberaLista(LISTA *li) {
    
    // Lista não é inválida nem vazia
    if (li != NULL && (*li) != NULL) {
    // Nós auxiliares
    NO *aux, *no = *li; 

/* Enquando o próximo elemento for 
 * diferente do 1º elemento da lista...*/
    while ((*li) != no->prox) {
        aux = no;
        no = no->prox;
        free(aux);
    }

    free(no);
    free(li);
    
    }
}

int addFuncionario(LISTA *li) {
    
    // Lista inválida
    if (li == NULL) 
        return 0;

    NO *func = (NO *) malloc(sizeof(NO));

    // Nó p/ funcionário não criado
    if (func == NULL) 
        return 0;

    printf("ID: ");
    scanf("%d", func->ID);

    // Lista vazia (inserção no início)
    if ((*li) == NULL) { 
        *li = func;
        func->prox = func; //"Circularidade"
    } else {
        // Nó auxiliar que guarda o conteúdo da lista
        NO *aux = (*li); 

    // Percorra até que se chegue ao início da lista novamente
        while (aux->prox != (*li)) { 
            aux = aux->prox;
        }

        aux->prox = func;
        // O último no recebe o conteúdo da lista
        func->prox = *li; 
    }
    return 1;
}


void impressaoFunc(LISTA *li) {
    if ((*li) == NULL || li == NULL) {
        printf("Lista vazia!\n");
    } else {
        NO *aux = *li;
        do  {
            aux = aux->prox;
            printf("ID = %d\n", aux->ID);
        } while (aux != (*li));
    }
}
int opcoes() {
    int opcao;
    
    printf("\n1. Cadastrar funcionarios\n");
    printf("2. Imprimir funcionarios\n");
    // printf("2. Estacionar carro\n");
    printf("3. Retirar carro do estacionamento\n");
    printf("4. Exibe carros estacionados\n");
    printf("5. Exibe operacoes\n");
    printf("Opcao: ");
    scanf("%d", &opcao);
    printf("\n");
    return opcao;
}

void menu(int opcao, LISTA *li) {
    int r;
    switch (opcao) {
    case 1:
        r = addFuncionario(li);
        if (r == 1)
            printf("Funcionario add\n");
        else
            printf("Funcionario nao add\n");
        break;
    case 2:
        impressaoFunc(li);
        break;
    default:
        break;
    }
}
int main (void) {
    
    LISTA *lista;
    lista = (LISTA *) malloc(sizeof(LISTA));

    int op;

    do {
        op = opcoes();
        menu(op, lista);
    } while (op);
    
    liberaLista(lista);
    return 0;
}