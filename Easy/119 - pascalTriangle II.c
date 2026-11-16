
#include <stdio.h>
#include <stdlib.h>

// Function to generate the specified row
int* getRow(int rowIndex, int* returnSize) {

    *returnSize = rowIndex + 1;

    int* result = (int*)calloc(*returnSize, sizeof(int));

    if (result == NULL) {
        *returnSize = 0;
        return NULL;
    }

    result[0] = 1;

    for (int i = 1; i <= rowIndex; i++) {

        // Update elements from right to left
        for (int j = i; j > 0; j--) {
            result[j] = result[j] + result[j - 1];
        }
    }

    return result;
}

int main() {
    int rowIndex;
    int returnSize = 0;

    printf("Enter row index: ");
    scanf("%d", &rowIndex);

    if (rowIndex < 0 || rowIndex > 33) {
        printf("Invalid row index.\n");
        return 1;
    }

    int* result = getRow(rowIndex, &returnSize);

    if (result == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Pascal's Triangle Row %d: [", rowIndex);

    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);

        if (i < returnSize - 1)
            printf(", ");
    }

    printf("]\n");

    free(result);

    return 0;
}
