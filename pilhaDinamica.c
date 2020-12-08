#include <stdio.h>
#include <stdlib.h>
#include "pilhaDinamica.h"


void cleanBuf(void) {
    char c;
    while((c = getchar()) != '\n' && c != EOF);
}

PILHA *criaPilha(void) {
    PILHA *p = (PILHA *) malloc(sizeof(PILHA));
    if (p != NULL)
        (*p)= NULL;
    return p;
}

void liberaPilha(PILHA *p) {

    if (p != NULL) {
        NODE *no;
        while ((*p) != NULL) {
            no = *p;
            *p = (*p)->prox;
            free(no);
        }
    free(p);
    }
}

int tamanhoPilha(PILHA *p) {
    if (p == NULL)
        return 1;
    
    NODE *no = *p;
    int tam = 0;

    while (no != NULL) {
        tam++;
        no = no->prox;
    }
    return tam;
}

// INSERIR NÓ NA PILHA

int pushStack(PILHA *p, struct aluno al) {
    if (p == NULL)
        return 1;

    NODE *no = (NODE *) malloc(sizeof(NODE));

    if (no == NULL)
        return 1;
    no->dados = al;
    no->prox = *p;
    *p = no;
    return 0;
}

int popStack(PILHA *p) {
    if (p == NULL || (*p) == NULL)
        return 1;

    NODE *noAux = *p;
    (*p) = noAux->prox;
    free(noAux);
    return 0;
}

int showNode(PILHA *p, struct aluno *al) {
    
    if (p == NULL || (*p) == NULL)
        return 1;
    
    *al = (*p)->dados;
    return 0;
}


void dadosAluno(struct aluno *al) {
    printf("\nINFORME OS DADOS DO ALUNO: \n");
    
    printf("NOME: ");
    cleanBuf();
    scanf("%[^\n]s", al->nome);
    cleanBuf();
    printf("MATRICULA: ");
    scanf("%d", &al->matricula);
    printf("\n");
}

int menu(void) {
    int opcao;

    printf("\n\n0. ENCERRAR PROGRAMA\n");
    printf("1. INSERIR NA PILHA\n");
    printf("2. REMOVER DA PILHA\n");
    printf("3. EXIBIR PRIMEIRO NO\n");
    printf("OPCAO: ");
    scanf("%1d", &opcao);

    return opcao;
}

void opcao(PILHA *p, int op) {
    int teste;
    struct aluno al;

    switch (op) {
    case 0:
        liberaPilha(p);
        exit(0);
        break;
    case 1:
        dadosAluno(&al);
        teste = pushStack(p, al);
        if (teste == 0)
            printf("INSERIDO!\n");
        else
            printf("NAO INSERIDO!\n");
        break;
    case 2:
        teste = popStack(p);
        if (teste == 0)
            printf("REMOVIDO!\n");
        else
            printf("NAO REMOVIDO!\n");
        break;
    case 3:
        teste = showNode(p, &al);
        if (teste == 0)
            printf("ALUNA(O): %s", al.nome);
        else
            printf("ALUNA(O) NAO ENCONTRADO!\n");
        break;
    default:
        printf("OPCAO INVALIDA!\n");
        break;
    }
}


int main(void) {
    PILHA *p = criaPilha();

    int op;
    do {
        op = menu();
        opcao(p, op);
    } while (op);
    
    return 0;
}