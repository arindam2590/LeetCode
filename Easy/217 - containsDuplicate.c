
#include <stdio.h>

// Function to find the single number
int singleNumber(int* nums, int numsSize) {

    int result = 0;

    for (int i = 0; i < numsSize; i++) {
        result = result ^ nums[i];
    }

    return result;
}

int main() {
    int nums[] = {4, 1, 2, 1, 2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int result = singleNumber(nums, numsSize);

    printf("Single Number: %d\n", result);

    return 0;
}
