#include <stdio.h>
#include <stdlib.h>

// Definição da struct celula
typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

// Função para empilhar o elemento x na pilha encabeçada por p
void empilha(celula *p, int x) {
    celula *novo = (celula *)malloc(sizeof(celula));
    if (novo == NULL) {
        // Tratamento de erro: falha na alocação de memória
        exit(EXIT_FAILURE);
    }

    novo->dado = x;
    novo->prox = p->prox;  // O novo nó aponta para o antigo primeiro nó da pilha
    p->prox = novo;        // O nó cabeça aponta para o novo primeiro nó
}

// Função para desempilhar um elemento da pilha
int desempilha(celula *p, int *y) {
    if (p == NULL || p->prox == NULL) {
        // Pilha vazia
        return 0;
    }

    celula *temp = p->prox;  // Aponta para o primeiro elemento da pilha
    *y = temp->dado;        // Salva o dado a ser desempilhado

    p->prox = temp->prox;    // Atualiza o ponteiro do nó cabeça para o próximo elemento
    free(temp);              // Libera o nó desempilhado da memória

    return 1;                // Desempilhamento bem-sucedido
}

// int main() {
//     // Exemplo de uso
//     celula *pilha = (celula *)malloc(sizeof(celula));
//     pilha->prox = NULL;  // Inicializa a pilha como vazia

//     // Empilha alguns elementos
//     for (int i = 1; i <= 5; i++) {
//         empilha(pilha, i);
//     }

//     // Desempilha um elemento
//     int elemento_desempilhado;
//     if (desempilha(pilha, &elemento_desempilhado)) {
//         printf("Elemento desempilhado: %d\n", elemento_desempilhado);
//     } else {
//         printf("A pilha está vazia.\n");
//     }

//     // Liberar memória
//     while (pilha->prox != NULL) {
//         celula *temp = pilha->prox;
//         pilha->prox = temp->prox;
//         free(temp);
//     }
//     free(pilha);

//     return 0;
// }
