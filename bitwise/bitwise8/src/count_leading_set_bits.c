unsigned int count_leading_set_bits(unsigned int num) {
    unsigned int count = 0;
    while (num) {
        if (num & 0x80000000) // Check if leftmost bit is set
            count++;
        else
            break; // Break loop if leftmost bit is cleared
        num <<= 1; // Left shift to check next bit
    }
    return count;
}
