#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int num;
    struct Stack *nxt;
};

typedef struct Stack NODE;

int tam;

void startStack(NODE *stack) {
    stack->nxt = NULL;
    tam = 0;
}

int menu(void) {

    int op;

    printf("\n\n***CHOICE AN OPTION***\n");
    printf("0. SAIR\n");
    printf("1. EXIBIR ELEMENTOS DA PILHA\n");
    printf("2. PUSH\n");
    printf("3. POP\n");
    printf("4. ZERAR PILHA\n");
    printf("OPCAO: ");
    scanf("%1d", &op);

    return op;
}

NODE *allocates(void) {

    NODE *newNode;
    newNode = (NODE *) malloc(sizeof(NODE));

    if(!newNode) {
        printf("\nUNAVAILABLE MEMORY!\n");
    } else {
        printf("PUT THE INTEGER: ");
        scanf("%d", &newNode->num);
    }
    return newNode;
}

int isEmpty(NODE *stack) {

    if(stack->nxt == NULL)
    return 1;
    else
    return 0;
}

void freeMemory(NODE *stack) {

    if(!isEmpty(stack)) {
        NODE *current, *next;
        current = stack->nxt;

        while (current != NULL) {
            next = current->nxt;
            free(current);
            current = next;
        }
        startStack(stack);
    } else
        printf("EMPTY LIST!\n");
}

void showStack(NODE *stack) {

    if(isEmpty(stack)){
        printf("PILHA vazia!\n\n");
    } else {
        NODE *temp;
        temp = stack->nxt;
        printf("\nVALUES IN THE STACK:     \n");
        
        while (temp != NULL) {
            printf("%d  ", temp->num);
            temp = temp->nxt;
        }
        
        printf("\n");
        for(int count = 0; count < tam; count++)
            printf("^  ");
    
        printf("\n");
        for(int count = 1; count <= tam; count++)
            printf("%d  ", count);
    }
}

//COLOCANDO NODE EM FINAL DA FILA
void pushStack(NODE *stack) {
    
    NODE *newNode = allocates();
    newNode->nxt = NULL;

    if(isEmpty(stack)) {
        stack->nxt = newNode;
    } else {
        NODE *temp = stack->nxt;
        
        while(temp->nxt != NULL) {
            temp = temp->nxt;
        }
        temp->nxt = newNode;
    }
    tam++;
}

//RETIRANDO NODE DO FINAL DA FILA
NODE *popStack(NODE *stack) {

    if(isEmpty(stack)) {
        printf("\nEMPTY STACK!\n");
        return NULL;
    } else {
         NODE *last = stack->nxt,
               *previous = stack;
        while (last->nxt != NULL) {
            previous = last;
            last = last->nxt;
        }

        previous->nxt = NULL;
        tam--;
        return last;
    }
}

void option(NODE *stack, int op) {
    
    NODE *temp;
    switch (op) {
    case 0:
        exit(0);
        break;
    case 1:
        showStack(stack);
        break;
    case 2:
        pushStack(stack);
        break;
    case 3:
        temp = popStack(stack);
        printf("\nVALUE TOKEN FROM THE STACK = %d", temp->num);
        break;
    case 4:
        freeMemory(stack);
        startStack(stack);
        break;
    default:
        printf("\nINVALID OPTION!\n");
        break;
    }
}

int main(void) {
    
    NODE *STACK;
    STACK = (NODE *) malloc(sizeof(NODE));

    startStack(STACK);

    if(!STACK) {
        printf("\nUNAVAILABLE MEMORY!\n");
        exit(1);
    } else {
        int op;
        do {
            op = menu();
            option(STACK, op);
        } while (op);
        free(STACK);
    }
    return 0;
}