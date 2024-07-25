void my_tolower(char *str)
{
    while(*str != '\0')
    {
        if (*str >= 'A' && *str <= 'Z')
        {
            *str = *str + ('a' -'A');
        }
        str++;
    }
}

