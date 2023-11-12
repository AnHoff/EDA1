#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura da fila
typedef struct {
    int *dados;
    int N, p, u;
} fila;

// Função para desenfileirar um elemento da fila
int desenfileira(fila *f, int *y) {
    // Verifica se a fila está vazia
    if (f->p == f->u) {
        return 0;  // Remoção mal sucedida, fila vazia
    }

    *y = f->dados[f->p];  // Salva o valor do elemento em y
    f->p++;               // Atualiza o índice da frente da fila

    // Redimensiona o vetor se o tamanho atual for muito grande
    if (f->u > 2 * f->p && f->u <= f->N / 4) {
        int *novo_dados = (int *)malloc(f->N / 2 * sizeof(int));
        if (novo_dados == NULL) {
            // Se a alocação falhar, a operação de desenfileirar ainda é considerada bem sucedida
            return 1;
        }

        for (int i = f->p, j = 0; i < f->u; i++, j++) {
            novo_dados[j] = f->dados[i];
        }

        free(f->dados);
        f->dados = novo_dados;
        f->N /= 2;
        f->p = 0;
        f->u = f->u - f->p;
    }

    return 1;  // Remoção bem sucedida
}
