# MIPS Assembly
Consider the following questions read the instructions carefully.


## Hexadecimal Basics. (5 Points)
Test your understanding of hexadecimal.

1. How many symbols are used in hexadecimal?
- The hexadecimal is a base 16 number system --> hex means 6 and decimal is 10, giving us 10 + 6 = 16. 

2. What are all the symbols used in hexadecimal?
- Hexadecimal uses values 0 to 9 and A through F.
- Values 0 through 9 represent themselves whereas ...
- A = 10
- B = 11
- C = 12
- D = 13
- E = 14
- F = 15 

3. Convert the following hexadecimal numbers to decimal:
- It is worth noting that when performing these calculations the "OX" is the prefix used to denote this as a hexadecmial & not a decimal.
    & that from right to left the base is 16 and we raise it to the counting power of 0,1,2,3, ... and so on and so forth. 

- 0x1A = 16 + 10 = 26
- 0xFF = 15 + 240 = 255
- 0xABC = 2560 + 176 + 12 = 2748

4. Convert the following decimal numbers to hexadecimal: 
- It is worth noting here that when converting decimals to hexadecimals, we start off by dividing the number by 16. This gives us 2 values a 
    quotient and a reminder. The first remainder is the outtermost right value and then we repeat the process over and over again until our 
    quotient is zero and through every step we use the reminder and convert that to its corresponding hexadecimal value. 

- 27: 27 ÷ 16 = 1 w/ R = 11 --> B
    1 ÷ 16 = 0 w/ R = 1 --> 1
    Final ANS: 0X1B

- 255: 255 ÷ 15 = 15 w/reminder 15 --> F
    15 ÷ 16 = 0 w/remainder 15 --> F
    Final ANS: 0XFF 

- 2748: 2748 ÷ 16 = 171 w/ R = 12 --> C 
    171 ÷ 16 = 10 w/ R = 11 --> B 
    10 ÷ 16 = 0 w/ R = 10 --> A 
    Final ANS: 0XABC



## Convert MIPS Assembly to C code. (20 Points)
    1. Convert the following assembly to a single C statement.

    ```
    addi $t0, $s0, -2       # $t0 = ($s0 + -2)
    sll $t1, $t0, 2         # $t1 = (($s0 + -2) * 4)                    NOTE: shift logical left ... shifts bits in $t0 by 2 (2^2 = 4) & stores it inside $t1. 
    addi $t0, $s0, 3.       # $t0 = ($s0 + 3)                           NOTE: This overwrittes the first line of code
    add $s1, $t0, $t1       # $s1 = ($s0 + 3) + (($s0 + -2) * 4) 
    ```
    - c code: 
    s1 = (s0 + 3) + ((s0 - 2) * 4);


    2. Consider the register value for `$s0` is 5. What's the value of `$s1` after the instructions?
    - If we made that change we would have a new value of 20 for $s1.
    proof:
    ```
    addi $s0, $zero, 5      # $s0 = 0 + 5 
    addi $t0, $s0, -2       # $t0 = 5 + -2 = 3
    sll $t1, $t0, 2         # $t1 = 3 * 4          
    addi $t0, $s0, 3.       # $t0 = 5 + 3 
    add $s1, $t0, $t1       # $s1 = (5 + 3) + (3 * 4) = 8 + 12 = 20
    ```

    3. Convert the following assembly to a single C statement.

    ```
    addi $t0, $s0, 0        # $t0 = $s0 + 0 = 0
    addi $t1, $zero, 1      # $t1 = 0 + 1 = 1
    and  $t3, $t1, $t0      # $t3 = 1 & 0
    slt  $s1, $t0, $t3      # $s1 = (0 < (1 & 0)) ? 1=True : 0=Flase
    ```
    - C Statement: 
    s1 = (s0 < (1 && s0) ? 1 : 0);


    4. Consider the register value for `$s0` is 4. What's the value of `$s1` after the instructions?
        - The value of $s1 is then changed to become 0. 
    proof:
    ```
    addi $s0, $s0, 4        # $s0 = $s0 + 4 = 4
    addi $t0, $s0, 0        # $t0 = 4 + 0 = 4
    addi $t1, $zero, 1      # $t1 = 0 + 1 = 1
    and  $t3, $t1, $t0      # $t3 = 1 & 0
    slt  $s1, $t0, $t3      # $s1 = (4 < (1 & 0)) ? 1=True : 0=Flase
    ```



## Convert the C code to MIPS Assembly. (30 Points)
    1. Convert the C statement into a set of commented MIPS assembly code.

    ```
    y = (c + d) * e;    
    ```
        
    # PUT ASSEMBLY INSTRUCTIONS HERE.
    Assume `$s0` is `c`
            `$s1` is `d`
            `$s2` is `e`
            `$s3` is `y`

    ```
    # MIPS Registers: $s0 = c, $s1 = d, $s2 = e, $s3 = y
    add $t0, $s0, $s1       # $t0 = (c + d)
    mul $s3, $t0, $s2       # y = (c + d) * e
    ```

