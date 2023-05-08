#include "main.h"
/**
* open_files - Open source and destination files.
* @src_file: Pointer to the source file name.
* @dest_file: Pointer to the destination file name.
* Return: Returns the file descriptor of the source file.
*/
int open_files(const char *src_file, const char *dest_file)
{
int src_fd, dest_fd;
src_fd = open(src_file, O_RDONLY);
if (src_fd == -1)
{
dprintf(STDERR_FILENO, "Error: Unable to read from file %s\n", src_file);
exit(2);
}
dest_fd = open(dest_file, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR |
S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
if (dest_fd == -1)
{
dprintf(STDERR_FILENO, "Error: Unable to write to %s\n", dest_file);
close(src_fd);
exit(3);
}
return (src_fd);
}
/**
* copy_files - Copy content from source file to destination file.
* @src_fd: File descriptor of the source file.
* @dest_fd: File descriptor of the destination file.
*/
void copy_files(int src_fd, int dest_fd)
{
char buffer[BUFFER_SIZE];
int read_count, write_count;

while ((read_count = read(src_fd, buffer, BUFFER_SIZE)) > 0)
{
write_count = write(dest_fd, buffer, read_count);
if (write_count < read_count)
{
dprintf(STDERR_FILENO, "Error: Unable to write to dest_file\n");
exit(3);
}
}
if (read_count == -1)
{
dprintf(STDERR_FILENO, "Error: Unable to read from source file\n");
exit(2);
}
}
/**
* custom_copy - Customized version of the 'cp' command to copy file content.
* @arg_count: Number of arguments passed to the program.
* @arg_values: Array of string arguments.
*
* Return: 0 on success, otherwise exit with appropriate error codes.
*/
int custom_copy(int arg_count, char *arg_values[])
{
int src_fd, dest_fd;
if (arg_count != 3)
{
dprintf(STDERR_FILENO, "Invalid usage: custom_cp src_file dest_file\n");
exit(1);
}
src_fd = open_files(arg_values[1], arg_values[2]);
dest_fd = open(arg_values[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
if (dest_fd == -1)
{
dprintf(STDERR_FILENO, "Error: Unable to write to %s\n", arg_values[2]);
close(src_fd);
exit(3);
}
copy_files(src_fd, dest_fd);
if (close(src_fd) == -1)
{
dprintf(STDERR_FILENO, "Error: Unable to close source file descriptor\n");
exit(4);
}
if (close(dest_fd) == -1)
{
dprintf(STDERR_FILENO, "Error: Unable to close destination file descriptor\n");
exit(4);
}
return (0);
}

