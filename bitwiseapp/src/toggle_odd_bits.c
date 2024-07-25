unsigned int toggle_odd_bits(unsigned int num) {
    unsigned int mask = 0xAA; // odd bit positions will be 1 i.e. 1010
    return num ^ mask;
}

