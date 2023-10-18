#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

int remove_depois(celula *p) {
    if (p == NULL || p->prox == NULL) {
        return 0;
    }

    celula *temp = p->prox;
    p->prox = temp->prox;
    free(temp);
    return 1;
}

void remove_elemento(celula *le, int x) {
    celula *anterior = le;
    celula *atual = le->prox;

    while (atual != NULL) {
        if (atual->dado == x) {
            anterior->prox = atual->prox;
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
}

void remove_todos_elementos(celula *le, int x) {
    celula *anterior = le;
    celula *atual = le->prox;

    while (atual != NULL) {
        if (atual->dado == x) {
            celula *temp = atual;
            anterior->prox = atual->prox;
            atual = atual->prox;
            free(temp);
        } else {
            anterior = atual;
            atual = atual->prox;
        }
    }
}

int main() {
    celula le;
    le.prox = NULL;

    int valores[] = {1, 2, 3, 2, 4, 2, 5};

    for (int i = sizeof(valores) / sizeof(valores[0]) - 1; i >= 0; i--) {
        celula *nova_celula = (celula *)malloc(sizeof(celula));
        nova_celula->dado = valores[i];
        nova_celula->prox = le.prox;
        le.prox = nova_celula;
    }

    printf("Lista antes da remoção: ");
    celula *atual = le.prox;
    while (atual != NULL) {
        printf("%d -> ", atual->dado);
        atual = atual->prox;
    }
    printf("NULL\n");

    int elemento_a_remover = 2;
    celula *ponteiro = le.prox;

    if (remove_depois(ponteiro)) {
        printf("Remoção do elemento seguinte bem-sucedida.\n");
    } else {
        printf("Não é possível remover o elemento seguinte.\n");
    }

    remove_elemento(&le, elemento_a_remover);

    remove_todos_elementos(&le, elemento_a_remover);

    printf("Lista após a remoção: ");
    atual = le.prox;
    while (atual != NULL) {
        printf("%d -> ", atual->dado);
        atual = atual->prox;
    }
    printf("NULL\n");

    while (le.prox != NULL) {
        celula *temp = le.prox;
        le.prox = temp->prox;
        free(temp);
    }

    return 0;
}
