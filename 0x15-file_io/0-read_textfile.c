#include "main.h"
#include <stdlib.h>

/**
*read_textfile - reads a text file
*and prints its contents to the standard output
*@filename: the name of the file to read
*@num_letters: the maximum number of letters to read and print
*Return: the actual number of bytes read and printed,
*or 0 if the function fails or the filename is NULL.
*/
ssize_t read_textfile(const char *filename, size_t num_letters)
{
char *buffer;
ssize_t file_descriptor;
ssize_t num_bytes_read;
ssize_t num_bytes_written;
file_descriptor = open(filename, O_RDONLY);
if (file_descriptor == -1)
return (0);
buffer = malloc(sizeof(char) * num_letters);
num_bytes_read = read(file_descriptor, buffer, num_letters);
num_bytes_written = write(STDOUT_FILENO, buffer, num_bytes_read);
free(buffer);
close(file_descriptor);
return (num_bytes_written);
}

