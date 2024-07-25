int my_strindex(char *src, char ch)
{
    int i = 0;
    while(*(src + i) != '\0')
    {
        if(*(src + i) == ch)
            return i;
        i++;    
    }
}
