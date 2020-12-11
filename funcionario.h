struct funcionario {
    int ID;
    struct funcionario *prox; // Ponteiro para o próximo funcionário   
};

typedef struct funcionario NO; // Um nó representa um funcionário
typedef struct funcionario *LISTA; // Um ponteiro para nó representa uma lista de funcionários

int addFuncionario(LISTA *li);
void liberaFunc(LISTA *li);