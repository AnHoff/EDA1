#include <stdio.h>

int f91(int n) {
    if (n >= 101) {
        return n - 10;
    } else {
        return f91(f91(n + 11));
    }
}

int main() {
    int num;
    while (1) {
        scanf("%d", &num);

        if (num == 0) {
            break;
        }

        int result = f91(num);

        printf("f91(%d) = %d\n", num, result);
    }
    return 0;
}
