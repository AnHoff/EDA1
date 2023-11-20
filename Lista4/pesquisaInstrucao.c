#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char palavra_chave[16];
} Instrucao;

// Função de comparação para o qsort
int comparar_instrucoes(const void *a, const void *b) {
    return ((Instrucao *)b)->id - ((Instrucao *)a)->id;
}

// Função busca binária que retorna o índice do ID encontrado no vetor (caso exista) e -1 caso não
int busca_binaria(Instrucao *vetor, int n, int dado) {
    int l = 0, h = n;

    while (h > l) {
        int meio = l + (h - l) / 2;
        if (vetor[meio].id == dado) {
            return meio;
        } else if (vetor[meio].id > dado) {
            h = meio;
        } else {
            l = meio + 1;
        }
    }

    return -1;
}

int main() {
    int num_instrucoes, dado;
    scanf("%d", &num_instrucoes);

    Instrucao *vetor = malloc(sizeof(Instrucao) * num_instrucoes);

    for (int i = 0; i < num_instrucoes; i++) {
        scanf("%d %s", &vetor[i].id, vetor[i].palavra_chave);
    }

    // Ordena o vetor em ordem decrescente com base no ID
    qsort(vetor, num_instrucoes, sizeof(Instrucao), comparar_instrucoes);

    while (scanf("%d", &dado) != EOF) {
        int resposta = busca_binaria(vetor, num_instrucoes, dado);

        if (resposta == -1) {
            printf("undefined\n");
        } else {
            printf("%s\n", vetor[resposta].palavra_chave);
        }
    }

    free(vetor);

    return 0;
}
