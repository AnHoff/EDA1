#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
    int *dados;
    int N, topo;
} pilha;

int desempilha(pilha *p, int *y) {
    if (p == NULL || p->topo == 0) {
        // Pilha vazia
        return 0;
    }

    p->topo--;          // Decrementa o topo para apontar para a última posição ocupada
    *y = p->dados[p->topo];  // Salva o dado a ser removido

    return 1;           // Remoção bem-sucedida
}

// int main() {
//     // Exemplo de uso
//     pilha minhaPilha;
//     minhaPilha.N = 5;     // Tamanho máximo da pilha
//     minhaPilha.topo = 0;  // Inicializa o topo
//     minhaPilha.dados = (int *)malloc(minhaPilha.N * sizeof(int));  // Aloca espaço para os dados

//     // Adiciona alguns elementos à pilha
//     for (int i = 1; i <= 5; i++) {
//         minhaPilha.dados[minhaPilha.topo] = i;
//         minhaPilha.topo++;
//     }

//     // Desempilha um elemento
//     int elemento_removido;
//     if (desempilha(&minhaPilha, &elemento_removido)) {
//         printf("Elemento removido: %d\n", elemento_removido);
//     } else {
//         printf("A pilha está vazia.\n");
//     }

//     // Liberar memória
//     free(minhaPilha.dados);

//     return 0;
// }
