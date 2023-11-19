#include <stdio.h>

// Função para trocar dois elementos
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Função para ordenação por seleção
void selection_sort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        // Encontra o índice do menor elemento no restante do array
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Troca o menor elemento com o primeiro elemento não ordenado
        swap(&arr[min_idx], &arr[i]);
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

    // Chama a função de ordenação por seleção
    selection_sort(numbers, n);

    // Imprime os números ordenados
    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }

    // Adiciona quebra de linha no final
    printf("\n");

    return 0;
}
