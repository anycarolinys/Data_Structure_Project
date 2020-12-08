struct aluno {
    int matricula;
    char nome[30];
    float media;
};

struct node {
    struct aluno dados;
    struct node *prox;
};

typedef struct node NODE;
typedef struct node *LISTA;


