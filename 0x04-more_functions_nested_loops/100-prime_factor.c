#include <stdio.h>

int main(void)
{
long n = 612852475143;
long largest_factor = 0;
int i;

for (i = 2; i <= n; i++) {
while (n % i == 0) {
largest_factor = i;
n /= i;
}
}

printf("%ld\n", largest_factor);

return 0;
}

