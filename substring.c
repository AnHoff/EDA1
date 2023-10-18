#include <stdio.h>
#include <string.h>

int maiorSub(char *str, char *sub, int strPos, int subPos, int maxSubLen) {
    if (str[strPos] == '\0') {
        return maxSubLen;
    }
    
    if (str[strPos] == sub[subPos]) {
        subPos++;
        
        if (sub[subPos] == '\0') {
            return maiorSub(str, sub, strPos + 1, 0, subPos);
        }
    } else {
        subPos = 0;
    }
    
    int atualSubLen = maiorSub(str, sub, strPos + 1, subPos, maxSubLen);

    return (atualSubLen > maxSubLen) ? atualSubLen : maxSubLen;
}

int main() {
    char str[101];
    char sub[101];
    scanf("%s", str);
    scanf("%s", sub);

    int resultado = maiorSub(str, sub, 0, 0, 0);
    printf("%d\n", resultado);

    return 0;
}
