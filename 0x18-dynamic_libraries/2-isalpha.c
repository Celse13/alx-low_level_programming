#include "main.h"
/**
 *  * _isalpha - checker for alaphabet
 *   * @c: character to be checked
 *    * Return: 1 if alaphabet or 0 or not
 *    **/
int _isalpha(int c)
{
	int checker = 0;
	char character = 'a';

	while (!checker && character <= 'z')
	{
		if (c == character)
			checker = 1;
		character++;
	}
	character = 'A';
	while (!checker && character <= 'Z')
	{
		if (c == character)
			checker = 1;
		character++;
	}

	if (checker)
		return (1);
	else
		return (0);
}
