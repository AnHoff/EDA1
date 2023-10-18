#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void imprime(celula *le) {
    celula *atual = le->prox;

    if (atual == NULL) {
        printf("NULL\n");
        return;
    }

    while (atual != NULL) {
        printf("%d", atual->dado);
        if (atual->prox != NULL) {
            printf(" -> ");
        }
        atual = atual->prox;
    }
    printf(" -> NULL\n");
}

void imprime_rec(celula *le) {
    if (le->prox == NULL) {
        printf("NULL\n");
        return;
    }

    printf("%d", le->prox->dado);
    if (le->prox->prox != NULL) {
        printf(" -> ");
    }
    imprime_rec(le->prox);
}

int main() {
    celula le;
    le.prox = NULL;

    int valores[] = {1, 2, 3};

    for (int i = sizeof(valores) / sizeof(valores[0]) - 1; i >= 0; i--) {
        celula *nova_celula = (celula *)malloc(sizeof(celula));
        nova_celula->dado = valores[i];
        nova_celula->prox = le.prox;
        le.prox = nova_celula;
    }

    printf("Iterativo: ");
    imprime(&le);

    printf("Recursivo: ");
    if (le.prox != NULL) {
        imprime_rec(&le);
    }

    while (le.prox != NULL) {
        celula *temp = le.prox;
        le.prox = temp->prox;
        free(temp);
    }

    return 0;
}
