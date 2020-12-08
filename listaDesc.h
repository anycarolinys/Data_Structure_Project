struct aluno {
    int matricula;
    char nome[30];
    float media;
};

struct elem {
    struct aluno dados;
    struct elem *prox;
};

struct descritor {
    struct elem *inicio;
    struct elem *final;
    int qtd;
};

typedef struct elem NODE;
typedef struct descritor LISTA;