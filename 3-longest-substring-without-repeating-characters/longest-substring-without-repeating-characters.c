#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int last[256];
    for (int i = 0; i < 256; i++) last[i] = -1;

    int best = 0;
    int left = 0;

    for (int right = 0; s[right] != '\0'; right++) {
        unsigned char c = (unsigned char)s[right];

        if (last[c] >= left) left = last[c] + 1; 

        last[c] = right;

        int len = right - left + 1;
        if (len > best) best = len;
    }

    return best;
}
