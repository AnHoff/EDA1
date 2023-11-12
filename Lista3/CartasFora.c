#include <stdio.h>
#include <stdlib.h>

void descarta_cartas(int n)
{
    int *cartas = malloc(sizeof(int) * n * 2);
    int *cartas_descartadas = malloc(sizeof(int) * n);
    int inicio = 0;
    int fim = n - 1;
    int fim_descarte = 0;

    for (int i = 0; i < n; i++)
        cartas[i] = i + 1;

    for (int i = 1; i < n; i++)
    {
        cartas_descartadas[fim_descarte++] = cartas[inicio];
        cartas[++fim] = cartas[inicio + 1];
        inicio += 2;
    }
    
    printf("Cartas descartadas: %d", cartas_descartadas[0]);

    for (int j = 1; j < fim_descarte; j++)
        printf(", %d", cartas_descartadas[j]);

    printf("\n");

    printf("Carta restante: %d", cartas[inicio]);

    printf("\n");
}



int main()
{
    int n;
    scanf("%d", &n);

    descarta_cartas(n);

    return 0;
}