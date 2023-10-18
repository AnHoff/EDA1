#include <stdio.h>
#include <string.h>

int contarPares(char *str, int pos) {
    int totalPar = 0;
    int tam = strlen(str);

    if (pos < tam - 2) {
        if (str[pos] == str[pos + 2]) {
            totalPar++;
        }
    }

    if (pos < tam - 1) {
        totalPar += contarPares(str, pos + 1);
    }

    return totalPar;
}

int main() {
    char str[201];
    scanf("%s", str);

    int totalPar = contarPares(str, 0);
    printf("%d\n", totalPar);

    return 0;
}
