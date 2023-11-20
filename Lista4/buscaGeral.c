#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int valor, indice;
} Dado;

// Função para ordenar os dados
void shell_sort(Dado *v, int n) {
    int h = 1;

    while (h <= n / 9) {
        h = 3 * h + 1;
    }

    while (h > 0) {
        for (int i = h; i < n; i++) {
            Dado temp = v[i];
            int j = i;

            while (j >= h && temp.valor < v[j - h].valor) {
                v[j] = v[j - h];
                j -= h;
            }

            v[j] = temp;
        }

        h /= 3;
    }
}

// Função busca binária que retorna o índice do dado (se o dado estiver no vetor) ou -1
int busca_binaria(const Dado *v, int n, int dado) {
    int l = 0;
    int h = n;

    while (h > l) {
        int meio = l + (h - l) / 2;

        if (dado == v[meio].valor) {
            return meio;
        } else if (dado < v[meio].valor) {
            h = meio;
        } else {
            l = meio + 1;
        }
    }

    return -1;
}

int main() {
    int n, m, dado;
    scanf("%d %d", &n, &m);

    Dado *v = malloc(sizeof(Dado) * n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i].valor);
        v[i].indice = i;
    }

    // Ordenando o vetor
    shell_sort(v, n);

    // Lendo os dados de busca
    while (m--) {
        scanf("%d", &dado);

        int indice = busca_binaria(v, n, dado);

        if (indice != -1) {
            printf("%d\n", v[indice].indice);
        } else {
            printf("%d\n", indice);
        }
    }

    free(v);

    return 0;
}
