#include "main.h"
/**
 *  * _memset - pointer to the starting address of the memory
 *   * @s: pointer to the string
 *    * @b: value to fill the memory block
 *     * @n: number of bytes
 *      * Return: the original pointer
 *      **/
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int _num = 0;
	char *_new_memo = s;

	while (_num < n)
	{
		s[_num] = b;
		_num++;
	}
	return (_new_memo);
}
