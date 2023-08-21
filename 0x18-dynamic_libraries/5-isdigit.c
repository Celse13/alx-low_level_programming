#include "main.h"
/**
 *  * _isdigit - checker for a digit
 *   * @c: a data to be checked
 *    * Return: 1 if digit or 0 if not
 *    **/

int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
