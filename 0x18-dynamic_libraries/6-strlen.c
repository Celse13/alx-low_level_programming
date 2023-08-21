#include "main.h"
/**
 *  * _strlen - calcualate the length of the string
 *   * @s: string to be used
 *    * Return: length of the string
 *    **/
int _strlen(char *s)
{
	int n = 0;
	int _str_length = 0;

	while (s[n] != '\0')
	{
		_str_length++;
		n++;
	}
	return (_str_length);
}
