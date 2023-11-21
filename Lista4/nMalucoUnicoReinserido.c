#include <stdio.h>
#include <stdlib.h>

// Funções merge e merge_sort para ordenar o vetor
void merge(int *array, int start, int middle, int end) {
    int *temp = malloc(sizeof(int) * (end - start));

    int i = start, j = middle, k = 0;

    while (i < middle && j < end)
        temp[k++] = array[i] <= array[j] ? array[i++] : array[j++];

    while (i < middle)
        temp[k++] = array[i++];
    while (j < end)
        temp[k++] = array[j++];

    for (i = start; i < end; i++)
        array[i] = temp[i - start];

    free(temp);
}

void merge_sort(int *array, int start, int end) {
    if (end - 1 <= start)
        return;

    int middle = start + (end - start) / 2;

    merge_sort(array, start, middle);
    merge_sort(array, middle, end);
    merge(array, start, middle, end);
}

// Função busca binária que retorna o índice do dado no vetor (caso exista) ou -1
int binary_search(int *array, int size, int data) {
    int low = 0, high = size;

    while (low < high) {
        int middle = low + (high - low) / 2;
        if (array[middle] == data)
            return middle;
        if (array[middle] > data)
            high = middle;
        else
            low = middle + 1;
    }

    return -1;
}

int main() {
    int size;
    scanf("%d", &size);
    int array[200000];

    for (int i = 0; i < size; i++)
        scanf("%d", &array[i]);

    // Ordenando os dados do vetor
    merge_sort(array, 0, size);

    // Eliminando índices repetidos
    int newIndex = 0;
    for (int i = 1; i < size; i++)
        if (array[newIndex] != array[i])
            array[++newIndex] = array[i];

    newIndex++;

    // Caso o tamanho do vetor novo seja ímpar, adicionar 1000000000 ao final
    if (newIndex % 2 != 0)
        array[newIndex++] = 1000000000;

    // Criando os números malucos únicos (somando os adjacentes) e os adicionando ao final do vetor
    int nmuIndex = newIndex;
    for (int i = 1; i < newIndex; i += 2) {
        array[nmuIndex] = array[i] + array[i - 1];

        // Verificando se o número obtido está presente no vetor (caso sim, remove do final do vetor)
        if (binary_search(array, newIndex, array[nmuIndex]) == -1)
            nmuIndex++;
    }

    // Reordenando o vetor com os números malucos únicos reinseridos
    merge_sort(array, 0, nmuIndex);

    // Imprimindo os dados do vetor de 4 em 4 índices
    for (int i = 0; i < nmuIndex; i += 4)
        printf("%d\n", array[i]);

    printf("Elementos: %d\n", nmuIndex);

    return 0;
}
