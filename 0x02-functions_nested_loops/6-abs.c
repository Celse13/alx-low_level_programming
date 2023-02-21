
#include "main.h"

/**
* main - check the code
*
* Return: Always 0.
*/
int _abs(int a)
{
int k = a;
int absvalue;

if (k < 0)
{
k = k * (-1);
}
absvalue = k;
return (absvalue);
}

