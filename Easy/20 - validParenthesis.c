
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to check valid parentheses
bool isValid(char* s) {
    int n = strlen(s);
    char stack[n + 1];
    int top = -1;

    for (int i = 0; i < n; i++) {

        // Push opening brackets onto stack
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[++top] = s[i];
        }
        else {
            // No matching opening bracket
            if (top == -1)
                return false;

            char ch = stack[top--];

            // Check matching brackets
            if ((s[i] == ')' && ch != '(') ||
                (s[i] == '}' && ch != '{') ||
                (s[i] == ']' && ch != '[')) {
                return false;
            }
        }
    }

    // Stack must be empty
    return top == -1;
}

int main() {
    char s[10001];

    printf("Enter brackets: ");
    scanf("%10000s", s);

    if (isValid(s))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
