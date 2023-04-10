#include "main.h"

/**
* get_bit - returns the value of a bit at a given index in a decimal number
* @num: the decimal number to search
* @idx: the index of the bit to get (0 is the rightmost bit)
*
* Return: the value of the bit (0 or 1) at the given index
*or -1 if index is out of range
*/
int get_bit(unsigned long int num, unsigned int idx)
{
int bit_val;

/* check if index is within range */
if (idx > 63)
return (-1);

/* shift the bit at the given index to the rightmost position */
bit_val = (num >> idx) & 1;

return (bit_val);
}

