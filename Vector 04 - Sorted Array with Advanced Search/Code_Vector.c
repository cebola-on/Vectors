#include <stdio.h>

#define TAM 15

int vetor[TAM];
int n = 0; // Número atual de elementos no vetor

void inserir(int valor);
void remover(int valor);
int buscaTrinaria(int valor, int inicio, int fim);
int buscaExponencial(int valor);
int buscaBinaria(int valor, int inicio, int fim);

int main() {
    int opcao, valor;
    
    do {
        printf("1. Inserir\n2. Remover\n3. Busca Trinaria\n4. Busca Exponencial\n5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                printf("Digite o valor para inserir: ");
                scanf("%d", &valor);
                inserir(valor);
                break;
            case 2:
                printf("Digite o valor para remover: ");
                scanf("%d", &valor);
                remover(valor);
                break;
            case 3:
                printf("Digite o valor para buscar (trinaria): ");
                scanf("%d", &valor);
                if (buscaTrinaria(valor, 0, n-1) != -1)
                    printf("Valor encontrado.\n");
                else
                    printf("Valor nao encontrado.\n");
                break;
            case 4:
                printf("Digite o valor para buscar (exponencial): ");
                scanf("%d", &valor);
                if (buscaExponencial(valor) != -1)
                    printf("Valor encontrado.\n");
                else
                    printf("Valor nao encontrado.\n");
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while(opcao != 5);
    
    return 0;
}

// Função de inserção ordenada
void inserir(int valor) {
    if (n == TAM) {
        printf("Vetor cheio!\n");
        return;
    }
    
    // Garantir que o valor não está duplicado
    for (int i = 0; i < n; i++) {
        if (vetor[i] == valor) {
            printf("Valor duplicado!\n");
            return;
        }
    }

    // Encontrar a posição correta para inserir
    int i = n - 1;
    while (i >= 0 && vetor[i] > valor) {
        vetor[i + 1] = vetor[i]; // Desloca os elementos para a direita
        i--;
    }

    // Inserir o valor na posição correta
    vetor[i + 1] = valor;
    n++; // Aumenta o número de elementos no vetor
    printf("Valor inserido com sucesso.\n");
}

// Função de remoção
void remover(int valor) {
    if (n == 0) {
        printf("Vetor vazio!\n");
        return;
    }

    // Encontrar o valor a ser removido
    int pos = -1;
    for (int i = 0; i < n; i++) {
        if (vetor[i] == valor) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf("Valor nao encontrado!\n");
        return;
    }

    // Remover o valor e deslocar os elementos para a esquerda
    for (int i = pos; i < n - 1; i++) {
        vetor[i] = vetor[i + 1];
    }

    n--; // Diminui o número de elementos
    printf("Valor removido com sucesso.\n");
}

// Função de busca trinária
int buscaTrinaria(int valor, int inicio, int fim) {
    if (inicio > fim) {
        return -1; // Valor não encontrado
    }

    // Dividindo em três partes
    int terco1 = inicio + (fim - inicio) / 3;
    int terco2 = inicio + 2 * (fim - inicio) / 3;

    // Comparações com os terços
    if (vetor[terco1] == valor) {
        return terco1; // Valor encontrado
    } else if (vetor[terco2] == valor) {
        return terco2; // Valor encontrado
    }

    // Decidir em qual das três partes continuar a busca
    if (valor < vetor[terco1]) {
        return buscaTrinaria(valor, inicio, terco1 - 1); // Primeira parte
    } else if (valor > vetor[terco2]) {
        return buscaTrinaria(valor, terco2 + 1, fim); // Terceira parte
    } else {
        return buscaTrinaria(valor, terco1 + 1, terco2 - 1); // Segunda parte
    }
}

// Função de busca binária auxiliar
int buscaBinaria(int valor, int inicio, int fim) {
    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        
        if (vetor[meio] == valor) {
            return meio; // Valor encontrado
        } else if (vetor[meio] < valor) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    
    return -1; // Valor não encontrado
}

// Função de busca exponencial
int buscaExponencial(int valor) {
    if (vetor[0] == valor) {
        return 0; // Valor encontrado no primeiro elemento
    }

    int i = 1;
    // Encontrando o intervalo com potências de 2
    while (i < n && vetor[i] <= valor) {
        i *= 2;
    }

    // Realizar busca binária no intervalo encontrado
    return buscaBinaria(valor, i / 2, i < n ? i : n - 1);
}