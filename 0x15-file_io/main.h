#ifndef MAIN_H
#define MAIN_H
#define BUFFER_SIZE 1024
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int append_text_to_file(const char *filename, char *text_content);
int create_file(const char *filename, char *text_content);
ssize_t read_textfile(const char *filename, size_t num_letters);
int open_files(const char *src_file, const char *dest_file);
void copy_files(int src_fd, int dest_fd);
int custom_copy(int arg_count, char *arg_values[]);
#endif

