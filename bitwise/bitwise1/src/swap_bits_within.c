unsigned int swap_bits_within(unsigned int num, unsigned int s, unsigned int d) {
    // Extract bits at positions s and d
    unsigned int bit_s = (num >> s) & 1;
    unsigned int bit_d = (num >> d) & 1;

    // If bits are different, swap them
    if (bit_s != bit_d) {
        // Create masks for bits at positions s and d
        unsigned int mask_s = 1 << s;
        unsigned int mask_d = 1 << d;

        // Toggle bits at positions s and d
        num ^= mask_s;
        num ^= mask_d;
    }
    return num;
}
