#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int quantidade, posicao;
    char letra;
} DadosLetra;

void merge(DadosLetra *vetor, int inicio, int meio, int fim) {
    DadosLetra *auxiliar = malloc(sizeof(DadosLetra) * (fim - inicio));

    int i = inicio;
    int j = meio;
    int k = 0;

    while (i < meio && j < fim) {
        if (vetor[i].quantidade >= vetor[j].quantidade) {
            auxiliar[k++] = vetor[i++];
        } else {
            auxiliar[k++] = vetor[j++];
        }
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

void merge_sort(DadosLetra *vetor, int inicio, int fim) {
    if (inicio >= fim - 1) {
        return;
    }

    int meio = inicio + (fim - inicio) / 2;

    merge_sort(vetor, inicio, meio);
    merge_sort(vetor, meio, fim);
    merge(vetor, inicio, meio, fim);
}

int main() {
    DadosLetra vetor[100001];
    char string[100001];

    scanf("%s", string);

    int tamanho = 0, k = 0;
    int posicao = 0;
    int contador = 0;
    char anterior = string[0];
    char *caractere = &string[0];

    // Enquanto não chegar ao fim da string
    while (*caractere != '\0') {
        // Enquanto a letra atual for igual à anterior, aumenta o tamanho (quantidade) e muda o ponteiro para a próxima letra
        for (; *caractere == anterior; caractere++, tamanho++)
            ;

        DadosLetra letra;
        letra.quantidade = tamanho, letra.posicao = posicao, letra.letra = *(caractere - 1);

        vetor[k++] = letra;

        // Incrementando variáveis para continuar a leitura
        posicao += tamanho;
        tamanho = 0;
        contador++;
        anterior = *caractere;
    }

    merge_sort(vetor, 0, contador);

    for (int j = 0; j < contador; j++)
        printf("%d %c %d\n", vetor[j].quantidade, vetor[j].letra, vetor[j].posicao);

    return 0;
}
