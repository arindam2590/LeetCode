
#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort()
int compare(const void* a, const void* b) {
    int x = *(const int*)a;
    int y = *(const int*)b;
    return (x > y) - (x < y);
}

// Function to find all unique triplets
int** threeSum(int* nums, int numsSize, int* returnSize,
               int** returnColumnSizes) {

    *returnSize = 0;
    *returnColumnSizes = NULL;

    if (numsSize < 3)
        return NULL;

    // Sort the array
    qsort(nums, numsSize, sizeof(int), compare);

    int capacity = 16;
    int** result = malloc(capacity * sizeof(int*));
    *returnColumnSizes = malloc(capacity * sizeof(int));

    if (result == NULL || *returnColumnSizes == NULL) {
        free(result);
        free(*returnColumnSizes);
        *returnColumnSizes = NULL;
        return NULL;
    }

    for (int i = 0; i < numsSize - 2; i++) {

        // Skip duplicate first elements
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int left = i + 1;
        int right = numsSize - 1;

        while (left < right) {
            long long sum = (long long)nums[i] +
                            nums[left] + nums[right];

            if (sum == 0) {
                if (*returnSize == capacity) {
                    int newCapacity = capacity * 2;

                    int** newResult = realloc(
                        result, newCapacity * sizeof(int*));

                    if (newResult == NULL)
                        goto memory_error;

                    result = newResult;

                    int* newSizes = realloc(
                        *returnColumnSizes,
                        newCapacity * sizeof(int));

                    if (newSizes == NULL)
                        goto memory_error;

                    *returnColumnSizes = newSizes;
                    capacity = newCapacity;
                }

                result[*returnSize] = malloc(3 * sizeof(int));

                if (result[*returnSize] == NULL)
                    goto memory_error;

                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[left];
                result[*returnSize][2] = nums[right];

                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                left++;
                right--;

                // Skip duplicate elements
                while (left < right &&
                       nums[left] == nums[left - 1])
                    left++;

                while (left < right &&
                       nums[right] == nums[right + 1])
                    right--;
            }
            else if (sum < 0) {
                left++;
            }
            else {
                right--;
            }
        }
    }

    return result;

memory_error:
    for (int j = 0; j < *returnSize; j++)
        free(result[j]);

    free(result);
    free(*returnColumnSizes);
    *returnColumnSizes = NULL;
    *returnSize = 0;
    return NULL;
}

int main() {
    int nums[] = {-1, 0, 1, 2, -1, -4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int returnSize;
    int* returnColumnSizes;

    int** result = threeSum(nums, numsSize,
                            &returnSize, &returnColumnSizes);

    printf("Unique Triplets:\n");

    for (int i = 0; i < returnSize; i++) {
        printf("[%d, %d, %d]\n",
               result[i][0],
               result[i][1],
               result[i][2]);
    }

    // Free allocated memory
    for (int i = 0; i < returnSize; i++)
        free(result[i]);

    free(result);
    free(returnColumnSizes);

    return 0;
}
