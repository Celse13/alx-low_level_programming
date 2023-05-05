#include "main.h"

/**
* append_text_to_file - Appends text at the end of a file.
* @filename: A pointer to the name of the file.
* @text_content: The string to add to the end of the file.
*
* Return: If the function fails or filename is NULL - -1.
*         If the file does not exist or the user lacks write permissions - -1.
*         Otherwise - 1.
*/
int append_text_to_file(const char *filename, char *text_content)
{
int fd, bytes_written, len = 0;

if (filename == NULL)
return (-1);
if (text_content != NULL)
{
/* Find length of text content */
for (len = 0; text_content[len]; len++)
;
}
/* Open file for writing (in append mode) */
fd = open(filename, O_WRONLY | O_APPEND);
if (fd == -1)
return (-1);
/* Write text content to file */
bytes_written = write(fd, text_content, len);
if (bytes_written == -1)
{
/* Error occurred while writing to file */
close(fd);
return (-1);
}
/* Close file and return success */
close(fd);
return (1);
}
