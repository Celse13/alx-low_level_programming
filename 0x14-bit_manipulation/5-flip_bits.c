#include "main.h"

/**
* flip_bits - counts the number of bits to flip between two numbers
* @n1: the first number
* @n2: the second number
*
* Return: the number of bits that need to be flipped to get from n1 to n2
*/
unsigned int flip_bits(unsigned long int n1, unsigned long int n2)
{
int i, count = 0;
unsigned long int current_bit;
unsigned long int exclusive_or = n1 ^ n2;

for (i = 63; i >= 0; i--)
{
current_bit = exclusive_or >> i;
if (current_bit & 1)
    count++;
}

return (count);
}

