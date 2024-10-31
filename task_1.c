#include <stdio.h>
#include <string.h>

// Function vulnerable to stack smashing due to lack of bounds checking
void vulnerableFunction(char *input)
{
    char buffer[10]; // Small buffer that can hold only 10 characters

    // strcpy copies input directly into buffer without checking size,
    // allowing overflow if input is longer than buffer (10 chars).
    strcpy(buffer, input);

    printf("Buffer contents: %s\n", buffer);
}

int main()
{
    // Input that exceeds buffer size, triggering stack overflow vulnerability
    char largeInput[100] = "This input is too large and will cause a stack overflow.";

    // Call to vulnerableFunction with oversized input, causing stack smashing
    vulnerableFunction(largeInput);
    return 0;
}
