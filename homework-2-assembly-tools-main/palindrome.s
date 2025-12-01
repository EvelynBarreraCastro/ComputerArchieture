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



# palindrome function created. 
palindrome:                           # If length < 2 (0 or 1), it's palindrome --> return 1. 
    slti $t9, $a0, 2                  # If $a0 < 2      --> $t9 = 1 (true) 
                                      # Else if $a0 > 2 --> $t9 = 0 (false)
    bne $t9, $zero, pal_true          # Branch to "pal_true" if $t9 != $zero (if $t9 = 1) 
                                      # because an empty or single character is a palindrome. 

                                      # Initialize pointers: 
    move $t1, $zero                   # (left)  $t1 = 0  ---> [use $t1 for left index]
    addi $t2, $a0, -1                 # (right) $t2 = -1  --> [use $t2 for last index of string]


# loop_compared function created. Main loop that checks if pointers have crossed. 
# GOAL: The main 2 pointer loop, in where we will be comparing characters left & right and move inward.
loop_compare: 
                                      # if left >= right we've checked everything making it a palindrome. 
   slt $t3, $t1, $t2                  # if $t1 < $t2 then $t3 = 1 (True) --> else $t3 = 0 (False)
   beq $t3, $zero, pal_true           # branch to "pal_true" if $t3 = 0, (left >= right), pointers crossed, palindrome confirmed
   
                                      # load character at left:  char_left = *(base + left)
   add $t4, $a1, $t1                  # $t4 = $a1 + $t1 ---> computes the address of the left character --> address = base + left
   lbu $t5, 0($t4)                    # loads the byte address unsigned --> $t4 into $t5 (left character)

                                      # load character at right:  char_right = *(base + right)
   add $t6, $a1, $t2                  # $t6 = $a1 + $t2 ---> computes the address of the right character ---> address = base + right 
   lbu $t7, 0($t6)                    # load byte at address $t6 into $t7 (right character)
   
   # compare characters 
   bne $t5, $t7, pal_false            # branch to "pal_false" if ($t5 != $t7) meaning that characters are different

   # advance inward 
   addi $t1, $t1, 1                   # $t1 = $t1 + 1 ---> left++  (increments left) (move left pointer right)
   addi $t2, $t2, -1                  # $t2 = $t2 + -1 --> right-- (decrements right) (move right pointer left)
   j loop_compare                     # repeats the loop_compare function 

# Return true (palindrome found)
pal_true: 
  addi $v0, $zero, 1              # $v0 = 1 (true) satisfies palindrome
  jr $ra                          # jump register & return argument --> [exits function & returns argument v0]

# Return false (not a palindrome) 
pal_false: 
  move $v0, $zero                 # $v0 = 0 (false) doesn't satisfy the palindrome rule
  jr $ra                          # jump register & return arguement --> [exits function & returns argument v0]
      
