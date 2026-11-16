
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Comparison function for sorting
int compare(const void* a, const void* b) {
    int x = *(const int*)a;
    int y = *(const int*)b;
    return (x > y) - (x < y);
}

// Function to find the closest sum of three numbers
int threeSumClosest(int* nums, int numsSize, int target) {

    // Sort the array
    qsort(nums, numsSize, sizeof(int), compare);

    int closestSum = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < numsSize - 2; i++) {

        int left = i + 1;
        int right = numsSize - 1;

        while (left < right) {

            int sum = nums[i] + nums[left] + nums[right];

            // Update closest sum
            if (abs(sum - target) < abs(closestSum - target)) {
                closestSum = sum;
            }

            // Exact match found
            if (sum == target) {
                return sum;
            }
            else if (sum < target) {
                left++;
            }
            else {
                right--;
            }
        }
    }

    return closestSum;
}

int main() {
    int nums[] = {-1, 2, 1, -4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 1;

    int result = threeSumClosest(nums, numsSize, target);

    printf("Closest Sum: %d\n", result);

    return 0;
}
