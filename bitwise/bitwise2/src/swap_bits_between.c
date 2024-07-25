int swap_bits_between(unsigned int *snum, unsigned int *dnum, unsigned int s, unsigned int d) {
    // Extract bits at positions s and d from both numbers
    unsigned int bit_s_snum = (*snum >> s) & 1;
    unsigned int bit_d_dnum = (*dnum >> d) & 1;

    // If bits are different, swap them
    if (bit_s_snum != bit_d_dnum) {
        // Create masks for bits at positions s and d
        unsigned int mask_s_snum = 1 << s;
        unsigned int mask_d_dnum = 1 << d;

        // Toggle bits at positions s in snum and d in dnum
        *snum ^= mask_s_snum;
        *dnum ^= mask_d_dnum;
    }
    return 0;
}

