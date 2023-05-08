#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
* create_buffer - Allocates 1024 bytes for a buffer.
* @filename: The name of the file buffer is storing chars for.
*
* Return: A pointer to the newly-allocated buffer.
*/
char *create_buffer(char *filename)
{
char *buffer;

buffer = malloc(sizeof(char) * 1024);

if (buffer == NULL)
{
dprintf(STDERR_FILENO,
"Error: Can't allocate memory for buffer in file %s\n", filename);
exit(99);
}

return (buffer);
}

/**
* close_file - Closes file descriptor.
* @fd: The file descriptor to be closed.
* @filename: The name of the file being operated on.
*
* Return: void
*/
void close_file(int fd, char *filename)
{
int c;

c = close(fd);

if (c == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close file descriptor for %s\n", filename);
exit(100);
}
}

/**
* main - Copies the contents of a file to another file.
* @argc: The number of arguments supplied to the program.
* @argv: An array of pointers to the arguments.
*
* Return: 0 on success.
*
* Description: If the argument count is incorrect - exit code 97.
*              If file_from does not exist or cannot be read - exit code 98.
*              If file_to cannot be created or written to - exit code 99.
*              If file_to or file_from cannot be closed - exit code 100.
*/
int main(int argc, char *argv[])
{
int from, to, r, w;
char *buffer;

if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}

buffer = create_buffer(argv[2]);

/* Open source file for reading */
from = open(argv[1], O_RDONLY);
if (from == -1)
{
dprintf(STDERR_FILENO,
"Error: Can't read from file %s\n", argv[1]);
free(buffer);
exit(98);
}

/* Read data from source file into buffer and write to destination file */
r = read(from, buffer, 1024);
to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
do {
if (r == -1)
{
dprintf(STDERR_FILENO,
"Error: Can't read from file %s\n", argv[1]);
free(buffer);
close_file(from, argv[1]);
close_file(to, argv[2]);
exit(98);
}

w = write(to, buffer, r);
if (w == -1)
{
dprintf(STDERR_FILENO,
"Error: Can't write to file %s\n", argv[2]);
free(buffer);
close_file(from, argv[1]);
close_file(to, argv[2]);
exit(99);
}

r = read(from, buffer, 1024);
to = open(argv[2], O_WRONLY | O_APPEND);

} while (r > 0);

free(buffer);
close_file(from, argv[1]);
close_file(to, argv[2]);

return (0);
}

