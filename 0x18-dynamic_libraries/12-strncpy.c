#include "main.h"

/**
 *  * _strncpy - copy string
 *   * @dest: the pointer to the destinatioin
 *    * @src: the pointer to the src
 *     * @n: bytes of the of the destination
 *      * Return: new string
 *      **/
char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	while (i < n)
	{
		dest[i++] = '\0';
	}

	return (dest);
}
