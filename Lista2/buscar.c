#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

celula *busca(celula *le, int x) {
    celula *atual = le->prox;

    while (atual != NULL) {
        if (atual->dado == x) {
            return atual;
        }
        atual = atual->prox;
    }

    return NULL;
}

celula *busca_rec(celula *le, int x) {
    if (le->prox == NULL) {
        return NULL;
    }

    if (le->prox->dado == x) {
        return le->prox;
    }

    return busca_rec(le->prox, x);
}

int main() {
    celula *le = (celula *)malloc(sizeof(celula));
    le->prox = NULL;

    for (int i = 0; i < 10; i++) {
        celula *nova_celula = (celula *)malloc(sizeof(celula));
        nova_celula->dado = i;
        nova_celula->prox = le->prox;
        le->prox = nova_celula;
    }

    int elemento = 5;

    celula *resultado = busca(le, elemento);
    if (resultado != NULL) {
        printf("Elemento %d encontrado na busca iterativa.\n", elemento);
    } else {
        printf("Elemento %d não encontrado na busca iterativa.\n", elemento);
    }

    resultado = busca_rec(le, elemento);
    if (resultado != NULL) {
        printf("Elemento %d encontrado na busca recursiva.\n", elemento);
    } else {
        printf("Elemento %d não encontrado na busca recursiva.\n", elemento);
    }

    celula *atual = le->prox;
    while (atual != NULL) {
        celula *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(le);

    return 0;
}
