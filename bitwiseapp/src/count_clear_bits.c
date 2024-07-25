unsigned int count_clear_bits(unsigned int num) {
    unsigned int count = 0;
    while (num) {
        count += !(num & 1);
        num >>= 1;
    }
    return count;
}
