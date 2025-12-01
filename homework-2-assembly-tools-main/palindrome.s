.globl palindrome        # Declares palindrome as a global symbol so that the main.c file can call it.
                         # Following line of code is required so that the linker can work. 


# MIPS Assembly  Language
#
# palindrome: a word that reads the same way forward and backwards 
# ex: abba is a palindrome but harness is not. 
#
# This file contains the palindrome function written in MIPS assembly language.
# $a0 = the length of the string
# $a1 = the address of the string
# $v0 = the return value --> [1 if the string is palindrome (exact match) or 0 if not]

# "palindrome" is the label for the function entry point.
# When main.c calls palindrome the execution begins from this point on.




palindrome:                           # If length < 2 (0 or 1), it's palindrome --> return 1. 
    slti $t9, $a0, 2                  # Set less than immediate, sets $t9 to 1 if $a0 is less than 2.
    bne $t9, $zero, pal_true          # If $t9 is 1, we branch to pal_true because an empty or single character is a palindrome. 

                                      # Initialize pointers: 
    move $t1, $zero                   # left = 0    --> [use $t1 for left index]
    addi $t2, $a0, -1                 # right = length -1  --> [use $t2 for right index]


                                      # The main 2 pointer loop, in where we will be comparing characters left & right and move inward.
loop_compare: 
                                      # if left >= right we've checked everything making it a palindrome. 
   slt $t3, $t1, $t2                  # will set $t3 to equal 1 if "left < right" is true
   beq $t3, $zero, pal_true           # if false, we'll compare all pairs until it returns true.

                                      # load character at left:  char_left = *(base + left)
   add $t4, $a1, $t1                  # computes the address of the left character --> address = base + left
   lbu $t5, 0($t4)                    # loads the byte address unsigned --> $t5 = unsigned byte at left 

                                      # load character at right:  char_right = *(base + right)
   add $t6, $a1, $t2                  # address = base + right 
   lbu $t7, 0($t6)                    # $t7 = unsigned byte at right 

   # compare characters 
   bne $t5, $t7, pal_false            # jumps to pal_false if characters are different --> return 0

   # advance inward 
   addi $t1, $t1, 1                   # left++ (increments lefit)
   addi $t2, $t2, -1                  # right-- (decrements right)
   j loop_compare                     # repeats the loop

   pal_true: 
      addi $v0, $zero, 1              # return 1 --> means it is palindrome
      jr $ra                          # jump register & return argument. --> [exits function & returns argument]

    pal_false: 
      move $v0, $zero                 # return 0 --> not a palindrome 
      jr $ra                          # jump register & return arguement --> [exits function & returns argument]
      
