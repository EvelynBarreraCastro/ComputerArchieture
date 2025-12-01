.globl match

# MIPS Assembly match function
#
# (inputs) $a0 is the size of the needle string
# (inputs) $a1 is a pointer to the needle string
# (inputs) $a2 is the size of the haystack string
# (inputs) a3 is a pointer to the haystack string
# (return value) $v0 is the index of the match, or -1 if no match

# match: #placeholder for code (lines 11 -13)
#   addi $v0, $zero, -2
#   jr $ra


# Note: Algorithm Plan (The core problem is a string search Algorithm)
# A nested loop would be a good approach. 

# Outline: 
# Outer loop that iterates through the said "haystack string", one char at a time. 
# Inner loop: Given the position in the outer loop, us the inner loop to compare the
# characters of the needle string to the characters in the haystack. 
# As a result: If the 2 characters match, the loop continues to move on to the next
# character to compare. If the 2 characters don't match we will break out from the 
# inner loop and return to the outer loop. 
# Success Condition: If the inner loop successfully compares every character, we've found a match. 
# Failure Condition: If the outer loop ends without finding a match -> needle does not exist in haystack. 

match: 
    beq $a0, $zero, return_zero
    blt $a2, $a0, return_neg1

    move $t0, $zero

outer_loop: 
    sub $t1, $a2, $a0
    bgt $t0, $t1, return_neg1

    move $t2, $zero

inner_loop: 
    beq $t2, $a0, found_match

    add $t3, $t0, $t2
    add $t3, $t3, $a3
    lbu $t4, 0($t3)

    add $t5, $a1, $t2
    lbu $t6, 0($t5)

    bne $t4, $t6, not_match

    addi $t2, $t2, 1
    j inner_loop

not_match: 
  addi $t0, $t0, 1
  j outer_loop

found_match: 
  move $v0, $t0 # return index of match
  jr $ra

return_neg1: 
  addi $t0, $zero, -1
  jr $ra

return_zero: 
  add $v0, $zero, $zero 
  jr $ra


