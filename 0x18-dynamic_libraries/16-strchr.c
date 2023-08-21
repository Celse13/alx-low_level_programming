#include "main.h"
/**
 *  * _strchr - finding of occurence in the string
 *   * @s: string to be used
 *    * @c: character to be found
 *     * Return: occurence of the first char or null if not
 *     **/
char *_strchr(char *s, char c)
{
	unsigned int i, checker = 0;
	char *_new_str;

	if (s == 0 && c == '\0')
	{
		_new_str = s;
		return (_new_str);
	}
	if (s == 0)
		return (0);

	for (i = 0; (s[i] != '\0'); i++)
		if (s[i] == c)
		{
			_new_str = &(s[i]);
			checker = 1;
			break;
		}
	if (checker)
		return (_new_str);
	if (c == '\0')
	{
		_new_str = &(s[i]);
		return (_new_str);
	}
	return (0);
}
