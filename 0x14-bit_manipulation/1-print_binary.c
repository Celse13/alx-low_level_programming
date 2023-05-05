#include "main.h"

/**
* print_binary - Prints the binary representation of a num
* @num: The number to be printed
*
* Return: nothing
*/
void print_binary(unsigned long int num);
{
if (num == 0)
{
_putchar('0');
return;
}
unsigned int mask = 1;
unsigned int bit_count = sizeof(unsigned long int) * 8;

while (bit_count--)
{
unsigned int msb = n >> bit_count;

if (msb & mask)
_putchar('1');
else
_putchar('0');
}
}


