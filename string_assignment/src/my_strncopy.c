void my_strncopy(char *dest, char *src, int num)
{
    while (*src != '\0' && num != 0)
    {
        *(dest++) = *(src++);
        num--;
    }
    while (num--)
    {
        *(dest++) = '\0';
    }
}


