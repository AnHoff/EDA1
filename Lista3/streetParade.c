#include <stdio.h>
#include <stdlib.h>

int main() {
    while (1) {
        int n;
        scanf("%d", &n);

        if (n == 0) {
            break;
        }

        int *order = (int *)malloc(n * sizeof(int));

        for (int i = 0; i < n; i++) {
            scanf("%d", &order[i]);
        }

        int expected_order = 1;
        int *stack = (int *)malloc(n * sizeof(int));
        int top = -1;

        for (int i = 0; i < n; i++) {
            // Push love mobiles to the stack until the expected one is at the top
            while (top != -1 && stack[top] == expected_order) {
                top--;
                expected_order++;
            }

            // If the current love mobile matches the expected one, pop it
            if (order[i] == expected_order) {
                expected_order++;
            }
            // Otherwise, push it to the stack
            else {
                stack[++top] = order[i];
            }
        }

        // Check if the remaining love mobiles in the stack can be brought into order
        while (top != -1 && stack[top] == expected_order) {
            top--;
            expected_order++;
        }

        // Output the result for the current test case
        if (top == -1) {
            printf("yes\n");
        } else {
            printf("no\n");
        }

        free(order);
        free(stack);
    }

    return 0;
}
