#include <stdio.h>
#include <string.h>

int getDigitSum(char *num) {
    int sum = 0;
    int length = strlen(num);
    for (int i = 0; i < length; i++) {
        sum += num[i] - '0';
    }
    return sum;
}

int eMultNove(char *num) {
    int sum = getDigitSum(num);
    return (sum % 9 == 0);
}

int grauNove(char *num) {
    if (!eMultNove(num)) {
        return -1;
    }

    if (strcmp(num, "9") == 0) {
        return 1;
    }

    char temp[1005];
    sprintf(temp, "%d", getDigitSum(num));
    return 1 + grauNove(temp);
}

int main() {
    char num[1005];

    while (1) {
        scanf("%s", num);

        if (strcmp(num, "0") == 0) {
            break;
        }

        int eMult = eMultNove(num);
        int degree = -1;

        if (eMult) {
            degree = grauNove(num);
        }

        if (eMult) {
            printf("%s is a multiple of 9 and has 9-degree %d.\n", num, degree);
        } else {
            printf("%s is not a multiple of 9.\n", num);
        }
    }

    return 0;
}
