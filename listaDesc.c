// LISTA DINÂMICA COM NÓ DESCRITOR
#include <stdio.h>
#include <stdlib.h>
#include "listaDesc.h"

LISTA *criaLista(void) {
    LISTA *li = (LISTA *) mallloc(sizeof(LISTA));

    if (li != NULL) {
        li->inicio = NULL;
        li->final = NULL;
        li->qtd = 0;
    }
    return li;
}

void libera(LISTA *li) {

    if (li != NULL) {
        NODE *no;
// ENQUANTO NÃO CHEGAR AO FIM DA LISTA
        while ((li->inicio) != NULL) {
            no = li->inicio;
            li->inicio = li->inicio->prox; // GUARDANDO O CONTEÚDO DO PRÓXIMO NÓ
            free(no);
        }
        free(li);
    }
}      

/* PARA UMA LISTA COM NÓ DESCRITOR A INSERÇÃO NO 
 * INÍCIO E EM POSIÇÕES INTERMEDIÁRIAS SEGUE A 
 * MESMA LÓGICA DE UMA LISTA DINÂMICA COMUM
 * JÁ PARA A INSERÇÃO NO FINAL NÃO É NECESSÁRIO PERCORRER  A LISTA */

int insereInicio(LISTA *li, struct aluno al) {

    if (li == NULL)
        return 1;
    
    NODE *no = (NODE *) malloc(sizeof(NODE));

    no->dados = al;
    no->prox = li->inicio;

// SE NÃO HOUVER NENHUM OUTRO ELEMENTO NA LISTA...
    if (li->inicio == NULL)
        li->final = no;

    li->inicio = no;
    li->qtd++;
    return 0;
}

int insereFinal(LISTA *li, struct aluno al) {

    if (li == NULL)
        return 1;
    
    NODE *no = (NODE *) malloc(sizeof(NODE));

    if (no == NULL)
        return 1;

    no->dados = al;
    no->prox = NULL; // DENOTANDO FIM DA LISTA

// SE NÃO HOUVER NENHUM OUTRO NÓ NA LISTA
    if (li->inicio == NULL)
        li->inicio = no;
    else
        li->final->prox = no;
        
    li->final = no;    
    li->qtd++;
    return 0;
}

int removeInicio(LISTA *li, struct aluno al) {
// FAZER 'li->inicio = li->inicio->prox;' É INVÁLIDO
    if (li == NULL || li->inicio == NULL)
        return 1;

/* SOLUÇÃO ALTERNATIVA PARA O BLOCO SEGUINTE:
    NODE *no = li->inicio;
    li->inicio = no->prox;
    free(no);
    
    if (li->inicio == NULL)
        li->final = NULL;
    li->qtd--;
    return 1;
*/

    
    NODE *no = li->inicio;

    while (no->prox != NULL)
        no = no->prox;

// SE A LISTA POSSUIR APENAS 1 NÓ
    if (no == li->inicio) {
        li->inicio = NULL;
        li->final = NULL;
    } else {
        no = no->prox;
    }

    free(no);
    li->qtd--;
    return 0;
}

int removeFim(LISTA *li, struct aluno al) {
    if (li == NULL || li->inicio == NULL) //LISTA INVÁLIDA OU VAZIA
        return 1;

/* 'li->inicio' É EQUIVALENTE A '(*li)' DAS LISTAS 
 * DUPLAMENTE ENCADEADAS */
    NODE *ante, *no = li->inicio; 

/* É NECESSÁRIA O NÓ ANTERIOR POIS ELE SERÁ 
* GUARDADO EM 'li->final' */
    while (no->prox != NULL) {
        ante = no; // ARMAZENANDO O CONTEÚDO DO PENÚLTIMO NÓ
        no = no->prox; // PERCORRENDO A LISTA
    }

/* SE O CONTEÚDO DO NÓ FINAL FOR IGUAL AO
 * CONTEÚDO DO PRIMEIRO NÓ, A LISTA POSSUI
 * APENAS 1 NÓ */
    if (no == li->inicio) {
        li->inicio = NULL;
        li->final = NULL;
    } else {
        ante->prox = NULL; // 'ante->prox = no->prox'
        li->final = ante;
    }
    
    free(no);
    li->qtd--;
    return 0;
}

int tamanhoLista(LISTA *li) {
    if (li == NULL)
        return 1;
    return li->qtd;
}

int main(void) {
    return 0;
}