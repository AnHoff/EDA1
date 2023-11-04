#include <stdio.h>
#include <stdlib.h>

// Definição da struct celula
typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

// Função para enfileirar (inserir) um elemento x na fila circular com nó cabeça f
void enfileira(celula **f, int x) {
    celula *novo = (celula *)malloc(sizeof(celula));
    if (novo == NULL) {
        fprintf(stderr, "Erro de alocação de memória ao enfileirar o elemento %d\n", x);
        exit(1);
    }

    novo->dado = x;

    if (*f == NULL) {
        // Se a fila estiver vazia, o novo nó será o único nó da fila
        novo->prox = novo;
        *f = novo;
    } else {
        // Conecta o novo nó ao último nó da fila e atualiza o nó cabeça
        novo->prox = (*f)->prox;
        (*f)->prox = novo;
        *f = novo;
    }
}

// Função para desenfileirar (remover) um elemento da fila circular
int desenfileira(celula *f, int *y) {
    if (f == NULL) {
        // A fila está vazia, não é possível desenfileirar
        return 0;
    }

    celula *removido = f->prox;

    if (removido == f) {
        // A fila tinha apenas um elemento
        *y = removido->dado;
        free(removido);
        f = NULL; // A fila fica vazia
    } else {
        // Remove o primeiro nó da fila e atualiza o nó cabeça
        *y = removido->dado;
        f->prox = removido->prox;
        free(removido);
    }

    return 1;
}

// int main() {
//     celula *minhaFila = NULL;

//     // Enfileirar elementos na fila
//     for (int i = 1; i <= 5; i++) {
//         enfileira(&minhaFila, i);
//     }

//     // Desenfileirar elementos da fila
//     int elemento;
//     while (desenfileira(minhaFila, &elemento)) {
//         printf("Elemento desenfileirado: %d\n", elemento);
//     }

//     return 0;
// }
