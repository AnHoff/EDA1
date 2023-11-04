#include <stdio.h>

int main() {
    int botas[61][2] = {0}; // Inicializa um array para contar as botas de cada tamanho e pé
    int total_pares = 0;

    int tamanho;
    char pe;

    while (scanf("%d %c", &tamanho, &pe) != EOF) {
        if (pe == 'E') {
            botas[tamanho][0]++; // Incrementa o número de botas esquerdas desse tamanho
        } else if (pe == 'D') {
            botas[tamanho][1]++; // Incrementa o número de botas direitas desse tamanho
        }
    }

    for (int i = 30; i <= 60; i++) {
        // Conta quantos pares podem ser formados para cada tamanho
        total_pares += (botas[i][0] < botas[i][1] ? botas[i][0] : botas[i][1]);
    }

    printf("%d\n", total_pares);

    return 0;
}
