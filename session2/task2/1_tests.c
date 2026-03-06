/**
 * @file 1_tests.c
 * @brief Unit testing with Acutest - test the is_palindrome() function
 *
 * COMP1850 Week 6 Session 2 - Task 2
 *
 * Write test functions using Acutest to verify is_palindrome() works correctly.
 * An example test is provided - add more tests covering different cases.
 */

#include "acutest.h"
#include <string.h>

/* Function prototype */
int is_palindrome(const char *str);

/* ============================================================
 * EXAMPLE TEST - Students should follow this pattern
 * ============================================================ */

void test_obvious_palindrome(void) {
    TEST_CHECK(is_palindrome("racecar") == 1);
    TEST_MSG("Expected 'racecar' to be a palindrome");
}

/* ============================================================
 * Consider testing:
 * - Single characters: "a"
 * - Empty string: ""
 * - Non-palindromes: "hello", "world"
 * - Even-length palindromes: "abba", "deed"
 * - Edge cases: case sensitivity, spaces
 *
 * Each test function should:
 * 1. Call TEST_CHECK(condition) to verify a condition
 * 2. Use TEST_MSG("message") to explain what went wrong if it fails
 * ============================================================ */
void test_single_char(void) {
    TEST_CHECK(is_palindrome("a") == 1);
    TEST_CHECK(is_palindrome("d") == 1);
    TEST_CHECK(is_palindrome("z") == 1);
    TEST_MSG("Expected single characters to be paildromes");
}

void test_empty_string(void) {
    TEST_CHECK(is_palindrome("") == 1);
    TEST_MSG("Expected empty string to be a palindrome");
}

void test_non_palindromes(void) {
    TEST_CHECK(is_palindrome("hello") == 0);
    TEST_MSG("Expected hello to not be a palindrome");

    TEST_CHECK(is_palindrome("world") == 0);
    TEST_MSG("Expected world to not be a palindrome");
}

void test_even_length_palindromes(void) {
    TEST_CHECK(is_palindrome("abba") == 1);
    TEST_MSG("Expected abba to be a palindrome");

    TEST_CHECK(is_palindrome("deed") == 1);
    TEST_MSG("Expected deed to be a palindrome");
}

void test_edge_cases(void) {
    TEST_CHECK(is_palindrome("Racecar") == 1);
    TEST_MSG("Expected Racecar to be a palidrome/expected no case sensitivity");

    TEST_CHECK(is_palindrome("race car") == 0);
    TEST_MSG("Expected 'race car' to not be a palindrome/expected spaces to break palidromes");
}


/* ============================================================
 * TEST_LIST - Register all your tests here
 *
 * Format: { "test name shown in output", function_name },
 * Must end with { NULL, NULL }
 * ============================================================ */
TEST_LIST = {
    { "obvious palindrome (racecar)", test_obvious_palindrome },
    { "single character", test_single_char },
    { "empty string", test_empty_string },
    { "non-palidnrome", test_non_palindromes},
    { "even length palindromes", test_even_length_palindromes},
    { "edge cases", test_edge_cases},
    { NULL, NULL }
};

/* ============================================================
 * IMPLEMENTATION - Do not modify
 * ============================================================ */

/**
 * @brief Checks if a given string is a palindrome.
 *
 * @param str The string to be checked.
 * @return int 1 if the string is a palindrome, 0 otherwise.
 */
int is_palindrome(const char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}
