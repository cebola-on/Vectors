#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
// #include <unistd.h> // sleep() não é padrão do C, system("pause") ou getchar() são mais portáveis para espera

#define CAPACIDADE_MAXIMA 20

// Estrutura do cliente
typedef struct {
    char nome[50]; // Aumentado para nomes maiores
    int idade;
} Cliente;

// Função para inserir um novo cliente (Novo atendimento)
void novoAtendimento(Cliente fila[], int *totalClientes) {
    if (*totalClientes >= CAPACIDADE_MAXIMA) {
        printf("\n--- Erro: A fila esta cheia! Nao e possivel adicionar mais clientes. ---\n");
        return;
    }

    Cliente novoCliente;
    printf("\n--- NOVO ATENDIMENTO ---\n");
    printf("Insira o nome do cliente: ");
    scanf("%49s", novoCliente.nome); // Limita a leitura para evitar overflow
    printf("Insira a idade do cliente: ");
    scanf("%d", &novoCliente.idade);

    if (novoCliente.idade >= 60) { // Cliente idoso
        int posicaoInsercao = 0;
        // Encontra a posição após o último idoso
        for (int i = 0; i < *totalClientes; i++) {
            if (fila[i].idade >= 60) {
                posicaoInsercao = i + 1;
            }
        }
        // Desloca os elementos para abrir espaço para o novo idoso
        for (int i = *totalClientes; i > posicaoInsercao; i--) {
            fila[i] = fila[i - 1];
        }
        fila[posicaoInsercao] = novoCliente;
    } else { // Cliente não idoso
        fila[*totalClientes] = novoCliente; // Adiciona no final da fila
    }
    (*totalClientes)++;
    printf("\nCliente %s adicionado a fila.\n", novoCliente.nome);
}

// Função para atender o próximo cliente (Atendimento realizado)
void atendimentoRealizado(Cliente fila[], int *totalClientes) {
    if (*totalClientes <= 0) {
        printf("\n --- Erro: Nao existem clientes na fila para serem atendidos! --- \n");
        return;
    }

    printf("\n--- ATENDIMENTO REALIZADO ---\n");
    printf("Atendendo cliente: Nome = %s, Idade = %d anos\n", fila[0].nome, fila[0].idade);

    // Desloca os clientes restantes para frente
    for (int i = 0; i < *totalClientes - 1; i++) {
        fila[i] = fila[i + 1];
    }
    (*totalClientes)--;

    if (*totalClientes == 0) {
        printf("\nTodos os clientes foram atendidos. A fila esta vazia.\n");
    }
}

// Função para listar todos os indivíduos na fila
void listarIndividuos(Cliente fila[], int totalClientes) {
    printf("\n--- FILA DE ATENDIMENTO ATUAL ---\n");
    if (totalClientes == 0) {
        printf("A fila esta vazia.\n");
        return;
    }
    for (int i = 0; i < totalClientes; i++) {
        printf("Posicao %d: Nome = %s, Idade = %d anos\n", i + 1, fila[i].nome, fila[i].idade);
    }
}

int main() {
    setlocale(LC_ALL, "pt_BR.utf8");
    Cliente filaDeClientes[CAPACIDADE_MAXIMA];
    int totalClientesNaFila = 0;
    int opcao;

    do {
        printf("\n--- MENU DE ATENDIMENTO HOSPITALAR ---\n");
        printf("1. Novo atendimento\n");
        printf("2. Atendimento realizado\n");
        printf("3. Listar individuos na fila\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        
        if (scanf("%d", &opcao) != 1) {
            printf("\nEntrada invalida. Por favor, insira um numero.\n");
            // Limpar o buffer de entrada
            while (getchar() != '\n');
            opcao = 0; // Define uma opção inválida para continuar no loop do menu
            continue;
        }

        switch (opcao) {
            case 1:
                novoAtendimento(filaDeClientes, &totalClientesNaFila);
                break;
            case 2:
                atendimentoRealizado(filaDeClientes, &totalClientesNaFila);
                break;
            case 3:
                listarIndividuos(filaDeClientes, totalClientesNaFila);
                break;
            case 4:
                printf("\nEncerrando o programa. Obrigado!\n");
                break;
            default:
                printf("\nOpcao invalida. Tente novamente.\n");
        }
        // Pequena pausa para o usuário ler a saída antes de reimprimir o menu
        // Apenas se não for a opção de sair
        if (opcao != 4) {
             printf("\nPressione Enter para continuar...");
             // Limpa o buffer de entrada antes de esperar pelo Enter
             // Especialmente importante após scanf("%d") se o próximo input for char/string
             // ou para garantir que o Enter da seleção da opção não seja consumido aqui
             int c;
             while ((c = getchar()) != '\n' && c != EOF);
             getchar(); // Espera pelo Enter
        }

    } while (opcao != 4);

    // system("pause"); // Mais comum em Windows, mas getchar() é mais portável
    return 0;
}
