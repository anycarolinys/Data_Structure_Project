#include <stdio.h>
#include <stdlib.h>
#include "listaCirc.h"

void cleanBuf(void) {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}
LISTA *criaLista(void) {
    LISTA *li = (LISTA *) malloc(sizeof(LISTA));
    if (li != NULL)
        *li = NULL; //INICIALIZANDO A LISTA
    return li;
}

void liberaLista(LISTA *li) {
    
    if (li != NULL && (*li) != NULL) {
    NODE *aux, *no = *li; // NÓS AUXILIARES

/*** ENQUANTO O PRÓXIMO ELEMENTO FOR
 * DIFERENTE DO 1º ELEMENTO DA LISTA...
 * É USADA ESSA NOTAÇÃO PQ CONSISTE EM
 * UMA LISTA CIRCULAR ***/
    while ((*li) != no->prox) {
        aux = no;
        no = no->prox;
        free(aux);
    }

    free(no);
    free(li);
    }
}

int tamanho(LISTA *li) {
    int tam = 0;

    NODE *aux = *li;
//OU 'while (aux != (*li))'
    while (aux != (*li)) {
        tam++;
        aux = aux->prox;
    }
    return tam;
}

int listaVazia (LISTA *li) {
// SE A LISTA FOR INVÁLIDA E VAZIA, RETORNE TRUE    
    if (li == NULL && (*li) == NULL)
        return 0;
    else
        return 1;
}

int insereInicio (LISTA *li, struct aluno al) {
// TESTE PARA LISTA INVÁLIDA
    if (li == NULL)
        return 1;
    
    NODE *no = (NODE *) malloc(sizeof(NODE));
    if (no == NULL)
        return 1;
    no->dados = al;
        if ((*li) == NULL) {
            no->prox = no;
            *li = no;
        } else {
            NODE *aux = (*li);

            while (aux->prox != (*li)) {
                aux = aux->prox;
            }
            aux->prox = no; // O ÚLTIMO ELEMENTO APONTA PARA 'no'
            no->prox = *li; // O CONTEÚDO DA LISTA VEM APÓS 'no'
            *li = no; // O INÍCIO DA LISTA PASSA A SER 'no'
        }
    return 0;
}

int insereFim(LISTA *li, struct aluno al) {
    if (li == NULL)
        return 1;
    NODE *no = (NODE *) malloc(sizeof(NODE));
    if (no == NULL)
        return 1;
    no->dados = al;
    
    if ((*li) == NULL) {
        no->prox = no;
        *li = no;
    } else {
        NODE *aux = (*li);

        while (aux->prox != (*li)) {
            aux = aux->prox;
        }
// É O MESMO PROCESSO DA INSERÇÃO NO INÍCIO EXCETO PELA ÚTLIMA LINHA
        aux->prox = no;
        no->prox = *li;
    }
    return 0;
}

int insereOrd(LISTA *li, struct aluno al) {
    if (li == NULL)
        return 1;
    
    NODE *no = (NODE *) malloc(sizeof(NODE));

    if (no == NULL)
        return 1;
    no->dados = al;

    NODE *aux = *li;
    if ((*li) == NULL) { //INSERÇÃO NO INÍCIO
        *li = no;
        no->prox = no;
    } else {

/*** TESTANDO SE A MATRÍCULA REPRESENTA O
 * PRIMEIRO ALUNO ORDENADAMENTE PARA O
 * CASO DE REALIZAR UMA INSERÇÃO NO INÍCIO */
        if (al.matricula > (*li)->dados.matricula ) {
            while (aux->prox != (*li)) {
                aux = aux->prox;
            }
            aux->prox = no;
            no->prox = *li;
            *li = no;
            return 0;
        }
        /* SOLUÇÃO ALTERNATIVA PARA O BLOCO SEGUINTE
        NODE *ante = *li, *atual = (*li)->prox;
        while (atual != (*li) && atual->dados.matricula < al.matricula) {
            ante = atual;
            atual = atual->prox;
        }
        ante->prox = no;
        no->prox = atual;
        ***/
        while (no->prox != (*li) && aux->dados.matricula < al.matricula) 
            aux = aux->prox;
        
        aux->prox = no;
        no->prox = aux->prox;
    }
    return 0;
}

int removeInicio(LISTA *li) {
    if (li == NULL || (*li) == NULL) // LISTA INVÁLIDA OU VAZIA
        return 1;
    
// VERIFICANDO SE A LISTA CONTÉM UM ÚNICO ELEMENTO
    if ((*li) == (*li)->prox) {
        free(*li);
        *li = NULL;
        return 0;
    }

// PARA ALTERAR O CONTEÚDO DA LISTA OU PERCORRÊ-LA É NECESSÁRIO CRIAR NÓS AUXILIARES
    NODE *aux = *li;

    while (aux->prox != (*li))
        aux = aux->prox;

    NODE *no = *li;
    aux->prox = no->prox; //O ÚLTIMO NÓ APONTA PARA O SEGUNDO NÓ DA LISTA
    (*li) = no->prox; // O CONTEÚDO DO SEGUNDO NÓ É REALOCADO PARA O INÍCIO DA LISTA
    //(*li) = (*li)->prox ***INVÁLIDO***
    free(no); // LIBERANDO MEMÓRIA DO PRIMEIRO NÓ ÓRIGINAL
    return 0;
}

