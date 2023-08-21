#include "main.h"
/**
 *  * _strstr - allocation of segment of a string
 *   * @haystack: string to be used
 *    * @needle: the substring to be used
 *     * Return: new string being pointed to
 *     **/
char *_strstr(char *haystack, char *needle)
{
	while (*haystack != '\0')
	{
		char *_h = haystack;
		char *_n = needle;

		while (*_n != '\0' && *_h == *_n)
		{
			_h++;
			_n++;
		}

		if (*_n == '\0')
		{
			return (haystack);
		}

		haystack++;
	}

	return (NULL);
}
