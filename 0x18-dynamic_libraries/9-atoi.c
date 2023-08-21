#include "main.h"
/**
 *  * _atoi - extract integer from string
 *   * @s: string to be extracted
 *    * Return: extraceed value
 *    **/
int _atoi(char *s)
{
	int interate = 0;
	int _checker_for_nega = 1;
	int result = 0;

	if (s[0] == '-')
	{
		_checker_for_nega *= -1;
		interate++;
	}

	while (s[interate] != '\0')
	{
		result = result * 10 + s[interate] - '0';
		interate++;
	}

	result *= _checker_for_nega;
	return (result);
}
