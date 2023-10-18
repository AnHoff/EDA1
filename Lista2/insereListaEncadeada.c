#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void insere_inicio(celula *le, int x) {
    celula *nova_celula = (celula *)malloc(sizeof(celula));
    nova_celula->dado = x;
    nova_celula->prox = le->prox;
    le->prox = nova_celula;
}

void insere_antes(celula *le, int x, int y) {
    celula *anterior = le;
    celula *atual = le->prox;

    while (atual != NULL) {
        if (atual->dado == y) {
            celula *nova_celula = (celula *)malloc(sizeof(celula));
            nova_celula->dado = x;
            nova_celula->prox = atual;
            anterior->prox = nova_celula;
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }

    celula *nova_celula = (celula *)malloc(sizeof(celula));
    nova_celula->dado = x;
    nova_celula->prox = NULL;
    anterior->prox = nova_celula;
}

// int main() {
//     celula le;
//     le.prox = NULL;

//     for (int i = 1; i <= 3; i++) {
//         insere_inicio(&le, i);
//     }

//     celula *atual = le.prox;
//     while (atual != NULL) {
//         printf("%d -> ", atual->dado);
//         atual = atual->prox;
//     }
//     printf("NULL\n");

//     insere_antes(&le, 4, 2);

//     atual = le.prox;
//     while (atual != NULL) {
//         printf("%d -> ", atual->dado);
//         atual = atual->prox;
//     }
//     printf("NULL\n");

//     return 0;
// }
