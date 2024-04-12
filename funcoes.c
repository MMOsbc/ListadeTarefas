#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cadastrarTarefa(ListaDeTarefas *lt) {
    // condição para verificar a quantidade de tarefas
    if (lt->qtd >= 100) {
        printf("A lista de tarefas está cheia. Não é possível cadastrar mais "
               "tarefas.\n");
        return;
    }
    // a condição a cima não foi "aceita" então cotinua o programa
    Tarefa novaTarefa;
    // prints com o que deseja e logo após armazena as infos nas variaveis
    printf("Prioridade da tarefa (0 a 10): ");
    scanf("%d", &novaTarefa.prioridade);
    // estava com problema em escrever e cada espaço adicionava uma tarefa, usando
    // [^/] resolve
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

// funcao para carregar as tarefas que já foram salvas no arquivo
void carregarTarefas(ListaDeTarefas *lt, const char *arquivo) {
    FILE *file = fopen(arquivo, "rb");
    // condição para achar o fim do arquivo
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de tarefas.\n");
        return;
    }

    // carrega a quantidade de funcoes dentro do arquivo
    fread(&(lt->qtd), sizeof(int), 1, file);
    // condição que verifica se tme mais de 100 tarefas no arquivo
    if (lt->qtd > 100) {
        printf("Erro: O número de tarefas no arquivo é maior do que o limite "
               "permitido.\n");
        fclose(file);
        return;
    }

    // le as tarefas do arquivo
    fread(lt->tarefas, sizeof(Tarefa), lt->qtd, file);
    // e por fim fecha o arquivo
    fclose(file);
    printf("Tarefas carregadas com sucesso a partir do arquivo: %s\n", arquivo);
}

void salvarTarefas(ListaDeTarefas lt, const char *arquivo) {
    FILE *file = fopen(arquivo, "wb");
    // abre o arquivo
    // faz a mesma verificação se possui ruim

    if (file == NULL) {
        printf("Erro ao abrir o arquivo para salvar tarefas.\n");
        return;
    }

    // escreve o numero de tarefas no arquivo
    fwrite(&(lt.qtd), sizeof(int), 1, file);

    // escreve as tarefas no arquivo
    fwrite(lt.tarefas, sizeof(Tarefa), lt.qtd, file);
    // fecha o arquivo
    fclose(file);
    printf("Tarefas salvas com sucesso no arquivo: %s\n", arquivo);
}
