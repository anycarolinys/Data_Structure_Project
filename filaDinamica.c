#include <stdio.h>
#include <stdlib.h>

struct aluno {
    int matricula;
    char nome[50];
};

// Estrutura de um nó da fila
struct node {
    struct aluno dados;
    struct node *prox;
};

// Estrutura do primeiro e último nós da fila
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

// Adicionando nó do tipo 'aluno' na fila
int enQueue(FILA *f, struct aluno al) {

    NODE *no = (NODE *) malloc(sizeof(NODE));
    no->dados = al;
    no->prox = NULL;
    if (f == NULL || no == NULL) // FILA INVÁLIDA E ERRO AO ALOCAR NÓ
        return 1;
    
    if (f->inicio == NULL) { // FILA VAZIA
        f->inicio = no;
    } else {
        f->fim->prox = no;
    }
    f->fim = no;
    return 0;
}

int deQueue(FILA *f) {

    if (f == NULL || f->inicio == NULL) //FILA INVÁLIDA OU VAZIA
        return 1;
        
    NODE *noAux = f->inicio;
    // A REMOÇÃO CONSISTE NA LINHA SEGUINTE:
    f->inicio = f->inicio->prox;

    if (f->inicio == NULL) //LISTA ESVAZIOU-SE
        f->fim = NULL;

    free(noAux);
    return 0;
}

/* PARA UMA FILA SÓ É POSSÍVEL 
* CONSULTAR O PRIMEIRO NÓ, A LÓGICA DE
* CONSULTAR TODOS OS NÓS SERVE PARA UMA FILA */
int exibeFila(FILA *f, struct aluno *al) {
    if (f == NULL || f->inicio == NULL)
        return 1;

    *al = f->inicio->dados;
    return 0;
}

int menu(void) {
    int opcao;

    printf("\n\n0. ENCERRAR PROGRAMA\n");
    printf("1. LIBERAR MEMORIA\n");
    printf("2. INSERIR NA FILA\n");
    printf("3. REMOVER DA FILA\n");
    printf("4. EXIBIR PRIMEIRO NO\n");
    printf("OPCAO: ");
    scanf("%1d", &opcao);

    return opcao;
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
        dadosAluno(&al);
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
        exibeFila(f, &al);
        if (teste == 0)
            printf("1. %s", al.nome);
        else
            printf("LISTA VAZIA!\n");
        break;
    default:
        liberaFila(f);
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
    
    liberaFila(f);
    free(f);
    return 0;
}