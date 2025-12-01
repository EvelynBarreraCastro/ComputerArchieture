#include <stdio.h>
#include <stdint.h>
#include <math.h>

// Function to print binary representation of an integer
void print_binary_int(int num, int bits) {
    // Print from most significant bit to least significant bit
    for (int i = bits - 1; i >= 0; i--) {
        // Extract bit at position i using bitwise AND with a mask
        int bit = (num >> i) & 1;
        printf("%d", bit);
    }
}

// Function to process a single float value
void process_float(float value) {
    // Use union to access the same memory as both float and uint32_t
    union {
        float f;
        uint32_t i;
    } data;
    
    data.f = value;
    
    // Extract IEEE 754 components using bitwise operations
    // Sign bit: bit 31
    uint32_t sign = (data.i >> 31) & 0x1;
    
    // Exponent: bits 30-23 (8 bits)
    uint32_t biased_exponent = (data.i >> 23) & 0xFF;
    int actual_exponent = biased_exponent - 127;
    
    // Mantissa: bits 22-0 (23 bits)
    uint32_t mantissa = data.i & 0x7FFFFF;
    
    // Print the analysis
    printf("========================================\n");
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

int main() {
    // Array of floats to process
    float numbers[] = {42.375f, 56.625f};
    int count = sizeof(numbers) / sizeof(numbers[0]);
    
    for (int i = 0; i < count; i++) {
        process_float(numbers[i]);
    }

    // Convert hexadecimal bit patterns to floats using union
    union {
        uint32_t hex;
        float f;
    } converter;
    
    converter.hex = 0x4300E000;
    float X = converter.f;
    
    converter.hex = 0xC2C0C000;
    float Y = converter.f;
    
    float Z = X + Y;
    
    // Process the converted floats
    process_float(X);
    process_float(Y);
    process_float(Z);

    return 0;
}