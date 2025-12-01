#include <stdio.h>
#include <string.h>
#include <libgen.h>

extern int match(const int needle_size, const char *needle, const int haystack_size, const char *haystack);
extern int palindrome(const int size, const char *string);

void test_palindrome(const char *string, int expected)
{
    printf("Checking to see if \"%s\" is a palindrome...\n", string);
    int result = palindrome(strlen(string), string);
    if (result == expected)
    {
        printf("PASS\n");
    }
    else
    {
        printf("FAIL\n");
    }
}

void test_match(const char *foo, const char *bar, int expected) {
    printf("Checking to see if \"%s\" is in \"%s\"...\n", foo, bar);
    int result = match(strlen(foo), foo, strlen(bar), bar);
    if (result == expected)
    {
        printf("PASS\n");
    }
    else
    {
        printf("FAIL\n");
    }
}

int main(int argc, char const *argv[])
{
    printf("Testing %s...\n", basename(__FILE__));
    /* Basic tests for match */
    const char *test_needle = "foo";
    const char *test_haystack = "foobar";
    test_match(test_needle, test_haystack, 0);
    /* if the needle is in the haystack return the offset into the haystack */
    const char *test_haystack2 = "barfoo";
    test_match(test_needle, test_haystack2, 3);
    /* if the needle is not in the haystack return -1 */
    const char *test_haystack3 = "barbaz";
    test_match(test_needle, test_haystack3, -1);
    /* if the needle is bigger than the haystack return -1 */
    const char *test_needle2 = "foobar";
    const char *test_haystack4 = "foo";
    test_match(test_needle2, test_haystack4, -1);
    /* if the needle is empty return 0 */
    const char *test_needle3 = "";
    const char *test_haystack5 = "foobar";
    test_match(test_needle3, test_haystack5, 0);
    /* if the haystack is empty return -1 */
    const char *test_needle4 = "foo";
    const char *test_haystack6 = "";
    test_match(test_needle4, test_haystack6, -1);
    /* if both are empty return 0 */
    const char *test_needle5 = "";
    const char *test_haystack7 = "";
    test_match(test_needle5, test_haystack7, 0);
    /* if both are the same return 0 */
    const char *test_needle6 = "foo";
    const char *test_haystack8 = "foo";
    test_match(test_needle6, test_haystack8, 0);
    /* if the needle appears multiple times, return the index of the first occurrence */
    const char *test_needle7 = "o";
    const char *test_haystack9 = "foo";
    test_match(test_needle7, test_haystack9, 1);

    /* If the string is empty return 1 */
    const char *test_palindrome_string = "";
    test_palindrome(test_palindrome_string, 1);
    /* If the string is one character return 1 */
    const char *test_palindrome_string2 = "a";
    test_palindrome(test_palindrome_string2, 1);
    /* If the string is two characters and the same return 1 */
    const char *test_palindrome_string3 = "aa";
    test_palindrome(test_palindrome_string3, 1);
    /* If the string is two characters and different return 0 */
    const char *test_palindrome_string4 = "ab";
    test_palindrome(test_palindrome_string4, 0);
    /* Basic palindrome test */
    const char *test_palindrome_string5 = "racecar";
    test_palindrome(test_palindrome_string5, 1);
    /* if the string is not a palindrome return 0 */
    const char *test_palindrome_string6 = "notapalindrome";
    test_palindrome(test_palindrome_string6, 0);
    /* Ignore white space */
    const char *test_palindrome_string7 = "taco cat";
    test_palindrome(test_palindrome_string7, 1);
    /* Ignore case */
    const char *test_palindrome_string8 = "Taco Cat";
    test_palindrome(test_palindrome_string8, 1);
    /* Ignore punctuation */
    const char *test_palindrome_string9 = "A man, a plan, a canal, Panama!";
    test_palindrome(test_palindrome_string9, 1);

    return 0;
}
