# Homework 1 - Assembly Tools

There are two parts to this assignment. Follow the instructions
carefully and make sure the tests pass. A testing pipeline is
provided to ensure your code is correct.

## Match (40 Points)

Write a match function in the `match.s` file that takes four
arguments. The argument registers are documented in the `match.s`
header. Loop over the needle and try to find it in the haystack.
Return either the start index of the needle in the haystack or -1
if it's not found.

## Palindrome (40 Points)

Write a palindrome function in the `palindrome.s` file that takes
two arguments. The argument registers are documented in the
`palindrome.s` header. Loop over the string argument and detect if
the string is a palindrome. Return 0 if the string is not a
palindrome. Return 1 if the string is a palindrome. Ignore white
space, case and punctuation.

## Guidelines

Read every file in this repository. Many of the files will be used across all
three programming homeworks. So gaining an understanding of what each file does
will be important later.

- Don't touch the following files, as they are used to grade your assignment.
    - Testing will be done using `main.c` so do not modify the tests.
    - The build and testing pipeline is defined in `.gitlab-ci.yml` so do not
      modify the pipeline.
- Do the following early and often to complete your assignment successfully.
    - Put your assembly program in `match.s` and `palidrome.s` respectively.
    - Commit and push early and often.
    - Watch the pipeline so you know that you've done it right.
        - Green checkmarks are good.
        - Verify the job log says `PASS` for all tests.
    - Try to ask ChatGPT what's wrong with your program and see what it corrects.