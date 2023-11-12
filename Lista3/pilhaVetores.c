#include <stdio.h>
#include <stdlib.h>

// Definição da struct pilha
typedef struct {
    int *v;    // Vetor que contém os elementos da pilha
    int N;     // Tamanho de v
    int topo;  // Indicador do topo
} pilha;

// Função para empilhar o elemento x na pilha p
void empilha(pilha *p, int x) {
    if (p->topo == p->N) {
        // Pilha cheia, dobrar o tamanho do vetor
        p->N *= 2;
        p->v = (int *)realloc(p->v, p->N * sizeof(int));
        if (p->v == NULL) {
            // Tratamento de erro: falha na alocação de memória
            exit(EXIT_FAILURE);
        }
    }

    p->v[p->topo] = x;  // Insere o elemento na pilha
    p->topo++;          // Atualiza o topo
}

// Função para desempilhar um elemento da pilha
int desempilha(pilha *p, int *y) {
    if (p->topo == 0) {
        // Pilha vazia
        return 0;
    }

    p->topo--;          // Atualiza o topo
    *y = p->v[p->topo];  // Salva o dado a ser desempilhado

    return 1;            // Desempilhamento bem-sucedido
}

// int main() {
//     // Exemplo de uso
//     pilha minhaPilha;
//     minhaPilha.N = 5;     // Tamanho inicial da pilha
//     minhaPilha.topo = 0;  // Inicializa o topo
//     minhaPilha.v = (int *)malloc(minhaPilha.N * sizeof(int));  // Aloca espaço para os dados

//     // Empilha alguns elementos
//     for (int i = 1; i <= 8; i++) {
//         empilha(&minhaPilha, i);
//     }

//     // Desempilha um elemento
//     int elemento_desempilhado;
//     if (desempilha(&minhaPilha, &elemento_desempilhado)) {
//         printf("Elemento desempilhado: %d\n", elemento_desempilhado);
//     } else {
//         printf("A pilha está vazia.\n");
//     }

//     // Liberar memória
//     free(minhaPilha.v);

//     return 0;
// }
