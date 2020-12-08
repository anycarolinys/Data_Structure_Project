/* ADICIONANDO E REMOVENDO NÓS EM QUALQUER POSIÇÃO NUMA 
* LISTA SIMPLESMENTE ENCADEADA COM CABEÇA 
* LISTAS SIMPLESMENTE ENCADEADAS COM CABEÇA (HEAD)
* Operações: 
* - EXIBIR ELEMENTOS DA LISTA
* - INSERIR NODE NO FINAL
* - INSERIR NODE NO INICIO 
* - RETIRAR NODE DO INICIO
* - RETIRAR NODE DO FINAL
* - ESCOLHER POSIÇÃO PARA INSERIR NODE
* - ESCOLHER POSIÇÃO PARA REMOVER NODE
* - ZERAR LISTA */
#include <stdio.h>
#include <stdlib.h>

//DECLARANDO VARIÁVEL GLOBAL DE TAMANHO DA LISTA
int tam;

struct List {
    int num;
    struct List *nxt;
};

typedef struct List NODE;

void start(NODE *list) {
    list->nxt = NULL;
    tam = 0;
}

int menu(void) {
    
    int op;
    printf("\n\n***ESCOLHA UMA OPCAO***\n");
    printf("0. SAIR\n");
    printf("1. EXIBIR ELEMENTOS DA LISTA\n");
    printf("2. INSERIR NODE NO INICIO\n");
    printf("3. INSERIR NODE NO FINAL\n");
    printf("4. RETIRAR NODE NO INICIO\n");
    printf("5. RETIRAR NODE NO FINAL\n");
    printf("6. ESCOLHER POSICAO P/ INSERIR\n");
    printf("7. ESCOLHER POSICAO P/ RETIRAR\n");
    printf("8. ZERAR LISTA\n"); 
    printf("Opcao: ");
    scanf("%1d", &op);

    return op;
}

NODE *allocates(void) {
    NODE *ptr;
    ptr = (NODE *) malloc(sizeof(NODE));

    if(!ptr) {
        printf("UNAVAILABLE MEMORY!");
        exit(1);
    } else {
        printf("PUT THE INTEGER: ");
        scanf("%5d", &ptr->num);
        return ptr;
    }
}

int isEmpty(NODE *list) {

    if(list->nxt == NULL)
    return 1; //TRUE
    else
    return 0; //FALSE
}

//FUNÇÃO: INSERE NÓ NO INÍCIO DA LISTA (APÓS O HEAD)
void insertFirst(NODE *list) {
    
    NODE *newHead = allocates();

    if(!newHead) {
        printf("\nMEMORIA INSUFICIENTE!\n");
        exit(1);
    }

//'list->nxt' REPRESENTA O ENDEREÇO DE UM NÓ COMPLETO
    NODE *oldHead = list->nxt;

    list->nxt = newHead;
    newHead->nxt = oldHead;
    tam++;
}

//FUNÇÃO: INSERE NÓ AO FINAL DA LISTA
void insertLast(NODE *list) {

    NODE *newFinal = allocates();
//APONTA PARA 'NULL' CONSIDERANDO-SE, PORTANTO, O ÚLTIMO VALOR
    newFinal->nxt = NULL;

    if(!newFinal) {
        printf("\nMEMORIA INSUFICIENTE!\n");
        exit(1);
    }

    if(isEmpty(list)) {
//HEAD APONTA PARA O NODE A SER INSERIDO
        list->nxt = newFinal;
    } else {
        NODE *temp = list->nxt;

        while(temp->nxt != NULL) {
            temp = temp->nxt;
        }
        temp->nxt = newFinal;
    }
    tam++;
}

/* FUNÇÃO: REMOVE O ÚLTIMO NÓ DA LISTA RETORNA O
* ENDEREÇO (PONTEIRO PARA O NÓ) DO NÓ REMOVIDO */
NODE *takeLast(NODE *list) {

    if (isEmpty(list)) {
        printf("\nLISTA VAZIA!\n");
        return NULL;
    }
    
    NODE *last, *penultimate;
//'last' RECEBE O CONTEÚDO DO 1º NÓ
    last = list->nxt;
//'penultimate' RECEBE O CONTEÚDO DA LISTA
    penultimate = list;

    while(last->nxt != NULL) {
        penultimate = last;
        last = last->nxt;   
    }

    penultimate->nxt = NULL;
    tam--;
    return last;
}

