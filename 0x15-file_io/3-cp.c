#include "main.h"
#define BUFFER_SIZE 1024

/**
* custom_copy - Customized version of the 'cp' command to copy file content.
* @arg_count: Number of arguments passed to the program.
* @arg_values: Array of string arguments.
*
* Return: 0 on success, otherwise exit with appropriate error codes.
*/
int custom_copy(int arg_count, char *arg_values[])
{
int src_file, dest_file;
int read_count = BUFFER_SIZE, write_count = 0;
char buffer[BUFFER_SIZE];
if (arg_count != 3)
{
dprintf(STDERR_FILENO, "Invalid usage: custom_cp src_file dest\n");
exit(1);
}
src_file = open(arg_values[1], O_RDONLY);
if (src_file == -1)
{
dprintf(STDERR_FILENO, "Error: Unable to read from file %s\n", arg_values[1]);
exit(2);
}
dest_file = open(arg_values[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR |
S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
if (dest_file == -1)
{
dprintf(STDERR_FILENO, "Error: Unable to write to %s\n", arg_values[2]);
close(src_file);
exit(3);
}
while (read_count == BUFFER_SIZE)
{
read_count = read(src_file, buffer, BUFFER_SIZE);
if (read_count == -1)
{
dprintf(STDERR_FILENO, "Error: Unable to read from file %s\n", arg_values[1]);
exit(2);
}
write_count = write(dest_file, buffer, read_count);
if (write_count < read_count)
{
dprintf(STDERR_FILENO, "Error: Unable to write to %s\n", arg_values[2]);
exit(3);
}
}
if (close(src_file) == -1)
{
dprintf(STDERR_FILENO, "Error: Unable to close fd %d\n", src_file);
exit(4);
}
if (close(dest_file) == -1)
{
dprintf(STDERR_FILENO, "Error: Unable to close fd %d\n", dest_file);
exit(4);
}
return (0);
}

