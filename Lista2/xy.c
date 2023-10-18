#include <stdio.h>

void subsXeY(char *str, int pos) {
    if (str[pos] == '\0') {
        return;
    }
    if (str[pos] == 'x') {
        str[pos] = 'y';
    }

    subsXeY(str, pos + 1);
}

int main() {
    char str[81];
    scanf("%s", str);
    subsXeY(str, 0);
    printf("%s\n", str);

    return 0;
}
