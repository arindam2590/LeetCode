
#include <stdio.h>
#include <limits.h>

// Function to find the third distinct maximum
int thirdMax(int* nums, int numsSize) {

    long long first = LLONG_MIN;
    long long second = LLONG_MIN;
    long long third = LLONG_MIN;

    for (int i = 0; i < numsSize; i++) {
        long long num = nums[i];

        // Skip duplicate values
        if (num == first || num == second || num == third)
            continue;

        if (num > first) {
            third = second;
            second = first;
            first = num;
        }
        else if (num > second) {
            third = second;
            second = num;
        }
        else if (num > third) {
            third = num;
        }
    }

    // Return maximum if third distinct maximum does not exist
    if (third == LLONG_MIN)
        return (int)first;

    return (int)third;
}

int main() {
    int nums[] = {2, 2, 3, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int result = thirdMax(nums, numsSize);

    printf("Third Maximum Number: %d\n", result);

    return 0;
}
