#include <stdio.h>

//ESTRUTURA DO TIPO LISTA
struct List {
    char caracter;
    struct List *ptrNext;
};

/*FUNÇÃO: RECEBE UM CARACTER E UMA STRUCT LISTA E RETORNA UMA STRUCT 'List' 
*/
struct List *findChar(char c, struct List *lConc) {
    
    while (lConc != NULL) {
        if(lConc->caracter == c)
        return lConc;
        else
        lConc = lConc->ptrNext;
    }
    
    return NULL;
}


int main(void) {
    struct List l1, l2, l3, l4, *hook, *result;
    //gancho = endereço da struct l1
    hook = &l1;
    l1.caracter = 'A';
    l1.ptrNext = &l2;
    
    l2.caracter = 'o';
    l2.ptrNext = &l3;

    l3.caracter = 'P';
    l3.ptrNext = &l4;

    l4.caracter = 't';
    l4.ptrNext = NULL;

    char cUser;
    printf("Informe um caracter: ");
    scanf("%c", &cUser);

    result = findChar(cUser, hook);

    if (result == NULL)
    //USANDO TABELA ASCII PARA IMPRIMIR
    printf("A letra %c n%co est%c nas Listas Concatenadas!", cUser, 198, 160);
    else 
    printf("A letra %c est%c nas Listas Concatenadas", result->caracter, 160);

    return 0;
}
