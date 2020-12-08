#define MAX 100

struct aluno {
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

struct lista {
    int qtd;
    struct aluno dados[MAX];
};

typedef struct lista LISTA;


/* FUNÇÃO: Aloca dinamicamente um espaço para um ponteiro do tipo 'LISTA'
Retorna um ponteiro para LISTA, portanto, uma variável deve receber o retorno */
LISTA *cria(void);

/* FUNÇÃO: Libera memória alocada para uma lista
Sem retorno */
void libera(LISTA *li);

/* FUNÇÃO: Recebe um ponteiro para lista e retorna a quantidade de nós contidos na mesma */
int tamanhoLista(LISTA *li);

/* FUNÇÃO: Recebe um ponteiro para lista e retorna um valor simbólico
indicando se a lista possui a quantidade de nós máxima */
int listaCheia(LISTA *li);

/* FUNÇÃO: Recebe um ponteiro para lista e uma variável struct a ser inserida
ao final da lista, retorna um valor simbólico para indicar se houve inserção
ou não */
int insereFinal(LISTA *li, struct aluno al);

/* FUNÇÃO: Recebe um ponteiro para lista e uma variável struct a ser inserida
no início da lista, retorna um valor simbólico para indicar se houve inserção
ou não */
int insereInicio(LISTA *li, struct aluno al);

/* FUNÇÃO: Recebe um ponteiro para lista e uma variável struct a ser inserida
ordenadamente, isto é, de acordo com a matricula o elemento vai ser inserido 
em uma posição relativa na lista, portanto, esta função NÃO deve ser utilizada
para inserir um primeiro nó na lista */
int insereLista(LISTA *li, struct aluno al);

/* FUNÇÃO: Recebe um ponteiro para lista e diminui o tamanho da lista
removendo, assim, o último elemento, retorna um valor para verificar
a remoção de nó */
int removeFinal(LISTA *li);

/* FUNÇÃO: Remove o primeiro nó da lista deslocando todos os outros
para a posição antecessora, retona um valor para verificar a 
remoção de nó */
int removeInicio(LISTA *li);

/* FUNÇÃO: Recebe um ponteiro para lista e uma matrícula a ser consultada,
então, o nó correspondente à matrícula é removido.
Retorna um valor de verificação da remoção. */
int removeLista(LISTA *li, int matricula);

/* FUNÇÃO: Recebe um ponteiro para lista, uma posição válida na lista
e um ponteiro para struct, o qual receberá o conteúdo da posição correspondente.
Retorna um valor de verificação de consulta e passagem de dados*/
int consultaPosicao(LISTA *li, int pos, struct aluno *al);

/* FUNÇÃO: Recebe um ponteiro para lista, uma matrícula válida na lista
e um ponteiro para struct, o qual receberá o conteúdo da matrícula correspondente.
Retorna um valor de verificação de consulta e passagem de dados*/
int consultaMatricula(LISTA *li, int matricula, struct aluno *al);

