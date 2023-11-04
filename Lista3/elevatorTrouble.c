#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct {
    int floor;
    int buttonPushes;
} State;

int minButtonPushes(int f, int s, int g, int u, int d) {
    bool *visited = (bool *)malloc((f + 1) * sizeof(bool));
    for (int i = 1; i <= f; i++) {
        visited[i] = false;
    }

    State *queue = (State *)malloc((f + 1) * sizeof(State));
    int front = 0, rear = 0;

    queue[rear].floor = s;
    queue[rear].buttonPushes = 0;
    rear++;

    visited[s] = true;

    while (front < rear) {
        State current = queue[front];
        front++;

        if (current.floor == g) {
            free(visited);
            free(queue);
            return current.buttonPushes;
        }

        int nextFloorUp = current.floor + u;
        int nextFloorDown = current.floor - d;

        if (nextFloorUp <= f && !visited[nextFloorUp]) {
            queue[rear].floor = nextFloorUp;
            queue[rear].buttonPushes = current.buttonPushes + 1;
            rear++;
            visited[nextFloorUp] = true;
        }

        if (nextFloorDown >= 1 && !visited[nextFloorDown]) {
            queue[rear].floor = nextFloorDown;
            queue[rear].buttonPushes = current.buttonPushes + 1;
            rear++;
            visited[nextFloorDown] = true;
        }
    }

    free(visited);
    free(queue);
    return -1;
}

int main() {
    int f, s, g, u, d;
    scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);

    int result = minButtonPushes(f, s, g, u, d);

    if (result == -1) {
        printf("use the stairs\n");
    } else {
        printf("%d\n", result);
    }

    return 0;
}
