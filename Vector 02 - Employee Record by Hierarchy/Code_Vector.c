//Definir as Estruturas Necessárias
#include <stdio.h>
#include <string.h>

#define TAMANHO 21
#define TAM_GERENTES 7
#define TAM_ADMIN 7
#define TAM_TECNICOS 7

char* funcionarios[TAMANHO];
int indice_gerentes = 0, indice_admin = 7, indice_tecnicos = 14;
//  Função de Inserção
void inserir_funcionario(char* nome, int hierarquia) {
    if (hierarquia == 1 && indice_gerentes < TAM_GERENTES) {
        funcionarios[indice_gerentes++] = nome;
    } else if (hierarquia == 2 && indice_admin < TAM_ADMIN + 7) {
        funcionarios[indice_admin++] = nome;
    } else if (hierarquia == 3 && indice_tecnicos < TAM_TECNICOS + 14) {
        funcionarios[indice_tecnicos++] = nome;
    } else {
        printf("Erro: Hierarquia cheia.\n");
    }
}
//Função para Listar Funcionários por Hierarquia
void listar_por_hierarquia(int hierarquia) {
    if (hierarquia == 1) {
        printf("Gerentes:\n");
        for (int i = 0; i < TAM_GERENTES; i++) {
            if (funcionarios[i] != NULL) {
                printf("%s\n", funcionarios[i]);
            }
        }
    } else if (hierarquia == 2) {
        printf("Administrativos:\n");
        for (int i = 7; i < 14; i++) {
            if (funcionarios[i] != NULL) {
                printf("%s\n", funcionarios[i]);
            }
        }
    } else if (hierarquia == 3) {
        printf("Técnicos:\n");
        for (int i = 14; i < 21; i++) {
            if (funcionarios[i] != NULL) {
                printf("%s\n", funcionarios[i]);
            }
        }
    } else {
        printf("Hierarquia inválida.\n");
    }
}
//Função para Listar Todos os Servidores
void listar_todos() {
    listar_por_hierarquia(1);
    listar_por_hierarquia(2);
    listar_por_hierarquia(3);
}
//Função Principal
int main() {
    int opcao, hierarquia;
    char nome[50];

    while (1) {
        printf("\n1. Inserir Funcionario\n2. Listar por Hierarquia\n3. Listar Todos\n4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o nome: ");
                scanf("%s", nome);
                printf("Escolha a hierarquia (1-Gerentes, 2-Administrativos, 3-Tecnicos): ");
                scanf("%d", &hierarquia);
                inserir_funcionario(nome, hierarquia);
                break;
            case 2:
                printf("Escolha a hierarquia (1-Gerentes, 2-Administrativos, 3-Tecnicos): ");
                scanf("%d", &hierarquia);
                listar_por_hierarquia(hierarquia);
                break;
            case 3:
                listar_todos();
                break;
            case 4:
                return 0;
            default:
                printf("Opcao invalida!\n");
        }
    }

    return 0;
}