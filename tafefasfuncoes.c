#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tarefas1.0.h"

void cadastrarTarefa(ListaDeTarefas *lt) {
    // condição para verificar a quantidade de tarefas
    if (lt->qtd >= 100) {
        printf("A lista de tarefas está cheia. Não é possível cadastrar mais tarefas.\n");
        return;
    }
// a condição a cima não foi "aceita" então cotinua o programa
    Tarefa novaTarefa;
// prints com o que deseja e logo após armazena as infos nas variaveis
    printf("Prioridade da tarefa (0 a 10): ");
    scanf("%d", &novaTarefa.prioridade);
 // estava com problema em escrever e cada espaço adicionava uma tarefa, usando [^/] resolve
    printf("Categoria da tarefa (até 100 caracteres): ");
    scanf(" %99[^\n]", novaTarefa.categoria);

    printf("Descrição da tarefa (até 300 caracteres): ");
    scanf(" %299[^\n]", novaTarefa.descricao);
// ponteiro para adicionar a tarefa, também atualizar a quantidade
    lt->tarefas[lt->qtd] = novaTarefa;
    lt->qtd++;

    printf("Tarefa cadastrada com sucesso!\n");
}

void listarTarefas(ListaDeTarefas lt) {

    // condição para verificar se possui pelo menos uma tarefa
    if (lt.qtd == 0) {
        printf("A lista de tarefas está vazia.\n");
        return;
    }
    // condição não sendo completa continua o programa
    printf("Lista de Tarefas:\n");
    // laço de repetição para interar pelo struct para listar todas as tarefas
    for (int i = 0; i < lt.qtd; i++) {
        printf("Tarefa %d:\n", i + 1);
        printf("Prioridade: %d\n", lt.tarefas[i].prioridade);
        printf("Categoria: %s\n", lt.tarefas[i].categoria);
        printf("Descrição: %s\n", lt.tarefas[i].descricao);
        printf("\n");
    }
}

