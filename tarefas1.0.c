#include <stdio.h>
#include <stdlib.h>
#include "tarefas1.0.h"
int main() {
// definição de variaveis
    ListaDeTarefas listaTarefas;
    listaTarefas.qtd = 0;
    int escolha;
//laço de repetição para passando as opções do menu
    while (1) {
        printf("\nEscolha uma opção:\n");
        printf("1. Cadastrar Tarefa\n");
        printf("2. Listar Tarefas\n");
        printf("3. Salvar Tarefas em Arquivo\n");
        printf("4. Carregar Tarefas de Arquivo\n");
        printf("5. Sair\n");
        printf("Digite o número da opção desejada: ");
// incluindo a opção escolhida na variavel escolha
        scanf("%d", &escolha);
// switch que de acordo com a variavel escolha define qual case irá executar
        switch (escolha) {
            case 1:
//case 1 cadastra as tarefas
                cadastrarTarefa(&listaTarefas);
                break;
            case 2:
// case 2 lista as tarefas existentes
                listarTarefas(listaTarefas);
                break;
            case 3:
// case 3 salva as tarefas no arquivo binario
                salvarTarefas(listaTarefas, "tarefas.bin");
                break;
            case 4:
// carregar as tarefas a partir do arquivo
                carregarTarefas(&listaTarefas, "tarefas.bin");
                break;
            case 5:
// case 5 sair do programa com return 0
                printf("Que pena que escolheu sair. Até breve!\n");
                return 0; // Encerra o programa
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }
}
