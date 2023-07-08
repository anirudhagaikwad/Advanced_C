/*
C Program to demonstrate concept of Preprocessor directive.
*/

#include <stdio.h>

// define constants
#define PI 3.14

// undefine existing macro and define it as new one
#undef  FILE_SIZE
#define FILE_SIZE 42

// define variable if is not already defined

#if !defined (MESSAGE)
   #define MESSAGE "You wish!"
#endif

// define one line function
#define square(x) ((x) * (x))



int main(void) {
   printf("Here is the message: %s\n", MESSAGE);
   printf("Square of 10 is : %d\n", square(10));

   //predefined Macros
   printf("File :%s\n", __FILE__ ); //This contains the current filename as a string literal.
   printf("Date :%s\n", __DATE__ ); //The current date as a character literal in "MMM DD YYYY" format.
   printf("Time :%s\n", __TIME__ ); //The current time as a character literal in "HH:MM:SS" format.
   printf("Line :%d\n", __LINE__ ); //This contains the current line number as a decimal constant.
   printf("ANSI :%d\n", __STDC__ ); //Defined as 1 when the compiler complies with the ANSI standard.

   return 0;
}
