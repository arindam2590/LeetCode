
#include <stdio.h>

// Function to remove all occurrences of val
int removeElement(int* nums, int numsSize, int val) {
    int k = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
}

int main() {
    int nums[] = {3, 2, 2, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int val = 3;

    int k = removeElement(nums, numsSize, val);

    printf("Number of remaining elements: %d\n", k);

    printf("Array after removing elements: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", nums[i]);
    }

    printf("\n");

    return 0;
}
