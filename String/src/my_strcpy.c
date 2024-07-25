void copy(char *src, char *dst)
{
    while(*src != '\0')
    {
        *dst = *src;
        src++;
        dst++;
    }
    *dst = '\0';
}

