void my_strsqueeze(char *str)
{
    char *dst = str;
    while(*str != '\0'){
        if(*str != *(str + 1)){
            *dst = *str;
            dst++;
        }
        str++;
    }
    *dst = '\0';
}
