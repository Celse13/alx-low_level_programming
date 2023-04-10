#include "main.h"
#include <stdlib.h>
/**
 * main - check the code
 *Return: Always 0.
 */
ssize_t read_textfile(const char *filename, size_t max_bytes)
{
char *buf;
ssize_t fd, n_read, n_written, total_written;

if (!filename)
return (0);

fd = open(filename, O_RDONLY);
if (fd == -1)
return (0);

buf = malloc(sizeof(char) * max_bytes);
if (!buf)
{
close(fd);
return (0);
}

total_written = 0;
while ((n_read = read(fd, buf, max_bytes)) > 0)
{
n_written = write(STDOUT_FILENO, buf, n_read);
if (n_written != n_read)
{
	free(buf);
	close(fd);
	return (0);
}
total_written += n_written;
}

free(buf);
close(fd);

if (n_read == -1 || total_written == 0)
return (0);

return (total_written);
}

