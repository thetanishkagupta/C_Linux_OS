int my_strspan(char *s1, char *s2)
{
    int count = 0;

    // Iterate over characters in s1
    while (*s1 != '\0') {
        char *temp_s2 = s2;

        // Check if the current character in s1 is present in s2
        while (*temp_s2 != '\0') {
            if (*s1 == *temp_s2) {
                count++;
                break;
            }
            temp_s2++;
        }

        // If the character in s1 is not present in s2, break the loop
        if (*temp_s2 == '\0') {
            break;
        }
        s1++;
    }
    return count;
}

