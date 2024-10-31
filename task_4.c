#include <stdio.h>
#include <string.h>

// Declare function pointer that could be exploited if overwritten
void (*func_ptr)();

// Vulnerable function that allows attacker to potentially modify func_ptr
void vulnerableFunction(char *input)
{
    char buffer[10]; // Small buffer for user input
    func_ptr = NULL; // Set function pointer to NULL initially

    // Copying input into buffer without bounds checking.
    // A long enough input could overwrite func_ptr, enabling code execution.
    strcpy(buffer, input);

    // If func_ptr was modified by overflow, it might now point to attacker code
    if (func_ptr)
    {
        func_ptr(); // Executes code at func_ptr, if not NULL
    }
}

int main()
{
    // Sample payload intended to exploit buffer overflow and modify func_ptr
    char maliciousInput[50] = "malicious payload";

    // Call vulnerable function with malicious input
    vulnerableFunction(maliciousInput);
    return 0;
}
