/*LISTAS SIMPLESMENTE ENCADEADAS COM CABEÇA (HEAD)
Operações: 
- EXIBIR ELEMENTOS DA LISTA\n");
- INSERIR NODE NO INICIO \n");
- INSERIR NODE NO FINAL\n");
- RETIRAR NODE DO INICIO\n");
- RETIRAR NODE DO FINAL\n");
- ZERAR LISTA*/
#include <stdio.h>
#include <stdlib.h>

//CRIANDO UMA STRUCT PARA OS NÓS
struct node {
    int num;
    struct node *nxt;
};  

//DECLARANDO UM NOVO TIPO COM A STRUCT
typedef struct node NODE;

/* MÉTODO: ZERA A LISTA PARA QUE A MESMA POSSA SER PREENCHIDA NOVAMENTE
* OBS.: MÉTODO NECESSÁRIO POIS O PONTEIRO DA LISTA APONTA, INICIALMENTE, 
* PARA UM LIXO DE MEMÓRIA */
void inicia(NODE *list) {
    list->nxt = NULL;
}

/* FUNÇÃO: EXIBE AS OPÇÕES DE OPERAÇÕES A SEREM REALIZADAS PELOS USERS,
* RETORNA A OPÇÃO ESCOLHIDA */
int menu(void) {
    
    int op;
    printf("\n\n***ESCOLHA UMA OPCAO***\n");
    printf("0. SAIR\n");
    printf("1. EXIBIR ELEMENTOS DA LISTA\n");
    printf("2. INSERIR NODE NO INICIO \n");
    printf("3. INSERIR NODE NO FINAL\n");
    printf("4. RETIRAR NODE DO INICIO\n");
    printf("5. RETIRAR NODE DO FINAL\n");
    printf("6. ZERAR LISTA\n"); 
    printf("Opcao: ");
    scanf("%1d", &op);

    return op;
}

/* FUNÇÃO: CONFERE SE A LISTA ESTÁ VAZIA (SEM NÓS INSERIDOS)
* RETORNA 1 (TRUE) OU 0 (FALSE)*/
int isEmpty(NODE *list) {
    if(list->nxt == NULL)
    return 1; //TRUE
    else
    return 0; //FALSE
}

//FUNÇÃO: INSERE NÓ NO INÍCIO DA LISTA (APÓS O HEAD)
void insertFirst(NODE *list) {
    
    NODE *newHead = (NODE *) malloc(sizeof(NODE));

    if(!newHead) {
        printf("\nMEMORIA INSUFICIENTE!\n");
        exit(1);
    }
    
    printf("NOVO INTEIRO: ");
    scanf("%5d", &newHead->num);

//'list->nxt' REPRESENTA O ENDEREÇO DE UM NÓ COMPLETO
    NODE *oldHead = list->nxt;

    list->nxt = newHead;
    newHead->nxt = oldHead;
}

//FUNÇÃO: INSERE NÓ AO FINAL DA LISTA
void insertLast(NODE *list) {
    NODE *newFinal = (NODE *) malloc(sizeof(NODE));
    newFinal->nxt = NULL;

    if(!newFinal) {
        printf("\nMEMORIA INSUFICIENTE!\n");
        exit(1);
    }

    printf("NOVO INTEIRO: ");
    scanf("%5d", &newFinal->num);
    
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

//RETORNANDO O NÓ RETIRADO
    return first;

}

/* FUNÇÃO: EXIBE OS ELEMENTOS INTEIROS CONTIDOS NOS 
* NÓS DA LISTA*/
void show(NODE *list) {

    if(isEmpty(list)) {
        printf("\nLISTA VAZIA!\n");
    }  else {
    NODE *temp;
    temp = list->nxt;
    
    printf("\nVALORES NA LISTA:\n");
        while(temp != NULL) {
            printf("%d     ", temp->num);
            temp = temp->nxt;
        }
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
    
    NODE *first, *last;
    switch (op) {
        case 0:
            freeMemory(list);
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
            first = takeFirst(list);
            printf("VALOR DO NODE RETIRADO = %d", first->num);
            break;
        case 5:
            last = takeLast(list);
            printf("VALOR DO NODE RETIRADO = %d", last->num);
            break;
        case 6:
            inicia(list);
            break;
        default:
            printf("\nCOMANDO INVALIDO!\n");
            break;
    }
}


int main(void) {

    NODE *lista;
    lista = (NODE *) malloc(sizeof(NODE));

    if(!lista) {
    printf("ESPACO INSUFICIENTE\n");
    }

//ZERANDO A LISTA
    inicia(lista);
    
    int opt;
    do {
    opt = menu();
    option(lista, opt);
    } while (opt);

//LIBERANDO MEMÓRIA DA LISTA CRIADA
    free(lista);

    return 0;
}