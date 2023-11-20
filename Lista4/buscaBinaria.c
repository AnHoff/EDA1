#include <stdio.h>

// Função para realizar a busca binária
int buscaBinaria(int conjunto[], int tamanho, int alvo) {
    int baixo = 0, alto = tamanho;

    while (baixo < alto) {
        int meio = (baixo + alto) / 2;

        if (conjunto[meio] < alvo) {
            baixo = meio + 1;
        } else {
            alto = meio;
        }
    }

    return baixo;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int conjunto[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &conjunto[i]);
    }

    int consultas[m];
    for (int i = 0; i < m; i++) {
        scanf("%d", &consultas[i]);
    }

    // Processamento e saída
    for (int i = 0; i < m; i++) {
        int indice = buscaBinaria(conjunto, n, consultas[i]);
        printf("%d\n", indice);
    }

    return 0;
}
