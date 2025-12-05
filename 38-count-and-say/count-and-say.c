#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* countAndSay(int n) {
    if (n == 1) {
        char *base = malloc(2);
        strcpy(base, "1");
        return base;
    }

    char *prev = countAndSay(n - 1);
    int len = strlen(prev);
    char *result = malloc(len * 2 + 1);

    int idx = 0;
    int i = 0;

    while (i < len) {
        char digit = prev[i];
        int count = 0;

        while (i < len && prev[i] == digit) {
            count++;
            i++;
        }

        idx += sprintf(result + idx, "%d%c", count, digit);
    }

    result[idx] = '\0';
    free(prev);

    return result;
}
