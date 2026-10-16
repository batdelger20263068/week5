#include <stdio.h>
#include <string.h>

typedef struct {
    char digit[1001];
    int length;
} BigInt;

BigInt bigint(const char *value_str) {
    BigInt result;
    result.length = (int)strlen(value_str);
    strcpy(result.digit, value_str);
    return result;
}

void print(BigInt a) {
    printf("%s", a.digit);
}

int compare(BigInt a, BigInt b) {
    if (a.length > b.length) {
        return 1;
    }
    if (a.length < b.length) {
        return -1;
    }

    int result = strcmp(a.digit, b.digit);

    if (result > 0) {
        return 1;
    }
    if (result < 0) {
        return -1;
    }
    return 0;
}

int main(void) {
    char input1[1001];
    char input2[1001];

    printf("첫 번째 수를 입력하세요 : ");
    if (scanf("%1000s", input1) != 1) {
        return 0;
    }

    printf("두 번째 수를 입력하세요 : ");
    if (scanf("%1000s", input2) != 1) {
        return 0;
    }

    BigInt a = bigint(input1);
    BigInt b = bigint(input2);

    int result = compare(a, b);

    print(a);

    if (result > 0) {
        printf(" > ");
    } else if (result < 0) {
        printf(" < ");
    } else {
        printf(" = ");
    }

    print(b);
    printf("\n");

    return 0;
}