int removeFim(LISTA *li) {
    if (li == NULL || (*li) == NULL) // LISTA INVÁLIDA OU VAZIA
        return 1;
    
    if ((*li) == (*li)->prox) {// HÁ APENAS UM NÓ NA LISTA
        free(li);
        *li = NULL;
        return 0;
    }
    
    /* SOLUÇÃO ALTERNATIVA PARA O BLOCO SEGUINTE
    NODE *ante, *no = *li;
    while (no->prox != *li) {
        ante = no;
        no = no->prox;
    }
    ante->prox = no->prox;
    free(no);
    return 0;
    */
    NODE *ante = *li, *atual;

    while (atual != (*li)) {
        ante = atual;
        atual = atual->prox;
    }
    ante->prox = (*li);
    free(atual);
    atual = NULL;
    return 0;
}

int removeMat(LISTA *li, int matricula) {
    if (li == NULL || (*li) == NULL)
        return 1;

// SE A LISTA POSSUI UM ÚNICO ELEMENTO E ESTE POSSUI A MATRÍCULA INFORMADA
    if ((*li) == (*li)->prox && matricula == (*li)->dados.matricula) {
        free(li);
        (*li) = NULL;
        return 0;
    }
    
    NODE *ante, *aux = *li;

    while (aux != (*li) && (aux->dados.matricula != matricula)) {
        ante = aux;
        aux = aux->prox;
    }

    if (aux == (*li)) // ELEMENTO NÃO ENCONTRADO
        return 1;
    else {
        ante->prox = aux->prox;
        free(aux);
        return 0;
    }
}

int consultaPos(LISTA *li, int pos, struct aluno *al) {

    if (li == NULL || (*li) == NULL)
        return 1;
    
    int k = 1;
    NODE *aux = *li;
    while (aux->prox != (*li) && k < pos ) {
        aux = aux->prox;
        k++;
    }
    
    if (k != pos)
        return 1;
    else 
        *al = aux->dados;
        return 0;
}

int consultaMat(LISTA *li, int matricula, struct aluno *al) {
    if (li == NULL || (*li) == NULL)
        return 1;
    
    NODE *no = *li;

    while (no->prox != (*li) && no->dados.matricula != matricula)
        no = no->prox;

    if (no->dados.matricula != matricula)
        return 1;
    else {
        *al = no->dados;
        return 0;
    }
}


int menu(void) {
    int opcao;

    printf("\n\n1. LIBERAR MEMORIA\n");
    printf("2. INSERIR AO INICIO\n");
    printf("3. INSERIR  AO FINAL\n");
    printf("4. INSERIR POR MATRICULA\n");
    printf("5. REMOVER DO INICIO\n");
    printf("6. REMOVER DO FINAL\n");
    printf("7. REMOVER POR MATRICULA\n");
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
    printf("MEDIA: ");
    scanf("%f", &al->media);
    printf("\n");
}

void opcao(int op, LISTA *li) {
    
    int teste, matr, pos;
    struct aluno al;

    switch (op) {
    case 1:
        liberaLista(li);
        break;
    case 2:
        dadosAl(&al);
        teste = insereInicio(li, al);
        if (teste == 0)
            printf("INSERIDO!\n");
        else
            printf("NAO INSERIDO!\n");
        break;
    case 3:
        dadosAl(&al);
        teste = insereFim(li, al);
        if (teste == 0)
            printf("INSERIDO!\n");
        else
            printf("NAO INSERIDO!\n");
        break;
    case 4:
        dadosAl(&al);
        teste = insereOrd(li, al);
        if (teste == 0)
            printf("INSERIDO!\n");
        else
            printf("NAO INSERIDO!\n");
        break;
    case 5: 
        teste = removeInicio(li);
        if (teste == 0)
            printf("REMOVIDO!\n");
        else
            printf("NAO REMOVIDO!\n");
        break;
    case 6:
        teste = removeFim(li);
        if (teste == 0)
            printf("REMOVIDO!\n");
        else
            printf("NAO REMOVIDO!\n");
        break;
    case 7:
        printf("MATRICULA: ");
        scanf("%d", &matr);
        teste = removeMat(li, matr);
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

//OBS.: TESTAR AS SOLUÇÕES ALTERNATIVAS insereOrd E removeFim
int main(void) {
    LISTA *lista;
    lista = (LISTA *) malloc(sizeof(LISTA));

    int op;

    do {
        op = menu();
        opcao(op, lista);
    } while (op);
    
    free(lista);
    return 0;
}