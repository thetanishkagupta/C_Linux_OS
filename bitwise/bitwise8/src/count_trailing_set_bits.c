unsigned int count_trailing_set_bits(unsigned int num) {
    unsigned int count = 0;
    while (num) {
        if (num & 1) // Check if rightmost bit is set
            count++;
        else
            break; // Break loop if rightmost bit is cleared
        num >>= 1; // Right shift to check next bit
    }
    return count;
}
