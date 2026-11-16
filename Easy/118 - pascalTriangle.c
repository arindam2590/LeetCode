
#include <stdio.h>
#include <stdlib.h>

// Function to generate Pascal's Triangle
int** generate(int numRows, int* returnSize,
               int** returnColumnSizes) {

    *returnSize = numRows;

    int** result = malloc(numRows * sizeof(int*));
    *returnColumnSizes = malloc(numRows * sizeof(int));

    if (result == NULL || *returnColumnSizes == NULL) {
        free(result);
        free(*returnColumnSizes);
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    for (int i = 0; i < numRows; i++) {

        // Each row contains i + 1 elements
        result[i] = malloc((i + 1) * sizeof(int));

        if (result[i] == NULL) {
            for (int j = 0; j < i; j++)
                free(result[j]);

            free(result);
            free(*returnColumnSizes);
            *returnColumnSizes = NULL;
            *returnSize = 0;
            return NULL;
        }

        (*returnColumnSizes)[i] = i + 1;

        for (int j = 0; j <= i; j++) {

            // First and last elements are always 1
            if (j == 0 || j == i) {
                result[i][j] = 1;
            }
            else {
                result[i][j] = result[i-1][j-1]
                             + result[i-1][j];
            }
        }
    }

    return result;
}

int main() {
    int numRows = 5;
    int returnSize = 0;
    int* returnColumnSizes = NULL;

    int** result = generate(numRows, &returnSize,
                            &returnColumnSizes);

    if (result == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Pascal's Triangle:\n");

    for (int i = 0; i < returnSize; i++) {
        printf("[");

        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d", result[i][j]);

            if (j < returnColumnSizes[i] - 1)
                printf(", ");
        }

        printf("]\n");
    }

    // Free allocated memory
    for (int i = 0; i < returnSize; i++)
        free(result[i]);

    free(result);
    free(returnColumnSizes);

    return 0;
}
