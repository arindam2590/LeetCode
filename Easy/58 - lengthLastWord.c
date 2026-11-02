
#include <stdio.h>
#include <string.h>

// Function to find the length of the last word
int lengthOfLastWord(char* s) {
    int n = strlen(s);
    int length = 0;
    int i = n - 1;

    // Skip trailing spaces
    while (i >= 0 && s[i] == ' ') {
        i--;
    }

    // Count characters of the last word
    while (i >= 0 && s[i] != ' ') {
        length++;
        i--;
    }

    return length;
}

int main() {
    char s[10001];

    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);

    int length = lengthOfLastWord(s);

    printf("Length of Last Word: %d\n", length);

    return 0;
}
