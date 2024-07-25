unsigned int left_rotate_bits(unsigned int num, unsigned int n) {
    return (num << n) | (num >> (sizeof(num) * 8 - n));
}
