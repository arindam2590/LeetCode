
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to generate summary ranges
char** summaryRanges(int* nums, int numsSize, int* returnSize) {

    *returnSize = 0;

    if (numsSize == 0)
        return NULL;

    char** result = malloc(numsSize * sizeof(char*));

    if (result == NULL)
        return NULL;

    int i = 0;

    while (i < numsSize) {
        int start = nums[i];

        // Find the end of the consecutive range
        while (i + 1 < numsSize &&
               (long long)nums[i + 1] - nums[i] == 1) {
            i++;
        }

        int end = nums[i];

        // Allocate memory for the range string
        result[*returnSize] = malloc(32 * sizeof(char));

        if (result[*returnSize] == NULL) {
            for (int j = 0; j < *returnSize; j++)
                free(result[j]);

            free(result);
            *returnSize = 0;
            return NULL;
        }

        if (start == end) {
            sprintf(result[*returnSize], "%d", start);
        }
        else {
            sprintf(result[*returnSize], "%d->%d", start, end);
        }

        (*returnSize)++;
        i++;
    }

    return result;
}

int main() {
    int nums[] = {0, 1, 2, 4, 5, 7};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize = 0;

    char** result = summaryRanges(nums, numsSize, &returnSize);

    printf("Summary Ranges: [");

    for (int i = 0; i < returnSize; i++) {
        printf("\"%s\"", result[i]);

        if (i < returnSize - 1)
            printf(", ");
    }

    printf("]\n");

    // Free allocated memory
    for (int i = 0; i < returnSize; i++)
        free(result[i]);

    free(result);

    return 0;
}
