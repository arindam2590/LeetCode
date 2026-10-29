
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the longest common prefix
char* longestCommonPrefix(char** strs, int strsSize) {
    int i = 0, j;

    while (strs[0][i] != '\0') {
        for (j = 1; j < strsSize; j++) {
            if (strs[j][i] != strs[0][i]) {
                break;
            }
        }

        if (j != strsSize) {
            break;
        }

        i++;
    }

    // Allocate memory for the common prefix
    char* result = (char*)malloc((i + 1) * sizeof(char));

    if (result == NULL)
        return NULL;

    strncpy(result, strs[0], i);
    result[i] = '\0';

    return result;
}

int main() {
    int strsSize;

    printf("Enter the number of strings: ");
    scanf("%d", &strsSize);

    if (strsSize < 1 || strsSize > 200) {
        printf("Invalid number of strings.\n");
        return 1;
    }

    char strs[200][201];
    char* strPtrs[200];

    printf("Enter %d strings:\n", strsSize);

    for (int i = 0; i < strsSize; i++) {
        scanf("%200s", strs[i]);
        strPtrs[i] = strs[i];
    }

    char* result = longestCommonPrefix(strPtrs, strsSize);

    if (result != NULL) {
        printf("Longest Common Prefix: \"%s\"\n", result);
        free(result);
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}
