
#include <stdio.h>

// Function to find the missing number
int missingNumber(int* nums, int numsSize) {

    int result = numsSize;

    for (int i = 0; i < numsSize; i++) {
        result = result ^ i ^ nums[i];
    }

    return result;
}

int main() {
    int nums[] = {3, 0, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int result = missingNumber(nums, numsSize);

    printf("Missing Number: %d\n", result);

    return 0;
}
