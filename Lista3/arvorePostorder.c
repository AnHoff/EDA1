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

// Função para realizar o percurso pós-ordem não recursivo
void pos_ordem(no *raiz) {
    if (raiz == NULL) {
        return;
    }

    Pilha *pilha1 = criarPilha(10);  // Pilha para os nós
    Pilha *pilha2 = criarPilha(10);  // Pilha para a ordem final

    empilhar(pilha1, raiz);

    while (pilha1->topo != -1) {
        no *atual = desempilhar(pilha1);
        empilhar(pilha2, atual);

        if (atual->esq != NULL) {
            empilhar(pilha1, atual->esq);
        }

        if (atual->dir != NULL) {
            empilhar(pilha1, atual->dir);
        }
    }

    // Imprimir a ordem final
    while (pilha2->topo != -1) {
        no *n = desempilhar(pilha2);
        printf("%d ", n->dado);
    }

    // Liberar a memória das pilhas
    free(pilha1->dados);
    free(pilha1);
    free(pilha2->dados);
    free(pilha2);
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

//     // Realizar o percurso pós-ordem
//     printf("Percurso pós-ordem: ");
//     pos_ordem(raiz);

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
