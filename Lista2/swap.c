#include <stdio.h>

void swap(int *n1, int *n2) {
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

int main() {
    int num1, num2;

    scanf("%d %d", &num1, &num2);

    swap(&num1, &num2);
    printf("Antes: %d %d\n", num1, num2);
    printf("Depois: %d %d\n", num2, num1);

    return 0;
}
