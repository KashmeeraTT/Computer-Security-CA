#include <stdio.h>

int main()
{
    int arr[3] = {1, 2, 3}; // Array of size 3 with valid indices 0, 1, and 2

    // Trying to access index 5, which is out-of-bounds and not checked.
    // This may lead to reading invalid data or undefined behavior.
    printf("%d\n", arr[5]); // No range checking here, unsafe access
    return 0;
}
