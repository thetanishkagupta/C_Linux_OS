#include<stdio.h>

#define test_set_bit(num, p) ((num) |= (1 << (p)))

unsigned int swap_bits_within(unsigned int, unsigned int, unsigned int);
int swap_bits_between(unsigned int *, unsigned int *, unsigned int, unsigned int);
unsigned int copy_bits(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int toggle_even_bits(unsigned int);
unsigned int toggle_odd_bits(unsigned int);
int left_rotate_bits(unsigned int, unsigned int);
int right_rotate_bits(unsigned int, unsigned int);
unsigned int count_set_bits(unsigned int);
unsigned int count_clear_bits(unsigned int);

