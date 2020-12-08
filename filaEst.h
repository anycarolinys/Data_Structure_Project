#define MAX 50

struct aluno {
    int matricula;
    char nome[30];
    float media;
};

struct fila {
    int inicio, fim, qtd;
    struct aluno dados[MAX];
};

typedef struct fila FILA;

void cleanBuf(void);

FILA *criaFila(void);

void liberaFila(FILA *f);

int tamanho(FILA *f);


int enQueue(FILA *f, struct aluno al);

int deQueue(FILA *f);

int menu(void);

void dadosAl(struct aluno *al);

int exibeFila(FILA *f);

void opcao(FILA *f, int op);

