#include <stdio.h>

// Função para ordenação por inserção
void insertion_sort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move os elementos do arr[0..i-1] que são maiores que key
        // para uma posição à frente de sua posição atual
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    // Número máximo de elementos
    int max_elements = 50000;
    int numbers[max_elements];
    int n = 0;

    // Leitura da entrada padrão
    while (scanf("%d", &numbers[n]) != EOF) {
        n++;
        if (n == max_elements) {
            break; // Limite de elementos atingido
        }
    }

    // Chama a função de ordenação por inserção
    insertion_sort(numbers, n);

    // Imprime os números ordenados
    for (int i = 0; i < n; i++) {
        printf("%d", numbers[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }

    // Adiciona quebra de linha no final
    printf("\n");

    return 0;
}
