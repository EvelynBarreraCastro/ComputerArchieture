.globl match    #Assembler directive used to make globally visible to other files
                #The linker uses this to find starting point of "match"# MIPS Assembly match function

                
# MIPS Assembly match function 
# (inputs) $a0 is the size of the needle string
# (inputs) $a1 is a pointer to the needle string
# (inputs) $a2 is the size of the haystack string
# (inputs) a3 is a pointer to the haystack string
# (return value) $v0 is the index of the match, or -1 if no match

# Note: Algorithm Plan (The core problem is a string search Algorithm)
# A nested loop would be a good approach. 

# Outline: 
# Outer loop: that iterates through the said "haystack string", one char at a time. 
# Inner loop: Given the position in the outer loop, us the inner loop to compare the
# characters of the needle string to the characters in the haystack. 
# As a result: If the 2 characters match, the loop continues to move on to the next
# character to compare. If the 2 characters don't match we will break out from the 
# inner loop and return to the outer loop. 
# Success Condition: If the inner loop successfully compares every character, we've found a match. 
# Failure Condition: If the outer loop ends without finding a match -> needle does not exist in haystack. 


# match function created. 
match: 
    beq $a0, $zero, return_zero      # branch to "return_zero" if $a0 == $zero ... else continue instructions 
    blt $a2, $a0, return_neg1        # branch to "return_neg1" if $a2 < $a0 ... else continue instructions

    move $t0, $zero                  # moves $zero value into $t0 giving us ---> $t0 = 0

#outer_loop function created. 
outer_loop: 
    sub $t1, $a2, $a0                # $t1 = $a2 - $a0
    bgt $t0, $t1, return_neg1        # branch to "return_neg1" if $t0 > $t1

    move $t2, $zero                  # $t2 = 0 (initialize character index) 

#inner_loop function created. 
inner_loop: 
    beq $t2, $a0, found_match        # branch to "found_match" if $t2 == $a0

    add $t3, $t0, $t2                # $t3 = $t0 + $t2
    add $t3, $t3, $a3                # $t3 = $t3 + $a3 
    lbu $t4, 0($t3)                  # Load byte unsigned --> calculates address of $t3 and moves it to $t4

    add $t5, $a1, $t2                # $t5 = $a1 + $t2
    lbu $t6, 0($t5)                  # $t6 = loads address of $t5 & stores it 

    bne $t4, $t6, not_match          # branch if not equal to "not_match" ---> if $t4 != $t6

    addi $t2, $t2, 1                 # $t2 = $t2 + 1
    j inner_loop                     # jump to inner_loop function (repeat) 

#not_match function created. 
not_match:                           
  addi $t0, $t0, 1                   # $t0 = $t0 + 1
  j outer_loop                       # jump to outer_loop function 

#found_match function created. 
found_match: 
  move $v0, $t0                     # $v0 = $t0  (return index of match position)  jr $ra                            
  jr $ra                            # exit function and return argument in $v0 

#return_neg1 function created. 
return_neg1: 
  li $v0, -1                       # $v0 = -1 (return value) 
  jr $ra                           # exit function & return argument of ($v0 = -1)

#return_zero function created. 
return_zero: 
  add $v0, $zero, $zero           # $v0 = 0 + 0 = 0 
  jr $ra                          # exit function & save return arguement of ($v0 = 0) 


