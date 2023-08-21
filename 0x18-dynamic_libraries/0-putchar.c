#include "main.h"
/**
 *  * _putchar - display char on the file descriptor
 *   * @c: character to be displayed
 *    * Return: 1 as number of character or -1 of failure
 *    **/
int _putchar(char c)
{
		return (write(1, &c, 1));
}
