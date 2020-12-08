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

FILA *criaFila(void);

void liberaFila(FILA *f);

int tamanhoFila(FILA *f);

int vaziaFila(FILA *f);

int enQueue(FILA *f, struct aluno al);

int deQueue(FILA *f);

int exibeFila(FILA *f);

int menu(void);

void dadosAluno(struct aluno *al);

void opcao(FILA *f, int op);
