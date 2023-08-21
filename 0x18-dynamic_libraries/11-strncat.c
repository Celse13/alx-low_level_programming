#include "main.h"
/**
 *  * _strncat - concatenating string 2 strings
 *   * @dest: pointer to the _dest
 *    * @src: ponter to the _src
 *     * @n: bytyes to be used in _dest
 *      * Return: concantendated string
 *      **/
char *_strncat(char *dest, char *src, int n)
{
	int index_at_dest = 0;
	char *holder_to_dest = dest;
	int index_at_src = 0;
	int looping = 0;

	while (dest[index_at_dest] != '\0')
		index_at_dest++;

	while (looping < n && src[index_at_src] != '\0')
	{
		dest[index_at_dest] = src[index_at_src];
		index_at_dest++;
		index_at_src++;
		looping++;
	}

	dest[index_at_dest] = src[index_at_src];
	return (holder_to_dest);
}
