#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void cleanBuf(void) {
    char c;
    while((c = getchar()) != '\n' && c != EOF);
}

no *alocaJogador() {
    no *jog = (no *) malloc(sizeof(no));
    if (!jog) {
        printf("Memoria insuficiente!");
        exit(1);
    } else {
        printf("Nome do jogador: ");
        cleanBuf();
        scanf("%[^\n]s", &jog->gamer.nome);
        // scanf("%[^\ns]", &jog->j.nome);
    }
    
    return jog;
}

no *inicializa(void) {
    no *f = (no *) malloc(sizeof(no));
    
    if (f != NULL) 
        f->prox = NULL; // A fila está vazia

    return f;
}

void insereJogador(no *fila) {
    no *novo = alocaJogador();
    novo->prox = NULL;
    
    // Lista vazia
    if (fila->prox == NULL) {
        fila->prox = novo;
    } else {
        no *aux = fila->prox; // Nó auxiliar
        
        while (aux != NULL) {
            aux = aux->prox;
            aux->prox = novo;
        }
    }
}

void liberaFila(no *fila) {
    
    if (fila != NULL) {
        no *atual, *prox;
        atual = fila->prox;

        while (atual != NULL) {
            prox = atual->prox;
            free(atual);
            atual = prox;
        }
    }

    free(fila);
}

int menu(void) {
    int op;

    printf("0. Sair\n");
    printf("1. Adicionar jogador\n");
    printf("2. Exibir jogadores\n");
    printf("3. Liberar memoria\n");
    printf("Opcao: ");
    scanf("%d", &op);
    return op;
}

void opcao(no *fila, int op) {
    no *aux;
    switch (op) {
    case 1:
        insereJogador(fila);
        break;
    case 2:
        aux = fila->prox;
        while (aux != NULL) {
            printf("%s", aux->gamer.nome);
            aux = aux->prox;
        }
    case 0:
        exit(0);
        break;
    case 3:
        liberaFila(fila);
        break;
    }
}

int main(void) {

    no *fila = inicializa();
    int op;
    
    do {
        op = menu();
        opcao(fila, op);
    } while (op);
    
    liberaFila(fila);
    return 0;
}