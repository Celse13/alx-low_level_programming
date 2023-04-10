#include "main.h"

/**
* get_endianness - checks if a machine is little or big endian
*
* This function checks whether the machine it is run on is little or big endian.
*
* Return: 0 if the machine is big endian, 1 if it is little endian
*/
int get_endianness(void)
{
unsigned int test_val = 1;
char *test_ptr = (char *) &test_val;

return (*test_ptr);
}

