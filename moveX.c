#include <stdio.h>
#include <string.h>

void moveX(char *str, int pos, int xCount) {
    int length = strlen(str);

    if (pos == length) {
        for (int i = length - xCount; i < length; i++) {
            str[i] = 'x';
        }
        str[length] = '\0';
    } else {
        if (str[pos] == 'x') {
            xCount++;
        } else {
            str[pos - xCount] = str[pos];
        }
        moveX(str, pos + 1, xCount);
    }
}

int main() {
    char str[101];
    scanf("%s", str);
    moveX(str, 0, 0);
    printf("%s\n", str);

    return 0;
}
