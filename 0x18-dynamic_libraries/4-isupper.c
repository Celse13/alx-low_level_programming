#include "main.h"
/**
 *  * _isupper - checker if the input is a upper letter
 *   * @c: character to be checked
 *    * Return: 1 if upperletter or 0 if not
 *    **/

int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}
