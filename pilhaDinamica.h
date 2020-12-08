struct aluno {
    char nome[30];
    int matricula;
};

struct node {
    struct aluno dados;
    struct node *prox;
};

typedef struct node NODE;
typedef struct node *PILHA;