/* FUNÇÃO: REMOVE O PRIMEIRO NÓ (LOGO APÓS O HEAD) DA LISTA RETORNA O
* ENDEREÇO (PONTEIRO PARA O NÓ) DO NÓ REMOVIDO */
NODE *takeFirst(NODE *list) {

    if(isEmpty(list)) {
        printf("\nLISTA VAZIA!\n");
    NULL;
    }
    NODE *first;
//'first' RECEBE O CONTEÚDO DO 1º NÓ
    first = list->nxt;

//HEAD DA LISTA APONTA PARA O 2º NÓ
    list->nxt = first->nxt;

    tam--;
//RETORNANDO O NÓ RETIRADO
    return first;
}

void insert(NODE *list) {

    int pos;
    printf("***INSERT***\n");
    printf("CHOICE AN POSITION TO 1 FROM %d: ", tam);
    scanf("%1d", &pos);

    if(pos < 1 || pos > tam) {
        printf("INVALID POSITION!\n");
        exit(1);
    } else if (pos == 1) {
        insertFirst(list);
    } else {
        NODE *newNode = allocates();

        NODE *current = list->nxt, 
            *previous = list;

        if(isEmpty(list)) {
            list->nxt = newNode;
        } else {
            for (int i = 1; i < pos; i++) {
                previous = current;
                current = current->nxt;
            }
        previous->nxt = newNode;
        newNode->nxt = current;
        tam++;
        }
    }   
}

NODE *takeOff(NODE *list) {

    int pos;
    printf("***TAKE OFF***\n");
    printf("CHOICE AN POSITION TO 1 FROM %d: ", tam);
    scanf("%d", &pos);

    if(isEmpty(list)) {
        printf("EMPTY LIST!\n");
        exit(1);
    }
    

    if(pos < 1 || pos > tam) {
        printf("INVALID POSITION!\n");
        exit(1);
    } else if(pos == 1) {
        takeFirst(list);
    } else if(pos == tam) {
        takeLast(list);
    } else {
        NODE *current = list->nxt,
            *previous = list;
        for (int i = 1; i < pos; i++) {
            previous = current;
            current = current->nxt;
        }
        previous->nxt = current->nxt;
        tam--;
        return current;
    }
}

/* FUNÇÃO: EXIBE OS ELEMENTOS INTEIROS CONTIDOS NOS 
* NÓS DA LISTA COM SUA RESPECTIVA ORDEM*/
void show(NODE *list) {

    if(isEmpty(list)) {
        printf("EMPTY LIST!\n");
        exit(1);
    } 
    NODE *tmp;
    tmp = list->nxt;

    printf("\nVALUES: ");
    while(tmp != NULL) {
        printf("%d  ", tmp->num);
        tmp = tmp->nxt;
    }

    printf("\n      ");
    for (int i = 0; i < tam; i++) {
        printf("  ^");
    }
    printf("\nSORTED: ");
    for (int i = 1; i <= tam; i++) {
        
        printf("%d  ", i);
    }
}
//FUNÇÃO: LIBERA MEMÓRIA ALOCADA PARA A LISTA
void freeMemory(NODE *list) {

//"SE A LISTA NÃO ESTIVER VAZIA"
    if(!isEmpty(list)) {
        NODE *current, *next;
        current = list->nxt;

        while(current != NULL) {
            next = current->nxt;
            free(current);
            current = next;
        }
    } else {
        exit(1);
    }
}


/* FUNÇÃO: EXECUTA A OPERAÇÃO A SER REALIZADA NA LISTA 
* PASSADA COMO PARÂMETRO */
void option(NODE *list, int op) {
    
    int pos;
    NODE *valTake;
    switch (op) {
        case 0:
            exit(0);
            break;
        case 1:
            show(list);
            break;
        case 2:
            insertFirst(list);
            break;
        case 3:
            insertLast(list);
            break;
        case 4:
            valTake = takeFirst(list);
            printf("VALUE TOKEN FROM THE LIST = %d", valTake->num);
            break;
        case 5:
            valTake = takeLast(list);
            printf("VALUE TOKEN FROM THE LIST = %d", valTake->num);
            break;
        case 6:
            insert(list);
            break;
        case 7:
            valTake = takeOff(list);
            printf("VALUE TOKEN FROM THE LIST = %d", valTake->num);
            break;
        case 8:
            freeMemory(list);
            break;
        default:
            printf("\nCOMANDO INVALIDO!\n");
            break;
    }
}


int main(void) {

    NODE *list;
    list = (NODE *) malloc(sizeof(NODE));

    start(list);
    
    if(!list) {
    printf("UNAVAILABLE MEMORY!\n");
    exit(1); 
    } else {
        int opt;
        do {
            opt = menu();
            option(list, opt);
        } while (opt);

        free(list);
    }

    return 0;
}