2. Convert the C statement into a set of commented MIPS assembly code.

    ```
    b[i-2] = a[i+1] + a[4];
    ```
    Assume `$s0` contains the address of the array `a` 
           `$s1` contains the address of the array `b`
           `$s2` contains the integer variable `i`
    NOTE: `$t*` registers are used for temporary storage, if any are needed. 
    All variables and arrays are integers.

    Supplemental Note: **Why shift left by 2?**
    Shifting left by 2 is the same as **multiplying by 4**:
        Example: $t0 = 4 (binary: 0100)
        Shift left by 2:
        Before: 0000 0100  (4)
        After:  0001 0000  (16)  
        (4 << 2) = (4 × 2²) = (4 × 4) = 16 ✓

    ```
    # PUT ASSEMBLY INSTRUCTIONS HERE.
        
        #Step 1: Find address of a[i+1]
        addi $t0, $s2, 1            # $t0 = i + 1
        sll $t0, $t0, 2             # $t0 = (i + i) * 4   --> (2^2 = 4)
        add $t0, $t0, $s0           # $t0 = address of a[i + 1]

        #Step 2: Find value of a[i + 1]
        lw $t1, 0($t0)              # $t1 = a[ i + 1]
                                    # offset(base_register) ---> Load word from address ($t0 + 0)  
                                    # we use zero because "no offset, use the address as-is"

        #Step 1: Find address of a[4]
        li $t2, 16                  # $t2 = index 4 * bytes 4 = 16
        add $t2, $t2, $s0           # $t2 = address of a[4]

        #Step 2: Find value of a[4]
        lw $t3, 0($t2)              # $t3 = a[4] = offset(base_register)

        #Step 3: Add the values of a[i + 1] and a[4] together
        add $t4, $t1, $t3           # $t4 = a[i + 1] + a[4]

        #Step 1: Find the address of b[i - 2]
        addi $t5, $s2, -2           # $t5 = i - 2
        sll $t5,$t5, 2              # $t5 = (i - 2) * 4
        add $t5, $t5, $s1           # $t5 = address of b[i-2]

        #Step 4: Store the result in b[i-2]
        sw $t4, 0($t5)              # b[i-2] = $t4
    ```

    3. Convert the C statement into a set of commented MIPS assembly code.
    ```
     x = ((b << 3) - 3) < a ? 1 : 0;
    ```

    Assume `$s0` is `b`
            `$s1` is `a`
            `$v0` is `x`

    ```
    # PUT ASSEMBLY INSTRUCTIONS HERE.
    # MIPS Registers: $s0 = b, $s1 = a, $v0 = x. 
            
    # Left shift on b by 3 bits
    sll $t0, $s0, 3      # $t0 = b << 3 .... which gives us (2^3 = 8) so b * 8
        
    # Subtracting an immediate from a register 
    addi $t0, $t0, - 3   # $t0 = (b << 3) - 3
        
    # Set less than ... 1 = true & 0 = flase
    slt $v0, $t0, $s1    # x = ((b << 3) - 3) < a ? 1 : 0
    ```

## High-Level Code and MIPS Assembly. (20 Points)
Important Notes: When performing addition or subtraction in MIPS, the language takes care of storing the new value. 
However, when it comes to multipication or division, it's handled differently since it could exceed the 32 bits. 
multipication: LO stores the lower 32 bits && HI stores the upper 32 bits of the 62 bits.
Division: LO stores the quotient && HI stores the remainder. 

1. Convert the following MIPS assembly into C code and describe what it does.
    
    ```
    addi $t0, 0, 10         # $t0 = 0 + 10 = 10
    addi $t1, 0, 2          # $t1 = 0 + 2 = 2

    loop:
        beq $t0, $zero, done    # Exit loop when $t0 == 0 else enter loop ...
        div $t2, $t0, $t1       # $t2 = 10 / 2 ... (LO=$t0 / $t1=5) && (HI=$t0 % $t1=0)
        mflo $t3                # $t3 = 5 .... stores the quotient in the register aka LO = 5
        add $t1, $t1, $t3       # $t1 = $t1 + 5 = 5
        addi $t0, $t0, -1       # $t0 = $t0 - 1
        j loop                  # calls for repeating the loop hence --> jump to loop

    done:
        addi $v0, $t1, 0        # $v0 = $t1 + 0
    ```

    C Code Equivalency (option 1):
    
        #include <stdio.h>
        int main () {
                
        int t0 = 10;
        int t1 = 2;
        int v0;

        while (t0 != 0) {

            // storing division in t2
            int t2 = t0 / t1; 
            // storing quotient from t2 --> t3 (mimicking MIPS div + mflo)
            int t3 = t2;

            // updating t1 & t0 values 
            t1 = t1 + t3;
            t0 = t0 - 1; 

            // Used to check what's going inside the loop
            printf("t1 = %d\n", t1);
            printf("Iteration: t0 = %d\n", t0);
            printf("\n");
                
            }

            // stores t1 value into v0 and diplayes final v0 value
            v0 = t1 + 0;
            printf("Final v0 value is ");
            printf("%d\n", v0);

            
            return 0;
        }

    C Code Equivalency (option 2):
    // OR ANOTHER ALTERNATIVE SAME PERFORMACE BELOW!! 
            
        #include <stdio.h>
        int main () {
            int t0 = 10;
            int t1 = 2;

            while (t0 != 0) {
                int t3 = t0 / t1;
                t1 = t1 + t3;
                t0 = t0 - 1;    
            }
                return t1; 
        }


2. Convert the following MIPS assembly into C code and describe what it does.

    ```
    li $t0, 0x12345678      # loads memory address into register $t0
    li $t1, 0x87654321      # loads memory address into register $t1
    xor $t2, $t0, $t1       # $t2 = $t0 ^ $t1   ---> The XOR unlike OR, only returns true (1) when a signular state is true not both. 
    addi $v0, $t2, 0        # $v0 = $t2 + 0 
    ```

    C Code Equivalency(option 2): 
        
        #include <stdio.h>
        int main () {
            unsigned int t0 = 0x12345678;               # Assigned memory addreess into t0
            unsigned int t1 = 0x87654321;               # Assighned memory address into t1
            unsigned int t2 = t0 ^ t1 // Bitwise XOR    # t2 = t0 XOR t1 
                
            return t2;                                  # sends the value stored in "t2" back to the place where the function was called. 
        }