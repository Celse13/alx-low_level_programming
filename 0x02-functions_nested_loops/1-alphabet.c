#include "main.h"
/**
 * print_alphabet - prints all alphabets in lowercase.
 * Return: On success 1.
 */
void print_alphabet(void)
{
char letter = 'a';
while (letter <= 'z')
{
_putchar(letter);
letter++;
}
_putchar('\n');
}
