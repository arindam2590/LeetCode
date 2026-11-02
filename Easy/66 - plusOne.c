
#include <stdio.h>
#include <stdlib.h>

// Function to increment the number by one
int* plusOne(int* digits, int digitsSize, int* returnSize) {

    // Traverse from the last digit
    for (int i = digitsSize - 1; i >= 0; i--) {

        if (digits[i] < 9) {
            digits[i]++;
            *returnSize = digitsSize;
            return digits;
        }

        // Carry to the previous digit
        digits[i] = 0;
    }

    // All digits were 9, so allocate a larger array
    int* result = (int*)malloc((digitsSize + 1) * sizeof(int));

    if (result == NULL) {
        *returnSize = 0;
        return NULL;
    }

    result[0] = 1;

    for (int i = 1; i <= digitsSize; i++) {
        result[i] = 0;
    }

    *returnSize = digitsSize + 1;

    return result;
}

int main() {
    int digits[] = {9, 9, 9};
    int digitsSize = sizeof(digits) / sizeof(digits[0]);
    int returnSize = 0;

    int* result = plusOne(digits, digitsSize, &returnSize);

    if (result == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Result: [");

    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);

        if (i < returnSize - 1)
            printf(", ");
    }

    printf("]\n");

    // Free memory only if a new array was allocated
    if (result != digits)
        free(result);

    return 0;
}
