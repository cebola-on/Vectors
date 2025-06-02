#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

typedef struct {
    char nome[50];  // Nome do processo
    int tempo_execucao;  // Tempo de execução em segundos
} Processo;

Processo processos[10];
int total_processos = 0;

int main() {
    setlocale(LC_ALL, "pt_BR.utf8");
    int opcao;
    clock_t temp_inicial, temp_final;
    double tempo_decorrido;

    while (1) {
        // Menu de opções
        printf("Escolha uma opção:\n");
        printf("1. Adicionar um processo\n");
        printf("2. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        if (opcao == 2) {
            printf("Saindo do programa...\n");
            break;
        } else if (opcao == 1) {
            // Verifica se o limite de processos foi atingido
            if (total_processos >= 10) {
                printf("Número máximo de processos atingido!\n");
                continue;
            }

            // Solicita os dados do processo
            printf("Insira o nome do processo %d: ", total_processos + 1);
            scanf("%s", processos[total_processos].nome);
            printf("Insira o tempo de execução do processo %d (em segundos): ", total_processos + 1);
            scanf("%d", &processos[total_processos].tempo_execucao);

            total_processos++;
        } else {
            printf("Opção inválida! Tente novamente.\n");
        }
    }

    // Loop para simular a execução de cada processo
    for (int i = 0; i < total_processos; i++) {
        printf("Iniciando o processo %s...\n", processos[i].nome);

        // Cronometragem do processo individual
        temp_inicial = clock();
        do {
            temp_final = clock();
            tempo_decorrido = ((double)(temp_final - temp_inicial)) / CLOCKS_PER_SEC;
        } while (tempo_decorrido < processos[i].tempo_execucao);

        printf("Processo %s finalizado. Tempo de execução: %f segundos\n", processos[i].nome, tempo_decorrido);
    }

    printf("Todos os processos foram finalizados.\n");

    system("pause");
    return 0;
}

