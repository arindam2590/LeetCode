
#include <stdio.h>
#include <stdlib.h>

// Function to find missing numbers
int* findDisappearedNumbers(int* nums, int numsSize,
                            int* returnSize) {

    *returnSize = 0;

    int* result = malloc(numsSize * sizeof(int));

    if (result == NULL)
        return NULL;

    // Mark numbers that are present
    for (int i = 0; i < numsSize; i++) {

        int index = abs(nums[i]) - 1;

        if (nums[index] > 0) {
            nums[index] = -nums[index];
        }
    }

    // Find indices that remain positive
    for (int i = 0; i < numsSize; i++) {

        if (nums[i] > 0) {
            result[*returnSize] = i + 1;
            (*returnSize)++;
        }
    }

    return result;
}

int main() {
    int nums[] = {4, 3, 2, 7, 8, 2, 3, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize = 0;

    int* result = findDisappearedNumbers(
        nums, numsSize, &returnSize);

    if (result == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Missing Numbers: [");

    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);

        if (i < returnSize - 1)
            printf(", ");
    }

    printf("]\n");

    free(result);

    return 0;
}
