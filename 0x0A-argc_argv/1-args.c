#include <stdio.h>
#include "main.h"

/**
* main - Print the name of the program
* @argc: Count of arguments
* @argv: Array of arguments
*
* Return: Always 0 (Success)
*/

int main(int argc, char *argv[])
{
(void) argv; // Ignore argv
printf("%d\n", argc - 1);
return 0;
}

