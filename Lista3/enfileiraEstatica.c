#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
    int *dados;
    int N, p, u;
} fila;

int enfileira(fila *f, int x) {
    // Verifica se a fila está cheia e redimensiona o vetor
    if (f->u == f->N) {
        int novoTamanho = f->N * 2; // Duplique o tamanho da fila 
        int *novoDados = (int *)malloc(novoTamanho * sizeof(int));

        if (novoDados == NULL) {
            fprintf(stderr, "Erro de alocação de memória ao enfileirar o elemento %d\n", x);
            return 0;
        }

        for (int i = 0; i < f->N; i++) {
            novoDados[i] = f->dados[(f->p + i) % f->N];
        }

        f->p = 0;
        f->u = f->N;
        f->N = novoTamanho;

        free(f->dados);
        f->dados = novoDados;
    }

    f->dados[f->u] = x;
    f->u++;

    return 1;
}

// int main() {
//     fila minhaFila;
//     int tamanhoInicial = 10; // Tamanho inicial da fila

//     minhaFila.dados = (int *)malloc(tamanhoInicial * sizeof(int));
//     minhaFila.N = tamanhoInicial;
//     minhaFila.p = 0;
//     minhaFila.u = 0;

//     // Enfileirar elementos na fila
//     for (int i = 1; i <= 15; i++) {
//         if (enfileira(&minhaFila, i)) {
//             printf("Elemento enfileirado: %d\n", i);
//         } else {
//             printf("Erro ao enfileirar o elemento: %d\n", i);
//         }
//     }

//     // Liberar a memória alocada para o vetor de dados
//     free(minhaFila.dados);

//     return 0;
// }