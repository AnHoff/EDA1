#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
    int *dados;
    int N, topo;
} pilha;

int empilha(pilha *p, int x) {
    if (p->topo == p->N) {
        // Pilha cheia, redimensiona o vetor
        p->N *= 2;  // Dobrar o tamanho do vetor
        p->dados = (int *)realloc(p->dados, p->N * sizeof(int));
        if (p->dados == NULL) {
            // Falha na alocação de memória
            return 0;
        }
    }

    p->dados[p->topo] = x;  // Insere o elemento na pilha
    p->topo++;              // Atualiza o topo

    return 1;  // Inserção bem-sucedida
}

// int main() {
//     // Exemplo de uso
//     pilha minhaPilha;
//     minhaPilha.N = 5;     // Tamanho inicial da pilha
//     minhaPilha.topo = 0;  // Inicializa o topo
//     minhaPilha.dados = (int *)malloc(minhaPilha.N * sizeof(int));  // Aloca espaço para os dados

//     // Empilha alguns elementos
//     for (int i = 1; i <= 8; i++) {
//         if (empilha(&minhaPilha, i)) {
//             printf("Elemento %d empilhado com sucesso.\n", i);
//         } else {
//             printf("Falha ao empilhar o elemento %d. Memória insuficiente.\n", i);
//             // Tratamento adicional, se necessário
//         }
//     }

//     // Liberar memória
//     free(minhaPilha.dados);

//     return 0;
// }
