#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *v; // Vetor que representa a fila
    int N; // Tamanho da fila
    int inicio, fim; // Indicadores de início e final da fila
} fila;

// Função para enfileirar (inserir) um elemento x na fila circular
int enfileira(fila *f, int x) {
    if ((f->fim + 1) % f->N == f->inicio) {
        // A fila está cheia, não é possível enfileirar
        return 0;
    }

    f->v[f->fim] = x;
    f->fim = (f->fim + 1) % f->N;

    return 1;
}

// Função para desenfileirar (remover) um elemento da fila circular
int desenfileira(fila *f, int *y) {
    if (f->inicio == f->fim) {
        // A fila está vazia, não é possível desenfileirar
        return 0;
    }

    *y = f->v[f->inicio];
    f->inicio = (f->inicio + 1) % f->N;

    return 1;
}

// int main() {
//     fila minhaFila;
//     int tamanhoMaximo = 10; // Tamanho máximo da fila

//     minhaFila.v = (int *)malloc(tamanhoMaximo * sizeof(int));
//     minhaFila.N = tamanhoMaximo;
//     minhaFila.inicio = 0;
//     minhaFila.fim = 0;

//     // Enfileirar elementos na fila
//     for (int i = 1; i <= 10; i++) {
//         if (enfileira(&minhaFila, i)) {
//             printf("Elemento enfileirado: %d\n", i);
//         } else {
//             printf("Fila cheia, não foi possível enfileirar o elemento: %d\n", i);
//         }
//     }

//     // Desenfileirar elementos da fila
//     int elemento;
//     while (desenfileira(&minhaFila, &elemento)) {
//         printf("Elemento desenfileirado: %d\n", elemento);
//     }

//     free(minhaFila.v);

//     return 0;
// }
