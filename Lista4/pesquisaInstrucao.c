#include <stdio.h>
#include <stdlib.h>

// Struct que armazena a palavra-chave e seu ID em linguagem de máquina
typedef struct {
    int id;
    char palavra_chave[16];
} Instrucao;

// Função merge e merge_sort que ordenam com base no ID das instruções
void merge(Instrucao *vetor, int inicio, int meio, int fim) {
    Instrucao *auxiliar = (Instrucao *)malloc(sizeof(Instrucao) * (fim - inicio));

    int i = inicio, j = meio, k = 0;

    while (i < meio && j < fim) {
        auxiliar[k++] = vetor[i].id <= vetor[j].id ? vetor[i++] : vetor[j++];
    }

    while (i < meio) {
        auxiliar[k++] = vetor[i++];
    }

    while (j < fim) {
        auxiliar[k++] = vetor[j++];
    }

    for (i = inicio; i < fim; i++) {
        vetor[i] = auxiliar[i - inicio];
    }

    free(auxiliar);
}

void merge_sort(Instrucao *vetor, int inicio, int fim) {
    if (fim - 1 <= inicio) {
        return;
    }

    int meio = inicio + (fim - inicio) / 2;

    merge_sort(vetor, inicio, meio);
    merge_sort(vetor, meio, fim);
    merge(vetor, inicio, meio, fim);
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

    Instrucao vetor[num_instrucoes];

    for (int i = 0; i < num_instrucoes; i++) {
        scanf("%d %s", &vetor[i].id, vetor[i].palavra_chave);
    }

    merge_sort(vetor, 0, num_instrucoes);

    while (scanf("%d", &dado) != EOF) {
        int resposta = busca_binaria(vetor, num_instrucoes, dado);

        if (resposta == -1) {
            printf("undefined\n");
        } else {
            printf("%s\n", vetor[resposta].palavra_chave);
        }
    }

    return 0;
}
