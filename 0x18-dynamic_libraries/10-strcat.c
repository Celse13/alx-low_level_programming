#include "main.h"
/**
 *  * _strcat - concantingating two strigns
 *   * @dest: pointer to the _destination
 *    * @src: pointer to the _src
 *     * Return: concatenated string
 *     **/
char *_strcat(char *dest, char *src)
{
	int index_at_dest = 0;
	char *result = dest;
	int index_at_src = 0;


	while (dest[index_at_dest] != '\0')
	{
		index_at_dest++;
	}

	while (src[index_at_src] != '\0')
	{
		dest[index_at_dest] = src[index_at_src];
		index_at_dest++;
		index_at_src++;
	}

	dest[index_at_dest] = src[index_at_src];
	return (result);
}
