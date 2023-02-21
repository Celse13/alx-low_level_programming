#include "main.h"

/**
* print_last_digit - prints the last digit of an integer
* @a: the integer to compute the last digit of
*
* Return: the last digit of a
*/
int print_last_digit(int a)
{
int last_digit = a % 10;

if (last_digit < 0)
last_digit = -last_digit;

_putchar(last_digit + '0');
return last_digit;
}

