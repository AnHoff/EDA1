#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tradutor {
    char japones[100];
    char portugues[100];
} Tradutor;

// Funções de merge e merge_sort para ordenação das palavras em japonês
void merge(Tradutor *array, int left, int middle, int right) {
    Tradutor *temp = malloc(sizeof(Tradutor) * (right - left));

    int i = left, j = middle, k = 0;
    while (i < middle && j < right)
        temp[k++] = strcmp(array[i].japones, array[j].japones) <= 0 ? array[i++] : array[j++];

    while (i < middle)
        temp[k++] = array[i++];
    while (j < right)
        temp[k++] = array[j++];

    for (i = left; i < right; i++)
        array[i] = temp[i - left];

    free(temp);
}

void merge_sort(Tradutor *array, int left, int right) {
    if (right - 1 <= left)
        return;

    int middle = left + (right - left) / 2;

    merge_sort(array, left, middle);
    merge_sort(array, middle, right);
    merge(array, left, middle, right);
}

// Função busca binária que retorna o índice do dado no vetor caso exista, caso não retorna -1
int busca_binaria(Tradutor *array, int n, char *dado) {
    int low = 0, high = n;

    while (high >= low) {
        int middle = low + (high - low) / 2;
        if (!strcmp(array[middle].japones, dado))
            return middle;
        else if (strcmp(array[middle].japones, dado) > 0)
            high = middle - 1;
        else
            low = middle + 1;
    }
    return -1;
}

int main() {
    int casos_teste;

    scanf("%d", &casos_teste);

    while (casos_teste--) {
        int tamanho_dicionario, numero_palavras;

        scanf("%d %d", &tamanho_dicionario, &numero_palavras);

        Tradutor *dicionario = malloc(sizeof(Tradutor) * tamanho_dicionario);
        char frase[100];

        for (int i = 0; i < tamanho_dicionario; i++) {
            scanf("\n");

            fgets(dicionario[i].japones, sizeof(dicionario[i].japones), stdin);
            fgets(dicionario[i].portugues, sizeof(dicionario[i].portugues), stdin);

            // Usando a função strcspn para encontrar o índice que contém '\n' e substitui-lo por '\0'
            dicionario[i].japones[strcspn(dicionario[i].japones, "\n")] = '\0';
            dicionario[i].portugues[strcspn(dicionario[i].portugues, "\n")] = '\0';
        }

        // Ordenando as palavras em ordem alfabética (em japonês)
        merge_sort(dicionario, 0, tamanho_dicionario);

        // Fazendo a leitura das palavras e buscando no vetor
        while (numero_palavras--) {
            int indice = 0;
            int indice_palavra = 0;

            scanf("\n");
            fgets(frase, sizeof(frase), stdin);
            frase[strcspn(frase, "\n")] = '\0';

            while (1) {
                char palavra[100];
                while (frase[indice] != ' ' && frase[indice] != '\0')
                    palavra[indice_palavra++] = frase[indice++];

                palavra[indice_palavra] = '\0';
                indice++;

                int resposta = busca_binaria(dicionario, tamanho_dicionario, palavra);

                if (resposta == -1)
                    printf("%s", palavra);
                else
                    printf("%s", dicionario[resposta].portugues);

                if (frase[indice] == '\0')
                    break;
                else
                    printf(" ");

                indice_palavra = 0;
            }
            printf("\n");
        }

        free(dicionario);
    }

    return 0;
}
