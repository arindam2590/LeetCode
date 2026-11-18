
#include <stdio.h>
#include <stdlib.h>

// Comparison function for sorting
int compare(const void* a, const void* b) {
    int x = *(const int*)a;
    int y = *(const int*)b;

    return (x > y) - (x < y);
}

// Function to find intersection of two arrays
int* intersection(int* nums1, int nums1Size,
                  int* nums2, int nums2Size,
                  int* returnSize) {

    *returnSize = 0;

    // Sort both arrays
    qsort(nums1, nums1Size, sizeof(int), compare);
    qsort(nums2, nums2Size, sizeof(int), compare);

    int size = nums1Size < nums2Size ? nums1Size : nums2Size;

    int* result = malloc(size * sizeof(int));

    if (result == NULL)
        return NULL;

    int i = 0, j = 0;

    while (i < nums1Size && j < nums2Size) {

        if (nums1[i] < nums2[j]) {
            i++;
        }
        else if (nums1[i] > nums2[j]) {
            j++;
        }
        else {
            // Add only unique elements
            if (*returnSize == 0 ||
                result[*returnSize - 1] != nums1[i]) {

                result[*returnSize] = nums1[i];
                (*returnSize)++;
            }

            i++;
            j++;
        }
    }

    return result;
}

int main() {
    int nums1[] = {4, 9, 5};
    int nums2[] = {9, 4, 9, 8, 4};

    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);

    int returnSize = 0;

    int* result = intersection(nums1, nums1Size,
                               nums2, nums2Size,
                               &returnSize);

    printf("Intersection: [");

    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);

        if (i < returnSize - 1)
            printf(", ");
    }

    printf("]\n");

    free(result);

    return 0;
}
