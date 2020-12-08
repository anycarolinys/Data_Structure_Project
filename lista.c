#include <stdio.h>

//CRIANDO LISTA GLOBAL
struct lista {
    int valor;
//'proximo' APONTA PARA EM UMA ESTRUTURA 'lista'
    struct lista *proximo;
};

int main(void) {

//DECLARANDO ESTRUTURAS 'lista'
    
    struct lista m1, m2, m3;

//DECLARANDO PONTEIRO PARA 'lista'
    struct lista *gancho;
    
    //RECEBE O ENDEREÇO DE UMA ESTRUTURA 'lista'
    gancho = &m1;

    m1.valor = 10;
    m1.proximo = &m2;

    m2.valor = 20;
    m2.proximo = &m3;

    m3.valor = 30;
//m3 ENCERRA O CICLO E APONTA PARA UM PONTEIRO NULO DE LISTA
    m3.proximo = (struct lista *)0;
    //m3.proximo = 0;


//ACESSANDO 'valor' DE m1, m2 e m3 POR MEIO DOS PONTEIROS
    /*printf("\nValor de M1 = %d", gancho->valor);
    printf("\nValor de M2 = %d", m1.proximo->valor);
    printf("\nValor de M3 = %d", m2.proximo->valor); */

/*ENQUANTO O ENDEREÇO DO PONTEIRO GANCHO FOR 
DIFERENTE DE NULO, PROSSIGA*/
    int i = 1;
    while(gancho != (struct lista *) 0) {
        printf("\nValor %d = %d", i, gancho->valor);
        i++;
//'gancho' PASSA  A APONTAR PARA A ESTRUTURA CONTIDA EM 'proximo'
        gancho = gancho->proximo;
    }
    return 0;
}