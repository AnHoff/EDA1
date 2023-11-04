#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Digite o valor de n: ");
    scanf("%d", &n);

    // Inicializa a pilha com as cartas numeradas de 1 a n
    int *pilha = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        pilha[i] = i + 1;
    }

    // Inicializa a lista de cartas descartadas
    int *descartadas = (int *)malloc((n - 1) * sizeof(int));
    int topo = 0; // Índice do topo da pilha
    int descartadasIndex = 0; // Índice para as cartas descartadas

    while (n >= 2) {
        // Descarta a carta do topo
        descartadas[descartadasIndex] = pilha[topo];
        descartadasIndex++;

        // Move a próxima carta para a base da pilha
        topo = (topo + 1) % n;
        n--;
    }

    // Imprime a sequência de cartas descartadas
    printf("Cartas descartadas: ");
    for (int i = 0; i < descartadasIndex; i++) {
        printf("%d", descartadas[i]);
        if (i < descartadasIndex - 1) {
            printf(", ");
        }
    }
    printf("\n");

    // A última carta da pilha é a única que resta
    printf("Carta restante: %d\n", pilha[topo]);

    // Libera a memória alocada
    free(pilha);
    free(descartadas);

    return 0;
}
