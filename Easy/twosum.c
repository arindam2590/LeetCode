
#include <stdio.h>
#include <stdlib.h>

// Function to find indices of two numbers
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 0;

    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {

            if (nums[i] + nums[j] == target) {
                int* result = (int*)malloc(2 * sizeof(int));

                if (result == NULL)
                    return NULL;

                result[0] = i;
                result[1] = j;

                *returnSize = 2;
                return result;
            }
        }
    }

    return NULL;
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 9;
    int returnSize = 0;

    int* result = twoSum(nums, numsSize, target, &returnSize);

    if (result != NULL) {
        printf("Indices: [%d, %d]\n", result[0], result[1]);
        printf("Values: [%d, %d]\n", nums[result[0]], nums[result[1]]);
        free(result);
    } else {
        printf("No solution found.\n");
    }

    return 0;
}
