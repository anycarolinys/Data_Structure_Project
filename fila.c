#include <stdio.h>
#include <stdlib.h>

struct Node {
    int num;
    struct Node *prox;

};

typedef struct Node NODE;

int tam;

void inicia(NODE *queue) {
    queue->prox = NULL;
    tam = 0;
}
int menu(void) {

    int op;
    printf("\n\n0. Sair\n");
    printf("1. Exibir Fila\n");
    printf("2. Enqueue\n");
    printf("3. Dequeue\n");
    printf("4. Limpar Fila\n");
    printf("Opcao: ");
    scanf("%1d", &op);

    return op;
}

NODE *aloca(void) {
    NODE *novoNo;
    novoNo = (NODE *) malloc(sizeof(NODE));

    if (!novoNo) {
        printf("MEMORIA INSUFICIENTE!");
        exit(1);
    } else {
        printf("Novo inteiro: ");
        scanf("%d", &novoNo->num);
        return novoNo;
    }
}

int vazia(NODE *queue) {
    
    if (queue->prox == NULL)
        return 1;
    else
        return 0;
}

//Insere um elemento ao fim da lista
void *enqueue(NODE *queue) {
    
    NODE *novoNo = aloca();
    novoNo->prox = NULL;

    if (vazia(queue)) {
        queue->prox = novoNo;
    } else {
        NODE *temp = queue->prox;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = novoNo;
    }
    tam++;
}

//Retira o primeiro elemento da lista
NODE *dequeue(NODE *queue) {

    if (vazia(queue)) {
        printf("Lista vazia!");
        return NULL;
    } else {
        NODE *prim;
        prim = queue->prox;
        queue->prox = prim->prox;
        prim->prox = NULL;

        tam--;
        return prim;
    }
}

void limpar(NODE *queue) {

    if (vazia(queue)) {
        printf("Lista vazia!");
    } else {
        NODE *atual, *prox;
        atual = queue->prox;
        prox = queue;

        while (atual != NULL) {
            prox = atual->prox;
            free(atual);
            atual = prox;
//Como 'atual' acabou de ser limpado, não é possível usar 'atual->prox'
        }
        tam = 0;
        printf("Memoria liberada!\n");
        free(queue);
        inicia(queue);
    }
}
void exibe(NODE *queue) {

    if (vazia(queue)) {
        printf("Lista vazia!");
    } else {
        NODE *temp;
        temp = queue->prox;

        printf("\nValores na fila:\n");
        while (temp != NULL) {
            printf("%d ", temp->num);
            temp = temp->prox;
        }
    }
}

void opcao(NODE *queue, int op) {
    NODE *valor;

    switch (op) {
    case 0:
        exit(0);
        break;
    case 1: 
        exibe(queue);
        break;
    case 2:
        enqueue(queue);
        break;
    case 3:
        valor = dequeue(queue);
        printf("Valor tirado da fila: %d", valor->num);
        break;
    case 4:
        limpar(queue);
        break;
    default:
        printf("Opcao invalida!\n");
        break;
    }
}


int main(void) {
    
    NODE *fila;
    fila = (NODE *) malloc(sizeof(NODE));

    inicia(fila);

    if (!fila) {
        printf("Memoria insuficiente!");
    } else {
        int op;
        do {
            op = menu();
            opcao(fila, op);
        } while (op);
    }
    free(fila);
    return 0;
}