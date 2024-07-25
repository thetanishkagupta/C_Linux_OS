int my_strcomp(char *src, char *dest)
{
    while (*src != '\0' && *dest != '\0')
    {
        if (*src > *dest)
            return 1;

        else  if (*src < *dest)
            return -1;

        src++;
        dest++;
    }
    return 0;
}

