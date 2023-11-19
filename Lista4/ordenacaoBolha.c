#include <stdio.h>

// Função para trocar dois elementos
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Função para ordenação bolha
void bubble_sort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        // Últimos i elementos já estão ordenados
        for (j = 0; j < n-i-1; j++) {
            // Troca se o elemento encontrado for maior que o próximo elemento
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main() {
    // Número máximo de elementos
    int max_elements = 1000;
    int numbers[max_elements];
    int n = 0;

    // Leitura da entrada padrão
    while (scanf("%d", &numbers[n]) != EOF) {
        n++;
        if (n == max_elements) {
            break; // Limite de elementos atingido
        }
    }

    // Chama a função de ordenação bolha
    bubble_sort(numbers, n);

    // Imprime os números ordenados
    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }

    // Adiciona quebra de linha no final
    printf("\n");

    return 0;
}
