#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int dado;
    struct celula *prox;
} celula;

celula *enfileira(celula *f, int x)
{
    celula *nova = malloc(sizeof(celula));
    if(nova == NULL || f == NULL)
        return NULL;
    nova->prox = f->prox;
    f->prox = nova;
    f->dado = x;
    f = nova;
    return nova;
}