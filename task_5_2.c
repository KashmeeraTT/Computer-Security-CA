#include <stdio.h>

int main()
{
    int arr[3] = {1, 2, 3}; // Array of size 3, accessible with indices 0, 1, 2
    int index = 5;          // Index to be accessed

    // Check if the index is within array bounds before accessing
    if (index >= 0 && index < 3)
    {
        printf("%d\n", arr[index]); // Safe access if index is valid
    }
    else
    {
        printf("Index out of bounds\n"); // Error message for out-of-bounds access
    }

    return 0;
}
