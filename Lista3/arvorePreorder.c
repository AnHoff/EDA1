#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;

typedef struct {
    no **dados;
    int topo;
    int capacidade;
} Pilha;

// Função auxiliar para criar uma pilha
Pilha *criarPilha(int capacidade) {
    Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
    pilha->dados = (no **)malloc(capacidade * sizeof(no *));
    pilha->topo = -1;
    pilha->capacidade = capacidade;
    return pilha;
}

// Função auxiliar para empilhar um nó na pilha
void empilhar(Pilha *pilha, no *n) {
    if (pilha->topo == pilha->capacidade - 1) {
        // Pilha cheia, redimensiona a capacidade
        pilha->capacidade *= 2;
        pilha->dados = (no **)realloc(pilha->dados, pilha->capacidade * sizeof(no *));
    }

    pilha->topo++;
    pilha->dados[pilha->topo] = n;
}

// Função auxiliar para desempilhar um nó da pilha
no *desempilhar(Pilha *pilha) {
    if (pilha->topo == -1) {
        // Pilha vazia
        return NULL;
    }

    no *n = pilha->dados[pilha->topo];
    pilha->topo--;
    return n;
}

// Função para realizar o percurso pré-ordem não recursivo
void pre_ordem(no *raiz) {
    if (raiz == NULL) {
        return;
    }

    Pilha *pilha = criarPilha(10);  // Tamanho inicial da pilha
    empilhar(pilha, raiz);

    while (pilha->topo != -1) {
        no *atual = desempilhar(pilha);
        printf("%d ", atual->dado);

        if (atual->dir != NULL) {
            empilhar(pilha, atual->dir);
        }

        if (atual->esq != NULL) {
            empilhar(pilha, atual->esq);
        }
    }

    // Liberar a memória da pilha
    free(pilha->dados);
    free(pilha);
}

// Função auxiliar para criar um nó
no *criarNo(int dado) {
    no *novo = (no *)malloc(sizeof(no));
    novo->dado = dado;
    novo->esq = novo->dir = NULL;
    return novo;
}

// int main() {
//     // Exemplo de uso
//     no *raiz = criarNo(6);
//     raiz->esq = criarNo(3);
//     raiz->dir = criarNo(9);
//     raiz->esq->esq = criarNo(1);
//     raiz->esq->dir = criarNo(4);
//     raiz->dir->esq = criarNo(7);
//     raiz->dir->dir = criarNo(10);

//     // Realizar o percurso pré-ordem
//     printf("Percurso pré-ordem: ");
//     pre_ordem(raiz);

//     // Liberar a memória da árvore
//     free(raiz->esq->esq);
//     free(raiz->esq->dir);
//     free(raiz->dir->esq);
//     free(raiz->dir->dir);
//     free(raiz->esq);
//     free(raiz->dir);
//     free(raiz);

//     return 0;
// }
