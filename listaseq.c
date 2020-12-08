#include <stdio.h>
#include <stdlib.h>
#include "listaseq.h"
#define MAX 100

void cleanBuf(void) {
    char c;
    while((c = getchar()) != '\n' && c != EOF);
}

LISTA *cria(void) {
    LISTA *li;
    li = (LISTA *) malloc(sizeof(LISTA));

    if (li != NULL) {
        li->qtd = 0; //INICIALIZANDO
    }

    return li;
}

void libera(LISTA *li) {
    free(li);
}

int tamanhoLista(LISTA *li) {
    if (li == NULL)
        return -1;
    else
        return li->qtd;
}

int listaCheia(LISTA *li) {
    if (li == NULL)
        return 1;
    
    return (li->qtd == MAX);
}

int insereFinal(LISTA *li, struct aluno al) {
    if (li == NULL)
        return 1;
    if (listaCheia(li))
        return 1;
    
    li->dados[li->qtd] = al;
    li->qtd++;
    return 0;
}

int insereInicio(LISTA *li, struct aluno al) {

    if (li == NULL)
        return 1;
    if (listaCheia(li))
        return 1;

    for (int i = 0; i < li->qtd; i++) { 
        li->dados[i+1] = li->dados[i];
    }

    li->dados[0] = al;
    li->qtd++;
    return 0;
}

int insereLista(LISTA *li, struct aluno al) {
    if (li == NULL)
        return 1;
    if (listaCheia(li))
        return 1;
    
    int i = 0;

    while (i < li->qtd && li->dados[i].matricula < al.matricula)
        i++;

    for (int j = li->qtd - 1; j >= i; j--) {
        li->dados[j + 1] = li->dados[j];
    }

    li->dados[i] = al;
    li->qtd++;
    return 0;
}

int removeInicio(LISTA *li) {

    if (li == NULL)
        return 1;
    if (li->qtd == 0)
        return 1;
    
    for (int i = 0; i < li->qtd - 1; i++) {
        //A POSIÇÃO QUE VEM ANTES RECEBE A POSIÇÃO QUE VEM DEPOIS
        li->dados[i] = li->dados[i+1];
    }

    li->qtd--;
    return 0;
}


int removeFinal(LISTA *li) {
    if (li == NULL)
        return 1;
    if (li->qtd == 0)
        return 1;
    
    li->qtd--;
    return 0;
}

int removeLista(LISTA *li, int matricula) {

    if (li == NULL)
        return 1;
    if (li->qtd == 0)
        return 1;
    
    int k = 0;
    while (k <= li->qtd && li->dados[k].matricula != matricula) {
        k++;
    }

    if (k == li->qtd) {
        //ELEMENTO NÃO ENCONTRADO
        printf("MATRICULA NAO ENCONTRADA!\n");
        return 1;
    } 
    
    for (int i = k; i < li->qtd - 1; i++) {
        li->dados[i] = li->dados[i + 1];
    }
    
    li->qtd--;
    return 0;
}

int consultaPosicao(LISTA *li, int pos, struct aluno *al) {

    if (li == NULL || pos > li->qtd || pos <= 0)
        return 1;

    *al = li->dados[pos-1];
    return 0;
}

int consultaMatricula(LISTA *li, int matricula, struct aluno *al) {

    if (li ==  NULL)
        return 1;

    int k = 0;

    while (k <= li->qtd && li->dados[k].matricula != matricula)
        k++;
    
    if (k == li->qtd) {
        printf("ELEMENTO NAO ENCONTRADO!\n");
        return 1;
    }
        

    *al = li->dados[k];
    return 0;
}

int menu(void) {

    int opcao;

    printf("\n\n1. LIBERAR MEMORIA\n");
    printf("2. INSERIR\n");
    printf("3. INSERIR AO INICIO\n");
    printf("4. INSERIR AO FINAL\n");
    printf("5. REMOVER\n");
    printf("6. REMOVER DO INICIO\n");
    printf("7. REMOVER DO FINAL\n");
    printf("8. CONSULTAR POR MATRICULA\n");
    printf("9. CONSULTAR POR POSICAO\n");
    printf("OPCAO: ");
    scanf("%1d", &opcao);

    return opcao;
}

