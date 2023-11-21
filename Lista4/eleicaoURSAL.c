#include <stdio.h>
#include <stdlib.h>

// Struct que armazena os votos de um candidato
typedef struct Candidato {
    int votos, digitos;
} Candidato;

// Funções merge e merge_sort que ordenam com base na quantidade de votos
void merge(Candidato *array, int left, int middle, int right) {
    Candidato *temp = malloc(sizeof(Candidato) * (right - left));

    int i = left, j = middle, k = 0;

    while (i < middle && j < right)
        temp[k++] = array[i].votos <= array[j].votos ? array[i++] : array[j++];

    while (i < middle)
        temp[k++] = array[i++];
    while (j < right)
        temp[k++] = array[j++];

    for (i = left; i < right; i++)
        array[i] = temp[i - left];

    free(temp);
}

void merge_sort(Candidato *array, int left, int right) {
    if (right - 1 <= left)
        return;

    int middle = left + (right - left) / 2;

    merge_sort(array, left, middle);
    merge_sort(array, middle, right);
    merge(array, left, middle, right);
}

int main() {
    // Inicializando variáveis e vetor de structs Candidato
    Candidato *candidatos = malloc(sizeof(Candidato) * 100001);
    int votos_presidente, votos_senador, votos_governador, voto, votos_validos = 0, votos_invalidos = 0;
    int votos_totais = 0;

    // Lendo variáveis
    scanf("%d %d %d", &votos_presidente, &votos_senador, &votos_governador);

    // Inicializando o vetor com as 100000 possibilidades de digitos
    for (int i = 10; i < 100000; i++)
        candidatos[i].digitos = i;

    // Lendo as entradas dos digitos contabilizando a quantidade de votos
    while (scanf("%d", &voto) != EOF) {
        // Não existe a possibilidade de um voto válido ser menor que 10
        if (voto >= 10) {
            // Incrementando o valor dos votos válidos e o valor do atributo votos da struct Candidato referente
            votos_validos++;
            candidatos[voto].votos++;
        } else {
            votos_invalidos++;
        }
    }

    // Ordenando o vetor quanto aos votos para cada cargo (presidente 10-100, senador 100-1000, etc.)
    for (int i = 0, multiplier = 10; i < 4; i++, multiplier *= 10)
        merge_sort(candidatos, multiplier, multiplier * 10);

    // Fazendo a contagem de votos para presidente
    for (int i = 99; i >= 10; i--)
        votos_totais += candidatos[i].votos;

    // Imprimindo os resultados
    printf("%d %d\n", votos_validos, votos_invalidos);

    int threshold = (float)candidatos[99].votos / (float)votos_totais >= 0.51 ? 1 : 0;

    if (threshold)
        printf("%d\n", candidatos[99].digitos);
    else
        printf("Segundo turno\n");

    for (int i = 999; votos_presidente; i--, votos_presidente--)
        printf("%d ", candidatos[i].digitos);
    printf("\n");

    for (int i = 9999; votos_senador; i--, votos_senador--)
        printf("%d ", candidatos[i].digitos);
    printf("\n");

    for (int i = 99999; votos_governador; i--, votos_governador--)
        printf("%d ", candidatos[i].digitos);
    printf("\n");

    printf("\n");

    free(candidatos);

    return 0;
}
