/*
C Program to concatenate two strings using  macros.

Input: Hello,World
Output: Concatenated string: HelloWorld

Input: Good,Job
Output: Concatenated string: GoodJob

Input: Week,end
Output: Concatenated string: Weekend

*/

#include <stdio.h>

#define STR(s) #s
#define CONCAT_STR(a, b) STR(a##b)

int main() {
    printf("Concatenated string: %s\n", CONCAT_STR(Hello, World));

    return 0;
}

/*
This program demonstrates string concatenation using the # operator.
The CONCAT_STR macro concatenates the strings "Hello" and "World" to form the string "HelloWorld".
*/
