#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void mescla_listas(celula *l1, celula *l2, celula *l3) {
    celula *atual1 = l1->prox;
    celula *atual2 = l2->prox;
    celula *atual3 = l3;

    while (atual1 != NULL && atual2 != NULL) {
        if (atual1->dado <= atual2->dado) {
            atual3->prox = atual1;
            atual1 = atual1->prox;
        } else {
            atual3->prox = atual2;
            atual2 = atual2->prox;
        }
        atual3 = atual3->prox;
    }

    while (atual1 != NULL) {
        atual3->prox = atual1;
        atual1 = atual1->prox;
        atual3 = atual3->prox;
    }

    while (atual2 != NULL) {
        atual3->prox = atual2;
        atual2 = atual2->prox;
        atual3 = atual3->prox;
    }
}

int main() {
    celula l1, l2, l3;
    l1.prox = NULL;
    l2.prox = NULL;
    l3.prox = NULL;

    int valores1[] = {1, 7, 9, 10};
    int valores2[] = {2, 3, 8};

    for (int i = sizeof(valores1) / sizeof(valores1[0]) - 1; i >= 0; i--) {
        celula *nova_celula = (celula *)malloc(sizeof(celula));
        nova_celula->dado = valores1[i];
        nova_celula->prox = l1.prox;
        l1.prox = nova_celula;
    }

    for (int i = sizeof(valores2) / sizeof(valores2[0]) - 1; i >= 0; i--) {
        celula *nova_celula = (celula *)malloc(sizeof(celula));
        nova_celula->dado = valores2[i];
        nova_celula->prox = l2.prox;
        l2.prox = nova_celula;
    }

    mescla_listas(&l1, &l2, &l3);

    printf("Lista mesclada (l3): ");
    celula *atual = l3.prox;
    while (atual != NULL) {
        printf("%d -> ", atual->dado);
        atual = atual->prox;
    }
    printf("NULL\n");

    while (l1.prox != NULL) {
        celula *temp = l1.prox;
        l1.prox = temp->prox;
        free(temp);
    }

    while (l2.prox != NULL) {
        celula *temp = l2.prox;
        l2.prox = temp->prox;
        free(temp);
    }

    while (l3.prox != NULL) {
        celula *temp = l3.prox;
        l3.prox = temp->prox;
        free(temp);
    }

    return 0;
}
