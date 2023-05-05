
/**
* print_binary - display binary representation of a num.
* @num: The number to be printed using binary representation
*/
void print_binary(unsigned long int num)
{
if (num > 1)
print_binary(num >> 1);
_putchar((num & 1) + '0');
}
