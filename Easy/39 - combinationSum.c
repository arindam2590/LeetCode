
#include <stdio.h>
#include <stdlib.h>

// Recursive function to generate combinations
void backtrack(int* candidates, int candidatesSize,
               int target, int start, int* temp, int len,
               int** result, int* returnSize,
               int* returnColumnSizes) {

    // Valid combination found
    if (target == 0) {
        result[*returnSize] = malloc(len * sizeof(int));

        for (int i = 0; i < len; i++) {
            result[*returnSize][i] = temp[i];
        }

        returnColumnSizes[*returnSize] = len;
        (*returnSize)++;
        return;
    }

    for (int i = start; i < candidatesSize; i++) {

        if (candidates[i] > target)
            continue;

        temp[len] = candidates[i];

        // Same candidate can be chosen again
        backtrack(candidates, candidatesSize,
                  target - candidates[i], i,
                  temp, len + 1, result,
                  returnSize, returnColumnSizes);
    }
}

// Function to find all unique combinations
int** combinationSum(int* candidates, int candidatesSize,
                     int target, int* returnSize,
                     int** returnColumnSizes) {

    *returnSize = 0;

    // Problem guarantees fewer than 150 combinations
    int** result = malloc(150 * sizeof(int*));
    *returnColumnSizes = malloc(150 * sizeof(int));

    // Assumes candidates are positive integers
    int* temp = malloc((target + 1) * sizeof(int));

    if (!result || !*returnColumnSizes || !temp) {
        free(result);
        free(*returnColumnSizes);
        free(temp);
        *returnColumnSizes = NULL;
        return NULL;
    }

    backtrack(candidates, candidatesSize, target,
              0, temp, 0, result,
              returnSize, *returnColumnSizes);

    free(temp);

    return result;
}

int main() {
    int candidates[] = {2, 3, 6, 7};
    int candidatesSize = sizeof(candidates) / sizeof(candidates[0]);
    int target = 7;

    int returnSize = 0;
    int* returnColumnSizes = NULL;

    int** result = combinationSum(candidates, candidatesSize,
                                  target, &returnSize,
                                  &returnColumnSizes);

    if (result == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Unique Combinations:\n");

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