void opcao(LISTA *li, int op) {
    
    int teste, matricula, pos;
    struct aluno al;

    switch (op) {
    case 1:
        libera(li);
        break;
    case 2:
        printf("\nINFORME OS DADOS DO ALUNO: \n");
        printf("MATRICULA: ");
        scanf("%d", &al.matricula);
        cleanBuf();
        printf("NOME: ");
        scanf("%[^\n]s", al.nome);
        cleanBuf();
        printf("NOTA 1: ");
        scanf("%f", &al.n1);
        printf("NOTA 2: ");
        scanf("%f", &al.n2);
        printf("NOTA 3: ");
        scanf("%f", &al.n3);
        teste = insereLista(li, al);
        if (teste == 0)
            printf("INSERIDO!\n");
        else
            printf("NAO INSERIDO!\n");
        break;
    case 3:
        printf("\nINFORME OS DADOS DO ALUNO: \n");
        printf("MATRICULA: ");
        scanf("%d", &al.matricula);
        cleanBuf();
        printf("NOME: ");
        scanf("%[^\n]s", al.nome);
        cleanBuf();
        printf("NOTA 1: ");
        scanf("%f", &al.n1);
        printf("NOTA 2: ");
        scanf("%f", &al.n2);
        printf("NOTA 3: ");
        scanf("%f", &al.n3);
        teste = insereInicio(li, al);
        if (teste == 0)
            printf("INSERIDO!\n");
        else
            printf("NAO INSERIDO!\n");
        break;
    case 4:
        printf("\nINFORME OS DADOS DO ALUNO: \n");
        printf("MATRICULA: ");
        scanf("%d", &al.matricula);
        cleanBuf();
        printf("NOME: ");
        scanf("%[^\n]s", al.nome);
        cleanBuf();
        printf("NOTA 1: ");
        scanf("%f", &al.n1);
        printf("NOTA 2: ");
        scanf("%f", &al.n2);
        printf("NOTA 3: ");
        scanf("%f", &al.n3);
        teste = insereFinal(li, al);
        if (teste == 0)
            printf("INSERIDO!\n");
        else
            printf("NAO INSERIDO!\n");
        break;
    case 5:
        printf("MATRICULA: ");
        scanf("%d", &matricula);
        teste = removeLista(li, matricula);
        if (teste == 0)
            printf("REMOVIDO!\n");
        else
            printf("NAO REMOVIDO!\n");
        break;
    case 6:
        teste = removeInicio(li);
        if (teste == 0)
            printf("REMOVIDO!\n");
        else
            printf("NAO REMOVIDO!\n");
        break;
    case 7:
        teste = removeFinal(li);
        if (teste == 0)
            printf("REMOVIDO!\n");
        else
            printf("NAO REMOVIDO!\n");
        break;
    case 8:
        printf("MATRICULA: ");
        scanf("%d", &matricula);
        teste = consultaMatricula(li, matricula, &al);
        if (teste == 0)
            printf("ALUNA(O): %s\n", al.nome);
        else
            printf("ALUNO NAO ENCONTRADO!\n");
        break;
    case 9:
        printf("POSICAO NA LISTA: ");
        scanf("%d", &pos);
        teste = consultaPosicao(li, pos, &al);
        if (teste == 0)
            printf("ALUNA(O): %s\n", al.nome);
        else
            printf("ALUNO NAO ENCONTRADO!\n");
        break;
    default:
    printf("OPCAO INVALIDA!\n");
        break;
    }
}
int main(void) {

    LISTA *li;
    li = cria();

    int op;
    do {
        op = menu();
        opcao(li, op);
    } while (op);
    

    libera(li);
    return 0;
}