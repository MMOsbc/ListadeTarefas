#ifndef FUNCOES_H
#define FUNCOES_H

// type def do truck irá informar o que será permitido dentro dele e a
// quantidade de caracteres
typedef struct {
    int prioridade;
    char categoria[100];
    char descricao[300];
} Tarefa;
// define a quantidade maxima de tarefas
typedef struct {
    Tarefa tarefas[100];
    int qtd;
} ListaDeTarefas;
// assinatura das funções
void cadastrarTarefa(ListaDeTarefas *lt);
void listarTarefas(ListaDeTarefas lt);
void salvarTarefas(ListaDeTarefas lt, const char *arquivo);
void carregarTarefas(ListaDeTarefas *lt, const char *arquivo);

#endif

