#include <stdio.h>
#include <string.h>

// Function demonstrates how overflow in one variable affects adjacent variables
void overflow()
{
    int x = 5;      // Regular integer variable
    char buffer[4]; // Small character buffer with limited capacity
    int y = 10;     // Adjacent variable to buffer in memory

    printf("x = %d, y = %d\n", x, y);

    // strcpy copies data into buffer without bounds checking.
    // Input larger than buffer size will overwrite x and y due to memory adjacency.
    strcpy(buffer, "Overflow in buffer may affect y");

    // Printing values of x and y after overflow. x and y may change unexpectedly.
    printf("x = %d, y = %d\n", x, y);
}

int main()
{
    // Call function to demonstrate overflow and adjacent variable exploitation
    overflow();
    return 0;
}
