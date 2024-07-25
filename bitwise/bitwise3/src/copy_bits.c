unsigned int copy_bits(unsigned int snum, unsigned int dnum, unsigned int n, unsigned int s, unsigned int d) {
    // Extract n bits (right adjusted) from position s in snum
    unsigned int mask = (1 << n) - 1; // Create a mask with n bits set to 1
    unsigned int bits_to_copy = (snum >> s) & mask;

    // Clear n bits at position d in dnum
    dnum &= ~(mask << d);

    // Copy bits_to_copy to position d in dnum
    dnum |= (bits_to_copy << d);

    return dnum;
}
