#include "main.h"
/**
 *  * _strspn - calculating the length of substring
 *   * @s: strin to be used
 *    * @accept: character to be searche
 *     * Return: the length of string
 *     **/
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i = 0, j, cont = 0;

	while (s[i] != '\0')
	{
		j = 0;
		while (accept[j] != '\0')
		{
			if (s[i] == accept[j])
			{
				cont++;
				break;
			}
			j++;
		}
		if (s[i] != accept[j])
			break;
		i++;
	}

	return (cont);
}
