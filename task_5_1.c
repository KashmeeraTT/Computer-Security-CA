#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Secure function using canary to detect stack smashing
void secureFunction(char *input)
{
    char buffer[10];                           // Small buffer
    volatile unsigned int canary = 0xDEADBEEF; // Canary for stack protection

    // Copy input into buffer with strcpy. If input is too large, it may overflow
    strcpy(buffer, input);

    // Check if canary value was altered, indicating stack corruption
    if (canary != 0xDEADBEEF)
    {
        printf("Stack smashing detected!\n");
        exit(1); // Abort program if stack smashing detected
    }
}

int main()
{
    // Input that exceeds buffer size, triggering stack overflow vulnerability
    char largeInput[100] = "This input is too large and will cause a stack overflow.";

    // Call to secureFunction with oversized input, causing stack smashing
    secureFunction(largeInput);
    return 0;
}