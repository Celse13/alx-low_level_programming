#include "main.h"
/**
 *  * _islower - checker for a lower letter
 *   * @c: character to be checked;
 *    * Return: 1 on success or 0 on failure
 *    **/
int _islower(int c)
{
	int checker = 0;
	char character = 'a';

	while (!checker && character <= 'z')
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
