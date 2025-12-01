# Type Casting and IEEE 754 Float Analysis

This project demonstrates type casting concepts and IEEE 754 floating-point representation analysis in C. It provides detailed breakdowns of how floating-point numbers are stored in memory according to the IEEE 754 standard.

## Project Overview

This assignment focuses on implementing functions to analyze floating-point numbers by:
- Breaking down IEEE 754 single-precision float components (sign bit, exponent, mantissa)
- Converting between floating-point and hexadecimal representations
- Demonstrating type casting using unions
- Performing arithmetic operations and analyzing the results

**Note**: Students are required to implement the `print_binary_int()` and `process_float()` functions according to the specifications below.

## Files

- `main.c` - Main source code containing the float analysis implementation
- `Makefile` - Build configuration for compiling the project
- `typecast` - Compiled executable (generated after building)

## Building the Project

### Prerequisites
- GCC compiler
- Make utility (optional, but recommended)

### Build Instructions

#### Using Make (Recommended)
```bash
# Build the project
make

# Build and run tests
make test

# Clean build artifacts
make clean
```

#### Manual Compilation
```bash
gcc -Wall -g -o typecast main.c
```

## Running the Program

After building, run the executable:
```bash
./typecast
```

## What's in main.c

The main source file contains several key components:

### Functions to Implement

**Students must implement the following two functions:**

1. **`print_binary_int(int num, int bits)`**
   - **Purpose**: Print the binary representation of an integer
   - **Parameters**: 
     - `num`: The integer to convert to binary
     - `bits`: Number of bits to display (e.g., 8 for exponent, 23 for mantissa)
   - **Requirements**:
     - Must print exactly `bits` number of binary digits
     - Should handle the conversion using bitwise operations
     - Print from most significant bit to least significant bit
     - No newline character should be printed by this function

2. **`process_float(float value)`**
   - **Purpose**: Analyze and display the IEEE 754 representation of a floating-point number
   - **Parameter**: `value` - The floating-point number to analyze
   - **Requirements**:
     - Use a union to access the bit representation of the float
     - Extract and display the sign bit (1 bit)
     - Extract and display the biased exponent (8 bits) and calculate the actual exponent
     - Extract and display the mantissa (23 bits)
     - Display the complete hexadecimal representation
     - Format output exactly as shown in the sample output below
     - Use the `print_binary_int()` function to display binary representations

### Provided Functions

3. **`main()`**
   - Already implemented - processes sample floating-point values
   - Demonstrates hexadecimal to float conversion using specific bit patterns
   - Calls `process_float()` on various test cases

### Key Concepts Demonstrated

- **IEEE 754 Format**: Shows how single-precision floats are stored with 1 sign bit, 8 exponent bits, and 23 mantissa bits
- **Type Casting with Unions**: Uses unions to access the same memory location as both float and uint32_t
- **Bit Manipulation**: Extracts individual components using bitwise operations
- **Number Base Conversions**: Displays numbers in decimal, binary, and hexadecimal formats

### Sample Output Format

The program should output detailed analysis for each number in this exact format:
```
========================================
Original number: [float_value]

1. IEEE 754 components:
   Sign bit: [0 or 1] ([positive or negative])
   Exponent: [actual_exponent] + 127 = [biased_exponent] = [8-bit_binary]₂
   Mantissa: [23-bit_binary]₂

2. Hexadecimal representation:
   0x[8-digit_hex]

```

**Important Formatting Notes**:
- Include the separator line of 40 equal signs
- Display the original number with 3 decimal places using `%.3f`
- Show both actual exponent (subtract 127 from biased) and biased exponent
- Use subscript ₂ to indicate binary representation
- Hexadecimal should be uppercase, 8 digits with leading zeros if needed
- Include a blank line after the hexadecimal representation

## Assignment Requirements

Students must implement the two required functions to demonstrate understanding of:
- **Bitwise Operations**: Using bit manipulation to extract IEEE 754 components
- **IEEE 754 Format**: Understanding the 32-bit layout (1 sign + 8 exponent + 23 mantissa)
- **Type Casting with Unions**: Accessing the same memory as different data types
- **Number Base Conversions**: Converting between decimal, binary, and hexadecimal
- **Memory Layout**: How floating-point numbers are stored in computer memory

## Implementation Hints

- Use bitwise shift (`>>`) and AND (`&`) operations to extract bit fields
- Remember that the IEEE 754 exponent is biased by 127
- The union technique allows you to treat the same 32 bits as both float and uint32_t
- Test your functions with the provided main() function to verify correct output formatting

## Compilation Flags

The Makefile uses the following GCC flags:
- `-Wall`: Enable all common warnings
- `-g`: Include debugging information

These flags help ensure code quality and enable debugging if needed.