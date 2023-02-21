#include "main.h"

/**
* _abs - computes the absolute value of an integer
* @a: the integer to compute the absolute value of
*
* Return: the absolute value of a
*/
int _abs(int a)
{
int absvalue;

if (a < 0)
{
absvalue = -a;
}
else
{
absvalue = a;
}
return (absvalue);
}

