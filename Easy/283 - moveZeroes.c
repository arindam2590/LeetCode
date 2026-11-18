
#include <stdio.h>

// Function to move all zeros to the end
void moveZeroes(int* nums, int numsSize) {

    int k = 0;

    // Move non-zero elements to the beginning
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[k] = nums[i];
            k++;
        }
    }

    // Fill remaining positions with zeros
    while (k < numsSize) {
        nums[k] = 0;
        k++;
    }
}

int main() {
    int nums[] = {0, 1, 0, 3, 12};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    moveZeroes(nums, numsSize);

    printf("Array after moving zeroes: [");

    for (int i = 0; i < numsSize; i++) {
        printf("%d", nums[i]);

        if (i < numsSize - 1)
            printf(", ");
    }

    printf("]\n");

    return 0;
}
