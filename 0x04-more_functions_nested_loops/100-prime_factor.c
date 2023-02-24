#include <stdio.h>
#include <math.h>

/**
* main - finds and prints the largest prime factor of the number 612852475143
*        followed by a new line
* Return: Always 0 (Success)
*/
int main(void)
{
long int n;
long int max;
long int i;

n = 612852475143;
max = 2; // Start with max = 2 to avoid unnecessary conditional statement

// Divide n by 2 as many times as possible
while (n % 2 == 0)
{
n /= 2;
}

// Divide n by odd numbers up to its square root
for (i = 3; i <= sqrt(n); i += 2)
{
while (n % i == 0)
{
max = i;
n /= i;
}
}

// If n is still greater than 2, then it must be prime
if (n > 2)
{
max = n;
}

printf("%ld\n", max);

return (0);
}

