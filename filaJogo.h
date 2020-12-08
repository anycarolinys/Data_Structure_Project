struct jogador {
    char *nome;
};
typedef struct jogador j;
struct noFila {
    j gamer;
    struct noFila *prox; // Nó para o próximo elemento
};

typedef struct noFila no;

// Aloca memória para jogador
no *alocaJogador();
// Insere início 
void insereJogador(no *fila);
// Libera memória alocada pela fila
void liberaFila(no *fila);
