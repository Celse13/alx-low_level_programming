#include "main.h"

/**
* binary_to_uint - converts a binary string to an unsigned int
* @binary: string containing the binary number
*
* Return: the converted unsigned int, or 0 if invalid binary string
*/
unsigned int binary_to_uint(const char *binary)
{
int index;
unsigned int result = 0;

if (!binary)
return (0);

for (index = 0; binary[index]; index++)
{
if (binary[index] < '0' || binary[index] > '1')
return (0);
result = 2 * result + (binary[index] - '0');
}

return (result);
}

