#include <stdio.h>
#include <string.h>

// Safe function that prevents overflow using strncpy for bounded copying
void safeFunction(const char *input)
{
    char buffer[10]; // Small buffer with limited capacity

    // Copy only up to buffer size minus one, ensuring it won't overflow
    strncpy(buffer, input, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0'; // Null-terminate to prevent overflow

    printf("Buffer contents: %s\n", buffer);
}

int main()
{
    // Test function with safe input
    safeFunction("Safe input");
    return 0;
}
