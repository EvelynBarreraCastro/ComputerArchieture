//    Programmer: Evelyn Barrera Castro (e.barreracastro@wsu.edu)
//    Due Date: November 13, 2025
//    Text Editor: Visual Stuido Code (MacOS)
//    Description: CPTS260 Homework 6 (part 1). This Homework assignment is intended
//                 to get ahold of 4 decimal numbers and find their IEEE 754 components                
//                 associated such as: Sign bit, Exponent, Mantissa, and Hexadecimal representation.



#include <stdio.h>      // needed for standard input/output 
#include <stdint.h>     // Standard Integer types, needed for int32_t
#include <math.h>       // Mathematical function header file


// Function to print binary representation of an integer
void print_binary_int(int num, int bits) {
    // print from most significant but to least significant bit
    for (int i = bits - 1; i >=0; i--) {
        // Extract the bit at position i using the bitwise AND with a mask
        int bit = (num >> i) & 1;
            printf("%d", bit);
    }
}



// Function to process a single float value
void process_float(float value) {
    // using the union to access the same memory as both float and uint32_t
    union {
        float f;
        uint32_t i;
    } data;

    data.f = value;

    // Extract IEEE 754 components using bitwise operations
    // Sign bit: bit 31
    uint32_t sign = (data.i >> 31) & 0xFF;

    // Exponent: bits 30-23 (8 bits)
    uint32_t biased_exponent = (data.i >> 23) & 0xFF;
    int actual_exponent = biased_exponent - 127;

    // Mantissa: bits 22-0 (23 bits)
    uint32_t mantissa = data.i & 0x7FFFFF;

    // Print the analysis
    printf("\n");
    printf("========================================\n");
    printf("\n");
    printf("Original number: %.3f\n", value);
    printf("\n");
    printf("1. IEEE 754 components:\n");
    printf("   Sign bit: %u (%s)\n", sign, sign ? "negative" : "positive");
    printf("   Exponent: %d + 127 = %u = ", actual_exponent, biased_exponent);
    print_binary_int(biased_exponent, 8);
    printf("₂\n");
    printf("   Mantissa: ");
    print_binary_int(mantissa, 23);
    printf("₂\n");
    printf("\n");
    printf("2. Hexadecimal representation:\n");
    printf("   0x%08X\n", data.i);
    printf("\n");
}


// Main driver program: 
int main() {
    // Array of floats to process
    float numbers[] = {42.375f, 56.625f};
    int count = sizeof(numbers) / sizeof(numbers[0]);
    
    for (int i = 0; i < count; i++) {
        process_float(numbers[i]);
    }

    // Convert hexadecimal bit patterns to floats using union
    // float X = 0x4300E000;
    // float Y = 0xC2C0C000;
    // float Z = X + Y

    union {
        uint32_t hex;
        float f;
    }   converter; 

    converter.hex = 0x4300E000;
    float X = converter.f; 

    converter.hex = 0xC2C0C000;
    float Y = converter.f; 
    
    // Adding the 2 hexadecimal values together 
    // The Storing the value into Z
    float Z = X + Y; 

    // uncomment the following after implementing the union conversion
    process_float(X);
    process_float(Y);
    process_float(Z);

    return 0;
}


/*  
*   Final output in Visual Studio Code is: 
*
*   =======================================
*
*   Original number: 42.375
*
*    1. IEEE 754 components:
*    Sign bit: 0 (positive)
*    Exponent: 5 + 127 = 132 = 10000100₂
*    Mantissa: 01010011000000000000000₂
*
*    2. Hexadecimal representation:
*    0x42298000
*
*
*    ========================================
*
*    Original number: 56.625
*
*    1. IEEE 754 components:
*    Sign bit: 0 (positive)
*    Exponent: 5 + 127 = 132 = 10000100₂
*    Mantissa: 11000101000000000000000₂
*
*    2. Hexadecimal representation:
*    0x42628000
*
*
*    ========================================
*
*    Original number: 128.875
*
*    1. IEEE 754 components:
*    Sign bit: 0 (positive)
*    Exponent: 7 + 127 = 134 = 10000110₂
*    Mantissa: 00000001110000000000000₂
*
*    2. Hexadecimal representation:
*    0x4300E000
*
*
*   ========================================
*
*    Original number: -96.375
*
*   1. IEEE 754 components:
*    Sign bit: 1 (negative)
*    Exponent: 6 + 127 = 133 = 10000101₂
*    Mantissa: 10000001100000000000000₂
*
*    2. Hexadecimal representation:
*    0xC2C0C000
*
*
*    ========================================
*
*   Original number: 32.500
*
*    1. IEEE 754 components:
*    Sign bit: 0 (positive)
*    Exponent: 5 + 127 = 132 = 10000100₂
*    Mantissa: 00000100000000000000000₂
*
*    2. Hexadecimal representation:
*   0x42020000
*/