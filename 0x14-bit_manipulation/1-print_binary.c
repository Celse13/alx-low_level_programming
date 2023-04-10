#include "main.h"

/**
* print_binary - prints the binary representation of a number
* @num: the number to print in binary
*/
void print_binary(unsigned long int num)
{
int i, num_digits = 0;
unsigned long int mask;
/* Find the number of binary digits in num */
for (i = 63; i >= 0; i--)
{
mask = num >> i;
if (mask & 1)
{
num_digits++;
}
}
/* Print the binary digits from left to right */
for (i = 63; i >= 0; i--)
{
mask = num >> i;
if (mask & 1)
{
_putchar('1');
}
else
{
if (num_digits > 1)
{
_putchar('0');
}
}
if (mask & 1)
{
num_digits--;
}
}
if (num == 0)
{
_putchar('0');
}
}

