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

    // Redimensiona o vetor de dados se ele estiver menos de 1/4 cheio
    if (f->u - f->p <= f->N / 4) {
        int novoTamanho = f->N / 2; // Reduza o tamanho pela metade (você pode ajustar isso conforme necessário)
        int *novoDados = (int *)malloc(novoTamanho * sizeof(int));

        if (novoDados == NULL) {
            fprintf(stderr, "Erro de alocação de memória ao redimensionar a fila.\n");
            exit(1);
        }

        int i = 0;
        while (f->p != f->u) {
            novoDados[i] = f->dados[f->p];
            f->p = (f->p + 1) % f->N;
            i++;
        }

        f->p = 0;
        f->u = i;
        f->N = novoTamanho;

        free(f->dados);
        f->dados = novoDados;
    }

    return 1;
}

// int main() {
//     fila minhaFila;
//     int tamanhoInicial = 10; // Tamanho inicial da fila

//     minhaFila.dados = (int *)malloc(tamanhoInicial * sizeof(int));
//     minhaFila.N = tamanhoInicial;
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
