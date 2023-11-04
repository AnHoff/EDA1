#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
    int *dados;
    int N, p, u;
} fila;

int desenfileira(fila *f, int *y) {
    if (f->p == f->u) {
        // A fila está vazia, não é possível desenfileirar
        return 0;
    }

    *y = f->dados[f->p];
    f->p = (f->p + 1) % f->N;
    return 1;
}

// int main() {
//     fila minhaFila;
//     int tamanhoMaximo = 10; // Tamanho máximo da fila

//     minhaFila.dados = (int *)malloc(tamanhoMaximo * sizeof(int));
//     minhaFila.N = tamanhoMaximo;
//     minhaFila.p = 0;
//     minhaFila.u = 0;

//     // Inserir elementos na fila (suponha que já existe uma função para isso)

//     int elemento;

//     if (desenfileira(&minhaFila, &elemento)) {
//         printf("Elemento desenfileirado: %d\n", elemento);
//     } else {
//         printf("Fila vazia, não foi possível desenfileirar.\n");
//     }

//     // Liberar a memória alocada para o vetor de dados
//     free(minhaFila.dados);

//     return 0;
// }
