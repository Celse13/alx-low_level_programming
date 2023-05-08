#include "main.h"

/**
* append_text_to_file - appends the  text content to a file.
* @filename: name of the file for the content to be appended
* @text_content: the string to be appended
* Return: On success, returns 1. On failure, returns -1
*/
int append_text_to_file(const char *filename, char *text_content)
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

file_descriptor = open(filename, O_WRONLY | O_APPEND);
if (file_descriptor == -1)
return (-1);
write(file_descriptor, text_content, length);

close(file_descriptor);

return (1);
}

