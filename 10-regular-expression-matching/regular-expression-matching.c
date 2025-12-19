#include <stdbool.h>
#include <string.h>

bool isMatch(char* s, char* p) {
    int n = (int)strlen(s);
    int m = (int)strlen(p);

    // dp[i][j] = does s[0..i-1] match p[0..j-1] ?
    bool dp[21][21] = {0};
    dp[0][0] = true;

    // Patterns like a*, a*b*, a*b*c* can match empty string
    for (int j = 2; j <= m; j++) {
        if (p[j - 1] == '*') dp[0][j] = dp[0][j - 2];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (p[j - 1] == '*') {
                dp[i][j] = dp[i][j - 2];
                char prev = p[j - 2];
                if (prev == '.' || prev == s[i - 1]) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                }
            } else {
                // direct match or '.'
                if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
    }

    return dp[n][m];
}
