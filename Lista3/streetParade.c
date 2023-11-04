#include <stdio.h>

int main() {
    while (1) {
        int n;
        scanf("%d", &n);
        if (n == 0) {
            break;
        }

        int order[1001];
        int expected_order[1001];

        for (int i = 0; i < n; i++) {
            scanf("%d", &order[i]);
            expected_order[i] = i + 1;
        }

        int stack[1001];
        int top = 0;
        int i = 0;
        int possible = 1;

        for (int j = 0; j < n; j++) {
            while (top > 0 && stack[top - 1] == expected_order[i]) {
                top--;
                i++;
            }

            if (order[j] == expected_order[i]) {
                i++;
            } else {
                stack[top] = order[j];
                top++;
            }

            if (top > 0 && stack[top - 1] != expected_order[i]) {
                possible = 0;
                break;
            }
        }

        if (possible) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }

    return 0;
}
