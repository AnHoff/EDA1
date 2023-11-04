#include <stdio.h>
#include <string.h>

// Definição da estrutura da pilha
typedef struct {
    char data[100000];
    int top;
} Stack;

// Função para inicializar a pilha
void initialize(Stack *stack) {
    stack->top = -1;
}

// Função para empilhar um caractere
void push(Stack *stack, char c) {
    stack->data[++stack->top] = c;
}

// Função para desempilhar um caractere
char pop(Stack *stack) {
    return stack->data[stack->top--];
}

// Função para verificar se uma cadeia é bem definida
int isWellDefined(char *expression) {
    Stack stack;
    initialize(&stack);

    int len = strlen(expression);

    for (int i = 0; i < len; i++) {
        char c = expression[i];

        if (c == '(' || c == '[' || c == '{') {
            push(&stack, c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (stack.top == -1) {
                return 0; // A cadeia não é bem definida
            }

            char top = pop(&stack);

            if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
                return 0; // A cadeia não é bem definida
            }
        }
    }

    return stack.top == -1 ? 1 : 0;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        char expression[100000];
        scanf("%s", expression);

        if (isWellDefined(expression)) {
            printf("S\n");
        } else {
            printf("N\n");
        }
    }

    return 0;
}
