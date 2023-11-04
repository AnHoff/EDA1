#include <stdio.h>

int main() {
    int caso = 0;
    int P, R;

    while (1) {
        caso++;

        scanf("%d %d", &P, &R);
        if (P == 0 && R == 0) {
            break;
        }

        int fila[P];
        for (int i = 0; i < P; i++) {
            scanf("%d", &fila[i]);
        }

        int vencedor = 0;

        for (int i = 0; i < R; i++) {
            int N, J;
            scanf("%d %d", &N, &J);

            int acoes[N];
            for (int j = 0; j < N; j++) {
                scanf("%d", &acoes[j]);
            }

            int remanescentes[P];
            int idx = 0;

            for (int j = 0; j < N; j++) {
                if (acoes[j] == J) {
                    remanescentes[idx++] = fila[j];
                }
            }

            if (idx == 1) {
                vencedor = remanescentes[0];
            }

            for (int j = 0; j < P; j++) {
                fila[j] = remanescentes[j];
            }
        }

        printf("Teste %d\n%d\n\n", caso, vencedor);
    }

    return 0;
}
