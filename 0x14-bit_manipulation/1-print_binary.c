
/**
* print_binary - Prints the binary representation of a number.
* @num: The number to be printed.
*/
void print_binary(unsigned long int num)
{
unsigned long int bit = 1;

while (bit < num)
bit <<= 1;

while (bit > 0)
{
if (num & bit)
_putchar('1');
else
_putchar('0');

bit >>= 1;
}
}

