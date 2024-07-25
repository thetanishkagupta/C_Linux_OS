void my_strappend(char *src, char *dest)
{
    int i = 0;
    while(*src != '\0')
    {
        src++;
    }
    while(*dest != '\0')
    {
        *src = *dest;
        src++;
        dest++;
    }
    *src = '\0';
}
