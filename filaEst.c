#include <stdio.h>
#include <stdlib.h>

struct aluno {
    int matricula;
    char nome[50];
};

struct node {
    struct aluno dados;
    struct node *prox;
};

struct fila {
    struct node *inicio;
    struct node *fim;
};

typedef struct node NODE;
typedef struct fila FILA;

void cleanBuf(void) {
    char c;
    while((c = getchar()) != '\n' && c != EOF);
}

FILA *criaFila(void) {
    FILA *f = (FILA *) malloc(sizeof(FILA));

    if (f != NULL) {
        f->inicio = NULL;
        f->fim = NULL;
    }
    return f;
}

void liberaFila(FILA *f) {

    if (f != NULL) {
        NODE*noAux;
        while (f->inicio != NULL) {
            noAux = f->inicio;
            f->inicio = f->inicio->prox;
            free(noAux);
        }
    }
    free(f);
}

int tamanhoFila(FILA *f) {
    int tam = 0;

    /* NODE*noAux = f->inicio;
     * while (noAux != NULL)
     * tam++;
     * noAux = no->prox;
    */
    while (f->inicio != NULL) {
        tam++;
        f->inicio = f->inicio->prox;
    }
    return tam;
}

int vaziaFila(FILA *f) {
    if (f == NULL || f->inicio == NULL)
        return 0; // ESTÁ VAZIA
    else
        return 1;
}

int enQueue(FILA *f, struct aluno al) {

    NODE *no = (NODE *) malloc(sizeof(NODE));
    no->dados = al;
    no->prox = NULL;
    if (no == NULL || f == NULL)
        return 1;
    
    if (f->fim == NULL) { //ANALISANDO SE A LISTA É VAZIA (NUMA FILA INSERE-SE AO FINAL)
        f->inicio = no;
        return 0;
    } else {
        f->fim->prox = no;
        f->fim = no;
        return 0;
        /* NODE *noAux;
        while (f->inicio != NULL) {
            noAux = f->inicio;
            f->inicio = f->inicio->prox;
        }
        noAux->prox = no; */
    }
}

int deQueue(FILA *f) {

    if (f == NULL || f->inicio == NULL)
        return 1;
    else {
        NODE *noAux = f->inicio;
        f->inicio = f->inicio->prox;

        if (f->inicio == NULL) //LISTA ESVAZIOU-SE
            f->fim = NULL;
        free(noAux);
        return 0;
    }
}

int exibeFila(NODE *no, struct aluno *al) {
    if (no == NULL)
        return 1;

    *al = no->dados;
    return 0;
}

int menu(void) {
    int opcao;

    printf("\n\n0. ENCERRAR PROGRAMA\n");
    printf("1. LIBERAR MEMORIA\n");
    printf("2. INSERIR NA FILA\n");
    printf("3. REMOVER DA FILA\n");
    printf("4. EXIBIR FILA\n");
    printf("OPCAO: ");
    scanf("%1d", &opcao);

    return opcao;
}

void dadosAl(struct aluno *al) {
    printf("\nINFORME OS DADOS DO ALUNO: \n");
    
    printf("NOME: ");
    cleanBuf();
    scanf("%[^\n]s", al->nome);
    cleanBuf();
    printf("MATRICULA: ");
    scanf("%d", &al->matricula);
    printf("\n");
}

void opcao(FILA *f, int op) {

    struct aluno al;
    int teste, count = 0;
    NODE *noAux;
    
    switch (op) {
    case 0:
        liberaFila(f);
        exit(0);
        break;
    case 1:
        liberaFila(f);
        break;
    case 2:
        dadosAl(&al);
        teste = enQueue(f, al);
        if (teste == 0)
            printf("INSERIDO!\n");
        else
            printf("NAO INSERIDO!\n");
        break;
    case 3:
        teste = deQueue(f);
        if (teste == 0)
            printf("REMOVIDO!\n");
        else
            printf("NAO REMOVIDO!\n");
        break;
    case 4:
        if (f->inicio == NULL) {
            printf("FILA VAZIA!\n");
            break;
        } else {
            al = f->inicio->dados;
            printf("%d. %s", count, al.nome);
        }   
        break;

    default:
        printf("OPCAO INVALIDA!\n");
        break;
    }
}
int main(void) {
    FILA *f = criaFila();
    int op;

    do    {
        op = menu();
        opcao(f, op);
    } while (op);
    
    free(f);
    return 0;
}