unsigned int toggle_even_bits(unsigned int num) {
    unsigned int mask = 0x55; // even bit positions will be 1 i.e. 0101
    return num ^ mask;
}
