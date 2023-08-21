#include "main.h"
/**
 *  * _memcpy - copyt the memory
 *   * @dest: destination for the new memory
 *    * @src: memory to be copied
 *    *@n: number of bytes for new memory
 *     * Return: new memory address
 *     **/

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int _num = 0;
	char *_new_string = dest;

	while (_num < n)
	{
		dest[_num] = src[_num];
		_num++;
	}

	return (_new_string);
}
