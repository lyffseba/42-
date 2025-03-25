#include <unistd.h> // For write

// Function to write a number
void write_number(int n) {
    char num[4];    // Space for numbers up to 100
    int len = 0;
    while (n > 0) { // Convert number to digits
        num[len] = n % 10 + '0'; // Get digit
        n = n / 10;              // Remove last digit
        len = len + 1;
    }
    while (len > 0) { // Write digits in reverse
        len = len - 1;
        write(1, &num[len], 1);
    }
    write(1, "\n", 1); // New line
}

int main() {
    int i = 1;          // Start at 1
    while (i <= 100) {  // Loop until 100
        if (i % 4 == 0 && i % 7 == 0) write(1, "FourSeven\n", 10); // Multiples of 4 AND 7
        else if (i % 4 == 0) write(1, "Four\n", 5);             // Multiples of 4
        else if (i % 7 == 0) write(1, "Seven\n", 6);            // Multiples of 7
        else write_number(i); // Other numbers
        i = i + 1; // Increase i
    }
    return 0;
}
