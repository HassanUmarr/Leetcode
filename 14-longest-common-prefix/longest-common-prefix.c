char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return "";

    // Use the first string, we will shrink it as needed
    char* prefix = strs[0];

    // Compare prefix with each string
    for (int i = 1; i < strsSize; i++) {
        int j = 0;

        // Compare characters one by one
        while (prefix[j] != '\0' && strs[i][j] != '\0' && prefix[j] == strs[i][j]) {
            j++;
        }

        // Cut prefix at first mismatch
        prefix[j] = '\0';

        // If prefix becomes empty, no common prefix
        if (j == 0) {
            return "";
        }
    }

    return prefix;
}