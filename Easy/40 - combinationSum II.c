
#include <stdio.h>
#include <stdlib.h>

// Comparison function for sorting
int compare(const void* a, const void* b) {
    int x = *(const int*)a;
    int y = *(const int*)b;
    return (x > y) - (x < y);
}

// Recursive backtracking function
void backtrack(int* candidates, int candidatesSize,
               int target, int start, int* temp, int len,
               int*** result, int* returnSize,
               int** returnColumnSizes, int* capacity) {

    // Valid combination found
    if (target == 0) {
        if (*returnSize == *capacity) {
            int newCapacity = (*capacity) * 2;

            int** newResult = realloc(
                *result, newCapacity * sizeof(int*));
            int* newSizes = realloc(
                *returnColumnSizes, newCapacity * sizeof(int));

            if (newResult == NULL || newSizes == NULL) {
                // Simplified error handling for this example
                exit(EXIT_FAILURE);
            }

            *result = newResult;
            *returnColumnSizes = newSizes;
            *capacity = newCapacity;
        }

        (*result)[*returnSize] = malloc(len * sizeof(int));

        if ((*result)[*returnSize] == NULL)
            exit(EXIT_FAILURE);

        for (int i = 0; i < len; i++) {
            (*result)[*returnSize][i] = temp[i];
        }

        (*returnColumnSizes)[*returnSize] = len;
        (*returnSize)++;
        return;
    }

    for (int i = start; i < candidatesSize; i++) {

        // Skip duplicates at the same recursion level
        if (i > start && candidates[i] == candidates[i - 1])
            continue;

        // Stop if candidate exceeds remaining target
        if (candidates[i] > target)
            break;

        temp[len] = candidates[i];

        // Move to i + 1: each element is used only once
        backtrack(candidates, candidatesSize,
                  target - candidates[i], i + 1,
                  temp, len + 1, result,
                  returnSize, returnColumnSizes, capacity);
    }
}

// Function to find all unique combinations
int** combinationSum2(int* candidates, int candidatesSize,
                      int target, int* returnSize,
                      int** returnColumnSizes) {

    *returnSize = 0;

    // Sort the candidate array
    qsort(candidates, candidatesSize, sizeof(int), compare);

    int capacity = 16;

    int** result = malloc(capacity * sizeof(int*));
    *returnColumnSizes = malloc(capacity * sizeof(int));
    int* temp = malloc(candidatesSize * sizeof(int));

    if (result == NULL || *returnColumnSizes == NULL ||
        temp == NULL) {
        free(result);
        free(*returnColumnSizes);
        free(temp);
        *returnColumnSizes = NULL;
        return NULL;
    }

    backtrack(candidates, candidatesSize, target,
              0, temp, 0, &result, returnSize,
              returnColumnSizes, &capacity);

    free(temp);

    return result;
}

int main() {
    int candidates[] = {10, 1, 2, 7, 6, 1, 5};
    int candidatesSize =
        sizeof(candidates) / sizeof(candidates[0]);

    int target = 8;
    int returnSize = 0;
    int* returnColumnSizes = NULL;

    int** result = combinationSum2(
        candidates, candidatesSize, target,
        &returnSize, &returnColumnSizes);

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
