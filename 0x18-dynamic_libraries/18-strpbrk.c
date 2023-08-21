#include "main.h"
/**
 *  * _strpbrk - searching a string
 *   * @s: string in which were are going to search
 *    * @accept: string to be searched;
 *     * Return: pointer to the first occurrence of any char
 *     **/
char *_strpbrk(char *s, char *accept)
{

	char *ptr = NULL;
	int i = 0;
	int j = 0;
	int checker = 0;

	while (s[i] != '\0')
	{
		j = 0;
		while (accept[j] != '\0')
		{
			if (s[i] == accept[j])
			{
				ptr = &s[i];
				checker = 1;
				break;
			}
			j++;
		}
		if (checker)
			break;
		i++;
	}

	if (checker)
		return (ptr);
	else
		return (NULL);
}
