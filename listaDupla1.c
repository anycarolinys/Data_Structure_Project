/* NESSE PROJETO SERÁ TRABALHADO O CONCEITO DE 'PONTEIRO PARA PONTEIRO'
ASSIM, COMO O TIPO 'LISTA' FOI DECLARADO COMO UM PONTEIRO E 'li'
É PONTEIRO PARA 'LISTA', ENTÃO, AO USAR 'li' DENOTA-SE UM PONTEIRO PARA PONTEIRO
E AO USAR '*li' DENOTA-SE O CONTEÚDO DO PONTEIRO 'li'
*/
#include <stdio.h>
#include <stdlib.h>
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


void cleanBuf(void) {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

LISTA *cria(void) {
    LISTA *li;
    li = (LISTA *) malloc(sizeof(LISTA));

    //SE A LISTA FOR REALMENTE ALOCADA
    if (li != NULL)
        *li = NULL;
    
    return li;
}

void libera(LISTA *li) {
    NODE *no; //PONTEIRO AUXILIAR
    
    if (li != NULL) {
        while ((*li) != NULL) {
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
        printf("MEMORIA LIBERADA!\n");
    }
}

int tamanho(LISTA *li) {
    int tam = 0;
    
    NODE *no = *li;

    while ((*li) != NULL) {
        tam++;
        no = no->prox;
    }
    
    return tam;
}

int vazia(LISTA *li) {
    if (*li == NULL) {//ESTÁ VAZIA
        return 0; //TRUE
    } else
        return 1; //FALSE
}

int insereInicio(LISTA *li, struct aluno al) {
    
    if (li == NULL)
        return 1;

    NODE *no;
    no = (NODE *) malloc(sizeof(NODE));

    //SE O NÓ NÃO FOI ALOCADO
    if (no == NULL) 
        return 1;

    no->dados = al;
    no->ant = NULL;
    no->prox = (*li);
    
    if ((*li) != NULL)
        (*li)->ant = no;
    
    (*li) = no;
    return 0;
}


int insereFim(LISTA *li, struct aluno al) {
    if (li == NULL)
        return 1;

    NODE *no = (NODE *) malloc(sizeof(NODE));

    if (no == NULL) 
        return 1;

    no->prox = NULL;
    no->dados = al;

    if ((*li) == NULL) {
        no->ant = NULL;
        (*li) = no;
    } else {
        NODE *aux = *li;
        while (aux->prox != NULL)
            aux = aux->prox;

        aux->prox = no;
        no->ant = aux;
    }
    return 0;
}
/***ESTA FUNÇÃO DEVE SER USADA APENAS PARA INSERIR ORDENADAMENTE
 * DE ACORDO COM A MATRÍCULA INFORMADA***/
int insereLi(LISTA *li, struct aluno al) {
    

    if (li == NULL)
        return 1;
    NODE *no = (NODE *) malloc(sizeof(NODE));

    if (no == NULL)
        return 1;

    no->dados = al;

    if (vazia(li)) {
        no->ant = NULL;
        no->prox = NULL;
        *li = no;
        return 0;
    } else {
        NODE *ante, *atual;
        atual = *li; // RECEBE O CONTEÚDO DA LISTA

        while (atual != NULL && atual->dados.matricula < al.matricula) {
                ante = atual;
                atual = atual->prox; //PERCORRENDO A LISTA
            }

        /* SE A LISTA NÃO FOR PERCORRIDA,
        ENTÃO É UMA INSERÇÃO NO INÍCIO */
        if (atual == (*li)) {
            no->ant = NULL;
            (*li)->ant = no;
            no->prox = (*li); //O VALOR QUE INICIAVA A LISTA AGORA APONTA PRA NÓ
            *li = no; //O PRIMEIRO ELEMENTO PASSA A SER 'no'
        } else {
            no->prox = ante->prox; //'ante->prox' representa o nó que vem após 'ante'
            no->ant = ante;
            ante->prox = no;
                if (atual != NULL) //SE O 'atual' FOR DIFERENTE DE NULL NÃO FOI PERCORRIDO ATÉ O FIM DA LISTA
                    atual->ant = no;
        }
        return 0;
    }
}

/***ESTA FUNÇÃO DEVE SER USADA APENAS PARA INSERIR ORDENADAMENTE
 * DE ACORDO COM A MATRÍCULA INFORMADA***/
int removeInicio(LISTA *li) {

    if (li == NULL)
        return 1;

    if ((*li) == NULL)
        return 1;

    NODE *no = *li; //RECEBE O CONTEÚDO DO 1º NÓ 
    (*li) = no->prox; /* O 1º NÓ PASSA A SER O 'prox', 
    ISTO É, O SUCESSOR DO 1º VALOR ORIGINAL */
    
// QUANDO SE FAZ 'no->prox' TRATA-SE DO SEGUNDO NÓ
    if (no->prox != NULL)
        no->prox->ant = NULL;
// ESSA LINHA É NECESSÁRIA POIS O 1º E O ÚLTIMO ELEMENTO DA LISTA DUP ENCADEADA APONTAM PARA 'NULL'
    free(no);
    return 0;    
}

int removeFinal(LISTA *li) {

    if (li == NULL)
        return 1;

    NODE *no = *li;

    while (no->prox != NULL) //ENQUANTO NÃO CHEGOU O FIM DA LISTA
        no = no->prox;

    // SE O NÓ ANTERIOR É 'NULL', ENTÃO, SÓ HÁ UM ÚNICO NÓ NA LISTA
    if (no->ant == NULL)
        *li = no->prox; //O CONTEÚDO DA LISTA PASSA A SER NULL, ISTO É, VAZIA
    else
        no->ant->prox = NULL;
    
    free(no);
    return 0;
}

int removeLi(LISTA *li, int matricula) {

    if (li == NULL)
        return 1;

    NODE *no = *li;

    while (no != NULL && no->dados.matricula != matricula) {
        no = no->prox;
    }

    if (no == NULL) 
        return 1;
    //SE A LISTA NÃO FOI PERCORRIDA
    else if (no->ant == NULL)
        *li = no->prox; //'no->prox' SIGNIFICA NULL
    else
        no->ant->prox = no->prox;
    
    if (no->prox != NULL) {
        no->prox->ant = no->ant;
    }
    
    free(no);
    return 0;

}

/* MINHA VERSÃO DA FUNÇÃO ANTERIOR */
int removeLista(LISTA *li, int matricula) {

    if (li == NULL)
        return 1;

    NODE *atual, *ante;
    atual = (*li);

    while (atual != NULL && atual->dados.matricula != matricula) {
        ante = atual;
        atual = atual->prox;
    }

    atual->prox->ant = atual->ant;
    ante->prox = atual->prox;
    return 0;
}


int consultaPos(LISTA *li, int pos, struct aluno *al) {

    if (li == NULL && pos <= 0)
        return 1;
    
    NODE *noAux = *li;
    int k = 1;

    while (noAux->prox != NULL && k < pos) {
        noAux = noAux->prox;
        k++;
    }
    
    if (noAux == NULL) {
        return 1;
    } else {
        (*al) = noAux->dados;
        return 0;
    }
}

int consultaMat (LISTA *li, int matricula, struct aluno *al) {
    if (li == NULL)
        return 1;
    
    NODE *noAux = *li;

    while (noAux->prox != NULL && noAux->dados.matricula != matricula) {
        noAux = noAux->prox;
    }
        
    if (noAux == NULL)
        return 1;
    else {
        *al = noAux->dados;
        return 0;
    }
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

void dadosAl(struct aluno *al) {
    printf("\nINFORME OS DADOS DO ALUNO: \n");
    printf("MATRICULA: ");
    scanf("%d", &al->matricula);
    cleanBuf();
    printf("NOME: ");
    scanf("%[^\n]s", al->nome);
    cleanBuf();
    printf("NOTA 1: ");
    scanf("%f", &al->n1);
    printf("NOTA 2: ");
    scanf("%f", &al->n2);
    printf("NOTA 3: ");
    scanf("%f", &al->n3);
    printf("\n");
}

void opcao(int op, LISTA *li) {
    
    int teste, matr, pos;
    struct aluno al;

    switch (op) {
    case 1:
        libera(li);
        break;
    case 2: 
        dadosAl(&al);
        teste = insereLi(li, al);
        if (teste == 0)
            printf("INSERIDO!\n");
        else
            printf("NAO INSERIDO!\n");
        break;
    case 3:
        dadosAl(&al);
        teste = insereInicio(li, al);
        if (teste == 0)
            printf("INSERIDO!\n");
        else
            printf("NAO INSERIDO!\n");
        break;
    case 4:
        dadosAl(&al);
        teste = insereFim(li, al);
        if (teste == 0)
            printf("INSERIDO!\n");
        else
            printf("NAO INSERIDO!\n");
        break;
    case 5:
        printf("MATRICULA: ");
        scanf("%d", &matr);
        teste = removeLi(li, matr);
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
        scanf("%d", &matr);
        teste = consultaMat(li, matr, &al);
        if (teste == 0)
            printf("ALUNA(O): %s\n", al.nome);
        else
            printf("ALUNA(O) NAO ENCONTRADO!\n");
        break;
    case 9:
        printf("POSICAO: ");
        scanf("%d", &pos);
        teste = consultaPos(li, pos, &al);
        if (teste == 0)
            printf("ALUNA(O): %s\n", al.nome);
        else
            printf("ALUNA(O) NAO ENCONTRADO!\n");
        break;
    default:
        printf("OPCAO INVALIDA!\n");
        break;
    }
}
int main(void) {

    LISTA *list;
    list = (LISTA *) malloc(sizeof(list));

    int op;

    do {
        op = menu();
        opcao(op, list);
    } while (op);
    
    free(list);
    return 0;
}