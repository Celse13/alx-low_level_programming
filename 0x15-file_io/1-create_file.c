#include "main.h"

/**
* create_file - Creates a file with the given name and
* writes the specified text content to it.
* @filename: A pointer to the name of the file to create.
* @text_content: A pointer to the string to write to the file.
*
* Return: On success, returns 1. On failure, returns -1.
*/
int create_file(const char *filename, char *text_content)
{
int file_descriptor, length = 0;
if (filename == NULL)
return (-1);

if (text_content == NULL)
text_content = "";
while (text_content[length] != '\0')
{
length++;
}

file_descriptor = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
if (file_descriptor == -1)
return (-1);
write(file_descriptor, text_content, length);

close(file_descriptor);

return (1);
}

