#include "main.h"
/**
 *  * _strcpy - copying the string
 *   * @dest: where the string should be stored
 *    * @src: where we should get the string
 *     * Return: pointer to the start of new created str
 *     **/
char *_strcpy(char *dest, char *src)
{
	char *_handler = dest;

	while (*src != '\0')
		*_handler++ = *src++;
	*_handler = '\0';
	return (dest);
}
