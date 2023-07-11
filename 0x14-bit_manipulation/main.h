#ifndef MAIN_H
#define MAIN_H
unsigned int flip_bits(unsigned long int n1, unsigned long int n2);
int clear_bit(unsigned long int *num_ptr, unsigned int bit_index);
int set_bit(unsigned long int *num_ptr, unsigned int bit_index);
int get_bit(unsigned long int num, unsigned int idx);
unsigned int binary_to_uint(const char *binary);
int get_endianness(void);
void print_binary(unsigned long int num);
#endif
