#include <stdio.h>

int main() {
    int v[1000];
    int aux[500];
    int limite, n, counter = 0;
    int soma = 0;

    int i = 0;
    while (1) {
        scanf("%d", &n);
        if (n == 0) {
            break;
        }
        v[i] = n;
        i++;
    }
    scanf("%d", &limite);

    int ultimo = 0;
    for (int j = 0; j < i; j++) {
        soma += v[j];
        if (soma > limite) {
            aux[counter] = v[j];
            ultimo = v[j];
            soma = 0;
            counter ++;
        }
    }

    /*if (ultimo != 0) {
       // printf("%d\n", ultimo);
    }*/

    for( int i = counter - 1; i >= 0; i--){
        printf("%d\n", aux[i]);
    }

    return 0;
}
