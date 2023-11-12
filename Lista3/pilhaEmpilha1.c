#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

int empilha(celula *p, int x) {
    celula *novo = (celula *)malloc(sizeof(celula));
    if (novo == NULL) {
        return 0;
    }

    novo->dado = x;
    novo->prox = p->prox;  
    p->prox = novo;        

    return 1;
}

// int main() {
//     // Exemplo de uso
//     celula *pilha = (celula *)malloc(sizeof(celula));
//     pilha->prox = NULL;  // Inicializa a pilha como vazia

//     // Empilha alguns elementos
//     for (int i = 1; i <= 5; i++) {
//         if (empilha(pilha, i)) {
//             printf("Elemento %d empilhado com sucesso.\n", i);
//         } else {
//             printf("Falha ao empilhar o elemento %d.\n", i);
//         }
//     }

//     // Liberar memória
//     while (pilha->prox != NULL) {
//         celula *temp = pilha->prox;
//         pilha->prox = temp->prox;
//         free(temp);
//     }
//     free(pilha);

//     return 0;
// }
