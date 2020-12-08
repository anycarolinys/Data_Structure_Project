struct aluno {
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

struct node {
    struct node *ant;
    struct node *prox;
    struct aluno dados;
};

typedef struct node NODE;
typedef struct node *LISTA;

//DECLARANDO UM PONTEIRO PARA PONTEIRO
LISTA *li;

LISTA *cria(void);

int tamanho(LISTA *li);

int insereInicio(LISTA *li, struct aluno al);

int insereFim(LISTA *li, struct aluno al);

int insereLi(LISTA *li, struct aluno al);

int removeInicio(LISTA *li);

int removeFinal(LISTA *li);

int removeLi(LISTA *li, int matricula);

int consultaPos(LISTA *li, int pos, struct aluno *al);

int consultaMat (LISTA *li, int matricula, struct aluno *al);