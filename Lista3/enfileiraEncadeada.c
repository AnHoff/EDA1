#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

celula *enfileira(celula *f, int x) {
    // Cria um novo nó com o elemento x
    celula *novo = (celula *)malloc(sizeof(celula));
    if (novo == NULL) {
        fprintf(stderr, "Erro de alocação de memória ao enfileirar o elemento %d\n", x);
        return NULL;
    }

    novo->dado = x;
    novo->prox = NULL;

    if (f == NULL) {
        // Se a fila estiver vazia, o novo nó será o único nó da fila
        return novo;
    }

    // Encontra o último nó da fila
    celula *atual = f;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }

    // Conecta o novo nó ao último nó da fila
    atual->prox = novo;

    return f; // Retorna o mesmo nó cabeça da fila
}

// int main() {
//     celula *minhaFila = NULL;

//     // Enfileirar elementos na fila
//     for (int i = 1; i <= 5; i++) {
//         minhaFila = enfileira(minhaFila, i);
//         if (minhaFila != NULL) {
//             printf("Elemento enfileirado: %d\n", i);
//         } else {
//             printf("Erro ao enfileirar o elemento: %d\n", i);
//         }
//     }

//     // Liberar a memória alocada para a fila (liberar todos os nós da lista)
//     while (minhaFila != NULL) {
//         celula *temp = minhaFila;
//         minhaFila = minhaFila->prox;
//         free(temp);
//     }

//     return 0;
// }
