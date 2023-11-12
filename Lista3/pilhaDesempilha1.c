#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

int desempilha(celula *p, int *y) {
    if (p == NULL || p->prox == NULL) {
        // Pilha vazia
        return 0;
    }

    celula *temp = p->prox;  // Aponta para o primeiro elemento da pilha
    *y = temp->dado;        // Salva o dado a ser removido

    p->prox = temp->prox;    // Atualiza o ponteiro do nó cabeça para o próximo elemento
    free(temp);              // Libera o nó removido da memória

    return 1;                // Remoção bem-sucedida
}

// int main() {
//     celula *pilha = (celula *)malloc(sizeof(celula));
//     pilha->prox = NULL;

//     for (int i = 1; i <= 5; i++) {
//         celula *novo = (celula *)malloc(sizeof(celula));
//         novo->dado = i;
//         novo->prox = pilha->prox;
//         pilha->prox = novo;
//     }

//     int elemento_removido;
//     if (desempilha(pilha, &elemento_removido)) {
//         printf("Elemento removido: %d\n", elemento_removido);
//     } else {
//         printf("A pilha está vazia.\n");
//     }

//     while (pilha->prox != NULL) {
//         celula *temp = pilha->prox;
//         pilha->prox = temp->prox;
//         free(temp);
//     }
//     free(pilha);

//     return 0;
// }
