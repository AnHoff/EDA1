#include <stdio.h>
#include <string.h>

void printInverso(char *str, int tam) {
    if (tam < 1) {
        return;
    }

    putchar(str[tam - 1]);
    printInverso(str, tam - 1);
}

int main() {
    char str[501];
    scanf("%s", str);

    int tam = strlen(str);
    printInverso(str, tam);

    printf("\n");

    return 0;
}
