#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

int desenfileira(celula *f, int *y)
{
    if (f == NULL)
        return 0;
        
    celula *nova = f->prox;
    *y = nova->dado;
    f->prox = nova->prox;
    free(nova);

    return 0;
}