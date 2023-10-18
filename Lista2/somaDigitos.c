#include <stdio.h>

int somaDigitos(long n) {
    if (n < 10) {
        return n;
    } else {
        return n % 10 + somaDigitos(n / 10);
    }
}

int main() {
    long numero;
    scanf("%ld", &numero);
    int resultado = somaDigitos(numero);
    printf("%d\n", resultado);

    return 0;
}
