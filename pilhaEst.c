// SEM INTERFACE
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct aluno {
    char nome[50];
    int matricula;
};

struct pilha {
    int qtd;
    struct aluno dados[MAX];
};

typedef struct pilha PILHA;

PILHA *criaPilha() {
    PILHA *p = (PILHA *) malloc(sizeof(PILHA));

    if (p != NULL)
        p->qtd = 0;
    return p;
}

void liberaPilha(PILHA *p) {
    free(p);
}

int tamanhoPilha(PILHA *p) {
    if (p == NULL)
        return -1;
    else
        return p->qtd;
}

// INSERIR ELEMENTOS NA PILHA
int pushStack(PILHA *p, struct aluno al) {
    if (p == NULL || p->qtd == MAX)
        return 1;
    
    p->dados[p->qtd] = al;
    p->qtd++;
    return 0;
}

// REMOVER ELEMENTOS DA PILHA
int popStack(PILHA *p) {
    if (p == NULL || p->qtd == 0)
        return 1;
    p->qtd--;
    return 0;
}

int consultaTopo(PILHA *p, struct aluno *al) {
    if (p == NULL || p->qtd == 0)
        return 1;
    *al = p->dados[p->qtd - 1]; // O TAMANHO DO VETOR EM SI NÃO É UMA POSIÇÃO VÁLIDA
    return 0;
}
int main(void) {

}