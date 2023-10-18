#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void divide_lista(celula *l, celula *l1, celula *l2) {
    l1->prox = NULL;
    l2->prox = NULL;

    celula *atual_l1 = l1;
    celula *atual_l2 = l2;

    celula *atual = l->prox;

    while (atual != NULL) {
        if (atual->dado % 2 == 0) {
            // Número par para l2
            atual_l2->prox = atual;
            atual_l2 = atual_l2->prox;
        } else {
            // Número ímpar para l1
            atual_l1->prox = atual;
            atual_l1 = atual_l1->prox;
        }

        atual = atual->prox;
    }

    atual_l1->prox = NULL;
    atual_l2->prox = NULL;
}

int main() {
    celula *l = (celula *)malloc(sizeof(celula));
    l->prox = NULL;

    int valores[] = {10, 4, -9, 2, 7, 10};
    for (int i = sizeof(valores) / sizeof(valores[0]) - 1; i >= 0; i--) {
        celula *nova_celula = (celula *)malloc(sizeof(celula));
        nova_celula->dado = valores[i];
        nova_celula->prox = l->prox;
        l->prox = nova_celula;
    }

    celula *l1 = (celula *)malloc(sizeof(celula));
    celula *l2 = (celula *)malloc(sizeof(celula));

    divide_lista(l, l1, l2);

    printf("l1: ");
    celula *temp = l1->prox;
    while (temp != NULL) {
        printf("%d -> ", temp->dado);
        temp = temp->prox;
    }
    printf("NULL\n");

    printf("l2: ");
    temp = l2->prox;
    while (temp != NULL) {
        printf("%d -> ", temp->dado);
        temp = temp->prox;
    }
    printf("NULL\n");

    return 0;
}
